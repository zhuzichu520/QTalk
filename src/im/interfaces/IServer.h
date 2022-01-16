#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpServer>
#include "IConnection.h"

namespace IM {

    class IServer :public QTcpServer {
    Q_OBJECT
    protected:
        explicit IServer(QObject *parent);

        ~IServer();

    Q_SIGNALS:

        void gotConnection(IConnection *);

    public:
        virtual void start() = 0;
    };

}

#endif
