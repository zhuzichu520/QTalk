#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/qquickwindow.h>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
//    QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QGuiApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
