#include "MessageServer.h"

#include "ControlCenter.h"
#include "Connection.h"
#include "interfaces/IServer.h"
#include "ToolLog.h"

#include <QObject>
#include <QTcpServer>


namespace IM {

    MessageServer::MessageServer(QObject *parent) : IServer(parent) {}

    MessageServer::~MessageServer() {}

    void MessageServer::start() {
        if (listen(QHostAddress::Any, 2424))
            LOGI("started on 2424");
        else
            LOGI("could not start on 2424");
    }

    void MessageServer::shutdown() {
        LOGI("Stopped");
        close();
    }

    void MessageServer::incomingConnection(qintptr handle) {
        LOGI(QString::fromStdString("new connection %1").arg(handle));
        auto *conn = new Connection();
        conn->setSocketDescriptor(handle);
        Q_EMIT gotConnection(conn);
    }

}