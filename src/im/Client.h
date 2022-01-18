#ifndef CLIENT_H
#define CLIENT_H

#include "interfaces/IClient.h"
#include "ClientInformation.h"
#include "Message.h"

#include <QObject>
#include <QMap>

namespace IM {

    class IConnection;

    class SecureTunnel;

    class Client : public IClient {
    Q_OBJECT

    public:

        explicit Client(QObject *parent = nullptr);

        ~Client();

        IConnection *connection() override;

        ClientInformation info() override;

        void sendMessage(QString msg) override;

        void setConnection(IConnection *conn);

        void setInfo(ClientInformation info);

        void start();

        bool hasAcceptedData() const;

    public Q_SLOTS:

        void handleRead();

        void closeConnection();

    Q_SIGNALS:

        void infoRecieved(ClientInformation ci);

        void messageRecieved(qint16 id, QString msg);

        void connectionClosed();

    protected:

        void handleRequest();

        void send(Message m);

        void sendDetail();

        void secured();

        IConnection *m_conn;

        SecureTunnel *m_tunnel;

        ClientInformation m_info;

        Message m_request;

        bool m_detailAccepted;

        bool m_detailSent;
    };

}

#endif
