#include "ClientManager.h"


#include "interfaces/IClientManager.h"
#include "interfaces/IConnection.h"
#include "interfaces/IClient.h"
#include "Client.h"
#include "Connection.h"
#include "ClientInformation.h"
#include "ClientThreadManager.h"
#include "MessageInformation.h"
#include "ToolLog.h"

#include <QObject>
#include <QList>
#include <QThread>

namespace IM {

    ClientManager::ClientManager(QObject *parent)
            : IClientManager(parent), m_clientCount(0), m_messageCount(0),
              m_clientThread(new QThread(this)), m_clientThreadManager(new ClientThreadManager()) {
        LOGI("Started");
        connect(m_clientThreadManager, &ClientThreadManager::clientAdded, this, &ClientManager::clientAdded,
                Qt::QueuedConnection);
        connect(m_clientThreadManager, &ClientThreadManager::clientRemoved, this, &ClientManager::clientRemoved,
                Qt::QueuedConnection);
        connect(m_clientThreadManager, &ClientThreadManager::messageAdded, this, &ClientManager::addMessage,
                Qt::QueuedConnection);
        connect(this, &ClientManager::clientCreated, m_clientThreadManager, &ClientThreadManager::clientCreated,
                Qt::QueuedConnection);
        connect(this, &ClientManager::removeAllClients, m_clientThreadManager, &ClientThreadManager::removeAllClients,
                Qt::QueuedConnection);
        connect(this, &ClientManager::sendToClient, m_clientThreadManager, &ClientThreadManager::sendToClient,
                Qt::QueuedConnection);
        m_clientThreadManager->moveToThread(m_clientThread);
        m_clientThread->start();
    }

    ClientManager::~ClientManager() {
    }

    void ClientManager::shutdown() {
        emit removeAllClients();
        m_clientThread->quit();
        m_clientThread->wait();
        m_clientThread->deleteLater();
        LOGI("ClientManager-Stopped");
    }

    QList<ClientInformation> ClientManager::clients() {
        return m_clientsInfo.values();
    }

    ClientInformation ClientManager::clientInfo(qint16 id) {
        return m_clientsInfo.value(id);
    }

    QList<MessageInformation> ClientManager::messages() {
        return m_messages.values();
    }

    void ClientManager::clientRemoved(qint16 id) {
        m_clientsInfo.remove(id);
        emit userListUpdated();
    }

    void ClientManager::addConnection(IConnection *connection) {
        LOGI(QString::fromStdString("adding new Client with descriptor %1").arg(connection->socketDescriptor()));
        Client *client = createClient(connection);

        if (!client) {
            LOGI(QString::fromStdString("cannot add Client with socket descriptor %1").arg(
                    connection->socketDescriptor()));
            return;
        }
        connection->moveToThread(m_clientThread);
        client->moveToThread(m_clientThread);
        emit clientCreated(client);
    }

    void ClientManager::sendMessage(qint16 id, QString msg) {
        MessageInformation mi;
        mi.setSent(true);
        mi.setUser(m_clientsInfo.value(id).name());
        mi.setMsg(msg);
        m_messages.insert(m_messageCount++, mi);
        emit sendToClient(id, msg);
        emit messageAdded(mi);
    }

    void ClientManager::connectManualy(QString url) {
        IConnection *con = new Connection();
        m_pendingManualConnection.insert(con, url);
        connect(con, &IConnection::connected, this, &ClientManager::addManualConnection);
        connect(con, &IConnection::hostNotFound, this, &ClientManager::noManualConnection);
        con->connectToHost(url, 2424);
    }

    void ClientManager::addManualConnection() {
        if (!sender())
            return;
        IConnection *con = dynamic_cast<IConnection *>(sender());
        m_pendingManualConnection.remove(con);
        addConnection(con);
    }

    void ClientManager::noManualConnection() {
        if (!sender())
            return;
        IConnection *con = dynamic_cast<IConnection *>(sender());
        QString url = m_pendingManualConnection.value(con);
        m_pendingManualConnection.remove(con);
        if (url.isEmpty() || url.isNull())
            return;
        Q_EMIT manualConnectionFailed(url);
    }

    void ClientManager::clientAdded(ClientInformation ci) {
        m_clientsInfo.insert(ci.id(), ci);
        LOGI(QString::fromStdString("Added %1  in ClientManager").arg(ci.name()));
        Q_EMIT userListUpdated();
    }

    void ClientManager::addMessage(qint16 id, QString msg) {
        MessageInformation mi;
        mi.setSent(false);
        mi.setUser(m_clientsInfo.value(id).name());
        mi.setMsg(msg);
        m_messages.insert(m_messageCount++, mi);
        Q_EMIT messageAdded(mi);
    }

    Client *ClientManager::createClient(IConnection *conn) {
        if (!conn)
            return nullptr;

        auto *client = new Client();
        client->setConnection(conn);

        ClientInformation ci;
        ci.setId(m_clientCount++);
        client->setInfo(ci);
        return client;
    }

}
