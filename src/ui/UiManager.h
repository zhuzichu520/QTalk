#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

namespace IM {
    class ControlCenter;

    class UiManager : public QObject {

    Q_OBJECT

    public:
        UiManager();

        ~UiManager();

        Q_INVOKABLE void quickConnect(const QString &);

        static QObject *uimanager_singleton(QQmlEngine *engine, QJSEngine *scriptEngine);

    protected:
        ControlCenter *m_cc;
    };

}

#endif
