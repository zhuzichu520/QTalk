#include <QGuiApplication>
#include <QtQuick/qquickwindow.h>
#include <QApplication>

#include "MainWindow.h"
#include "Controlcenter.h"
#include "ToolLog.h"

using namespace IM;

int main(int argc, char *argv[])
{
    ToolLog toolLog(argv);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    //    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);
    QGuiApplication::setApplicationName("QTalk");
    QGuiApplication::setOrganizationName("QTalk");
    QGuiApplication::setOrganizationDomain("https://github.com/zhuzichu520/QTalk");
    QGuiApplication::setApplicationVersion("1.0");
    QGuiApplication app(argc, argv);
    QObject::connect(&app,&QApplication::aboutToQuit,ControlCenter::instance(),&ControlCenter::shutdown);
    MainWindow window;
    window.show();
    QGuiApplication::exec();
    return 0;
}
