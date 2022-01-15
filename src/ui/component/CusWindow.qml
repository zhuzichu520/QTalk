import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id:window

    property alias page: container.children
    property int borderOffset: 5
    property int containerMargins: window.visibility === Window.Windowed ? borderOffset : 0

    flags: Qt.Window | Qt.FramelessWindowHint
    visible: true
    color: "transparent"

    WindowResize{
        border: borderOffset
        enabled: window.visibility === Window.Windowed
    }

    function toggleMaximized() {
        if (window.visibility === Window.Maximized) {
            window.showNormal();
        } else {
            window.showMaximized();
        }
    }

    BorderImage {
        source: "qrc:/image/bg_shadow_border.png"
        anchors.fill: parent
        border{
            left: 20
            top: 20
            right: 20
            bottom: 20
        }
        smooth:true
    }


    Item {
        id:container
        anchors.fill: parent
        anchors.margins: containerMargins
        MouseArea{
            anchors.fill: parent
        }
    }

}
