#include "IServer.h"

namespace IM {

    IServer::IServer(QObject *parent) : QTcpServer(parent){}

    IServer::~IServer(){}

}