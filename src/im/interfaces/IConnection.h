#ifndef ICONNECTION_H
#define ICONNECTION_H

#include <QTcpSocket>

namespace IM {
    class IConnection : public QTcpSocket {
    Q_OBJECT
    protected:
        explicit IConnection();
        ~IConnection();
    public:
        virtual QByteArray data(quint32 size = 0) = 0;
        virtual QByteArray seek(quint32 size) = 0;
        virtual bool hasUnreadData() = 0;
        virtual quint32 availableSize() = 0;
    Q_SIGNALS:
        void dataAvailable();
        void errorOccurred();
        void hostNotFound();
    };
}
#endif
