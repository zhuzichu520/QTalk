#include "Client.h"

#include "interfaces/IClient.h"
#include "interfaces/IConnection.h"
#include "interfaces/ICryptEngine.h"
#include "interfaces/IUserSettings.h"
#include "Controlcenter.h"
#include "ClientInformation.h"
#include "Message.h"
#include "SecureTunnel.h"
#include "ToolLog.h"

#include <QObject>

namespace IM {

    Client::Client(QObject *parent) : IClient(parent), m_conn(nullptr), m_detailAccepted(false),
                                      m_detailSent(false), m_tunnel(new SecureTunnel(this)) {
        connect(m_tunnel, &SecureTunnel::secured, this, &Client::secured);
    }

    Client::~Client() {
        m_tunnel->deleteLater();
    }

    IConnection *Client::connection() {
        return m_conn;
    }

    ClientInformation Client::info() {
        return m_info;
    }

    void Client::sendMessage(QString msg) {
        Message m;
        m.setMethod(Message::MSG);
        m.setOption(Message::TEXT);
        m.setData("MSG", msg);
        send(m);
    }

    void Client::setConnection(IConnection *conn) {
        m_conn = conn;
        m_tunnel->setConnection(m_conn);
        connect(m_conn, &IConnection::dataAvailable, this, &Client::handleRead);
        connect(m_conn, &IConnection::disconnected, this, &Client::closeConnection);
        connect(m_conn, &IConnection::errorOccurred, this, &Client::closeConnection);
    }

    void Client::setInfo(ClientInformation info) {
        m_info = info;
    }

    void Client::start() {
        m_tunnel->create();
    }

    bool Client::hasAcceptedData() const {
        return m_detailAccepted;
    }

    void Client::handleRead() {
        if (!m_tunnel->secure())
            return;
        m_request = m_tunnel->readMessage();
        handleRequest();
    }

    void Client::closeConnection() {
         connectionClosed();
    }

    void Client::handleRequest() {
        if (m_request.method() == Message::CONNECT) {
            if (m_request.option() == Message::REQUEST) {
                if (!m_detailAccepted) {
                    LOGI("Accepting Detail");
                    QString ip = m_request.data("IP");
                    QString name = m_request.data("NAME");
                    if (ip.isEmpty() || name.isEmpty())
                        return;
                    m_info.setName(name.trimmed());
                    m_info.setIp(ip.trimmed());
                    LOGI(QString::fromStdString("Accepted request from %1").arg(name));
                    Q_EMIT infoRecieved(m_info);
                    m_detailAccepted = true;
                    if (!m_detailSent)
                        sendDetail();
                }
            }
        } else if (m_request.method() == Message::MSG) {
            if (!m_detailSent || !m_detailAccepted)
                return;

            if (m_request.option() == Message::TEXT) emit messageRecieved(m_info.id(), m_request.data("MSG"));
        }
        return;
    }

    void Client::send(Message m) {
        if (!m_tunnel->secure())
            return;

        if (m_conn) {
            m_tunnel->send(m.toJson());
            m_conn->flush();
            m_conn->waitForBytesWritten();
        } else
            LOGI("Connection not available on write");
    }

    void Client::sendDetail() {
        if (m_conn) {
            if (!m_detailSent) {
                m_detailSent = true;
                QString myIp = ControlCenter::instance()->userSettings()->ip();
                QString myName = ControlCenter::instance()->userSettings()->name();
                Message m;
                m.setMethod(Message::CONNECT);
                m.setOption(Message::REQUEST);
                m.setData("NAME", myName);
                m.setData("IP", myIp);
                send(m);
            }
        } else
            LOGI("Connection not available on greetings");
    }

    void Client::secured() {
        sendDetail();
    }

}
