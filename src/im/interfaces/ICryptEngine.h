#ifndef ICRYPTENGINE_H
#define ICRYPTENGINE_H


#include <QObject>

namespace IM
{

class ICryptEngine : public QObject
{
    Q_OBJECT

public:

    virtual QByteArray publicKey() = 0;

    virtual QByteArray privateKey() = 0;

    virtual QByteArray randomPassword() = 0;

    virtual bool encryptRSA(QByteArray& pubKey, QByteArray& input, QByteArray& output) = 0;

    virtual bool decryptRSA(QByteArray& input, QByteArray& output) = 0;

    virtual bool encryptAES(QByteArray pass, QByteArray& input, QByteArray& output) = 0;

    virtual bool decryptAES(QByteArray pass, QByteArray& input, QByteArray& output) = 0;

protected:

    explicit ICryptEngine(QObject* parent = nullptr);

    ~ICryptEngine();
};

}


#endif // ICRYPTENGINE_H
