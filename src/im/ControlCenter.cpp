#include "Controlcenter.h"

#include "ControlCenterPrivate.h"
#include "MessageServer.h"
#include "UserSettings.h"
#include "ClientManager.h"
#include "CryptEngine.h"

#include <QObject>

namespace IM {

    ControlCenter *ControlCenter::m_instance = nullptr;

    ControlCenter::ControlCenter(QObject *parent) : IControlCenter(parent), m_ccp(new ControlCenterPrivate(this)) {}

    ControlCenter::~ControlCenter() {
        shutdown();
    }

    ControlCenter *ControlCenter::instance() {
        return m_instance;
    }

    void ControlCenter::init() {
        m_instance = new ControlCenter();
        m_instance->m_ccp->init();
    }

    void ControlCenter::quit() {
        m_instance->deleteLater();
        m_instance = nullptr;
    }

    void ControlCenter::shutdown() {
        m_instance->m_ccp->shutdown();
        delete m_ccp;
    }

    IServer *ControlCenter::messageServer() {
        return m_ccp->m_messageServer;
    }

    IUserSettings *ControlCenter::userSettings() {
        return m_ccp->m_userSettings;
    }

    IClientManager *ControlCenter::clientManager() {
        return m_ccp->m_clientManager;
    }

    ICryptEngine *ControlCenter::cryptEngine() {
        return m_ccp->m_cryptEngine;
    }

}
