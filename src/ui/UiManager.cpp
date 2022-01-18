#include "UiManager.h"

#include "ControlCenter.h"
#include "interfaces/IClientManager.h"
#include "ToolLog.h"

namespace IM {

    UiManager::UiManager() : m_cc(ControlCenter::instance()) {
    }

    UiManager::~UiManager() {
    }

    void UiManager::quickConnect(const QString &url) {
        if (url.isEmpty() || url.isNull())
            return;
        LOGI(url);
        m_cc->clientManager()->connectManualy(url);
    }

    QObject *UiManager::uimanager_singleton(QQmlEngine *engine, QJSEngine *scriptEngine) {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        auto *manager = new UiManager();
        return manager;
    }

}
