#include "ControlCenterPrivate.h"

#include "MessageServer.h"
#include "interfaces/IConnection.h"
#include "Controlcenter.h"
#include "UserSettings.h"
#include "CryptEngine.h"
#include "ClientManager.h"

namespace IM {

    ControlCenterPrivate::ControlCenterPrivate(ControlCenter *parent) : m_cc(parent) {}

    ControlCenterPrivate::~ControlCenterPrivate() {}

    void ControlCenterPrivate::init() {
        m_userSettings = new UserSettings();
        m_cryptEngine = new CryptEngine(m_cc);
        m_clientManager = new ClientManager(m_cc);
        m_messageServer = new MessageServer(m_cc);
        m_messageServer->start();
        QObject::connect(m_messageServer, &MessageServer::gotConnection, m_clientManager, &ClientManager::addConnection,
                         Qt::QueuedConnection);
    }

    void ControlCenterPrivate::shutdown() {
        if (m_messageServer) {
            m_messageServer->shutdown();
            m_messageServer->deleteLater();
        }
        if (m_clientManager) {
            m_clientManager->shutdown();
            m_clientManager->deleteLater();
        }
        if (m_cryptEngine)
            m_cryptEngine->deleteLater();
        if (m_userSettings)
            m_userSettings->deleteLater();
    }

}
