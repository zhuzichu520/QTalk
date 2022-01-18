#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QQmlApplicationEngine>

namespace IM {

    class IControlCenter;

    class UiManager;

    class MainWindow {
    public:
        explicit MainWindow();

        ~MainWindow();

        void show();

    protected:
        QQmlApplicationEngine m_engine;
    };
}
#endif
