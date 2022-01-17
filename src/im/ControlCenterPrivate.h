#ifndef CONTROLCENTERPRIVATE_H
#define CONTROLCENTERPRIVATE_H

namespace IM {

class MessageServer;
class ControlCenter;
class CryptEngine;
class UserSettings;
class ClientManager;

class ControlCenterPrivate {

public:
    explicit ControlCenterPrivate(ControlCenter *parent = nullptr);

    ~ControlCenterPrivate();

    void init();

    void shutdown();

    MessageServer* m_messageServer;
    UserSettings* m_userSettings;
    ClientManager* m_clientManager;
    CryptEngine* m_cryptEngine;

    ControlCenter *m_cc;
};

}


#endif
