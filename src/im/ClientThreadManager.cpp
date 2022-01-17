#include "ClientThreadManager.h"


#include "Client.h"
#include "Connection.h"
#include "ClientInformation.h"

#include <QThread>
#include <QObject>
#include <QMap>
#include "ToolLog.h"

namespace IM
{

ClientThreadManager::ClientThreadManager(QObject* parent) : QObject(parent)
{
}

ClientThreadManager::~ClientThreadManager()
{
}

void ClientThreadManager::clientCreated(Client* client)
{
    addToPending(client);
    qint16 id = client->info().id();
    m_clientList.insert(id,client);
    connect(client,&Client::infoRecieved,this,&ClientThreadManager::addClient);
    connect(client,&Client::messageRecieved,this,&ClientThreadManager::messageRecieved);
    connect(client,&Client::connectionClosed,this,&ClientThreadManager::removeClient);
    LOGI(QString::fromStdString("Client Added with id %1").arg(id));
    LOGI(QString::fromStdString("Starting Client %1").arg(id));
    client->start();
    if(isPending(client) && client->hasAcceptedData())
        addClient(client->info());
}

void ClientThreadManager::addClient(ClientInformation ci)
{
    LOGI("addClient called");
    qint16 id = ci.id();
    Client* client = m_clientList.value(id);
    client->setInfo(ci);
    removeIfPending(m_clientList.value(id));
    emit clientAdded(ci);
}

void ClientThreadManager::messageRecieved(qint16 id, QString msg)
{
    emit messageAdded(id,msg);
}

void ClientThreadManager::removeAllClients()
{
    QList<Client*> clients = m_clientList.values();
    foreach(Client* c , clients){
        closeConnection(c);
        c->deleteLater();
    }
}

void ClientThreadManager::closeConnection(Client* client)
{
    IConnection* conn = client->connection();
    if(conn){
        if(conn->isValid())
            conn->close();
        conn->deleteLater();
    }
}

void ClientThreadManager::removeClient()
{
    if(!sender())
        return;
    Client* client = dynamic_cast<Client*>(sender());
    qint16 id = client->info().id();
    client->deleteLater();
    m_clientList.remove(id);
    emit clientRemoved(id);
}

void ClientThreadManager::sendToClient(qint16 id, QString msg)
{
    Client* client = m_clientList.value(id);
    if(!client)
    {
        LOGI(QString::fromStdString("sending message %1  to client %2").arg(msg).arg(id));
        return;
    }
    client->sendMessage(msg);
}

void ClientThreadManager::addToPending(Client* client)
{
    m_clientInQueue.append(client);
}

bool ClientThreadManager::isPending(Client *client)
{
    return m_clientInQueue.indexOf(client) != -1;
}

void ClientThreadManager::removeIfPending(Client* client)
{
    m_clientInQueue.removeOne(client);
}

}
