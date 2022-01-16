#include "ControlCenterPrivate.h"

#include "MessageServer.h"
#include "interfaces/IConnection.h"
#include "ControlCenter.h"

namespace IM {

    ControlCenterPrivate::ControlCenterPrivate(ControlCenter *parent) : m_cc(parent) {}

    ControlCenterPrivate::~ControlCenterPrivate() {}

    void ControlCenterPrivate::init() {
        m_messageServer = new MessageServer(m_cc);
        m_messageServer->start();
    }

    void ControlCenterPrivate::shutdown() {
        if (m_messageServer) {
            m_messageServer->shutdown();
            m_messageServer->deleteLater();
        }
    }

}
