#include "ControlCenter.h"

#include "ControlCenterPrivate.h"
#include "MessageServer.h"

#include <QObject>

namespace IM {

    ControlCenter *ControlCenter::m_instance = nullptr;

    ControlCenter::ControlCenter(QObject* parent) : IControlCenter(parent) , m_ccp(new ControlCenterPrivate(this)){}

    ControlCenter::~ControlCenter()
    = default;

    ControlCenter *ControlCenter::instance() {
        return m_instance;
    }

    void ControlCenter::init() {
        m_instance = new ControlCenter();
        m_instance->m_ccp->init();
    }

    void ControlCenter::quit()
    {
        m_instance->deleteLater();
        m_instance = nullptr;
    }

    IServer* ControlCenter::messageServer()
    {
        return m_ccp->m_messageServer;
    }


}
