#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H

#include "interfaces/IControlCenter.h"

#include <QObject>

namespace IM {

    class IServer;

    class IClientManager;

    class ControlCenterPrivate;

    class ICryptEngine;

    class IUserSettings;

    class ControlCenter : public IControlCenter {
    Q_OBJECT
    public:
        explicit ControlCenter(QObject *parent = nullptr);

        ~ControlCenter() override;

        static ControlCenter *instance();

        static void init();

        static void quit();

        IServer *messageServer() override;

        ICryptEngine *cryptEngine() override;

        IClientManager *clientManager() override;

        IUserSettings *userSettings() override;

    public Q_SLOTS:

        void shutdown();

    protected:
        friend ControlCenterPrivate;
        ControlCenterPrivate *m_ccp;
        static ControlCenter *m_instance;
    };

}

#endif
