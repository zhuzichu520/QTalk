#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/qquickwindow.h>
#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
//    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    //    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);
    QGuiApplication app(argc, argv);
    app.setApplicationName("QTalk");
    app.setOrganizationName("QTalk");
    app.setOrganizationDomain("https://github.com/zhuzichu520/QTalk");
    app.setApplicationVersion("1.0");

    MainWindow window;
    window.show();
    return app.exec();
}
