#ifndef CONTROLCENTERPRIVATE_H
#define CONTROLCENTERPRIVATE_H

namespace IM {

    class MessageServer;
    class ControlCenter;

    class ControlCenterPrivate {

    public:
        explicit ControlCenterPrivate(ControlCenter *parent = nullptr);

        ~ControlCenterPrivate();

        void init();

        void shutdown();

        MessageServer* m_messageServer;

        ControlCenter *m_cc;
    };

}


#endif
