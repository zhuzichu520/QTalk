#include "MainWindow.h"

#include "UiManager.h"

namespace IM {

    MainWindow::MainWindow() {
        qmlRegisterSingletonType<UiManager>("Qtalk.UI", 1, 0, "UiManager", UiManager::uimanager_singleton);
    }

    MainWindow::~MainWindow() {
    }

    void MainWindow::show() {
        m_engine.load(QUrl("qrc:/layout/Main.qml"));
    }

}