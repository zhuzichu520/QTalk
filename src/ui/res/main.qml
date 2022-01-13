import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

ApplicationWindow {
    id:root
    minimumWidth: 800
    minimumHeight: 600
    x:(Screen.width-800)/2
    y:(Screen.height-600)/2
    flags: Qt.Window | Qt.FramelessWindowHint
    visible: true
    title: qsTr("Hello World")

    property string rootBgColor: "#f9f9f9"

    Item {
        anchors.fill: parent

        Rectangle{
            id: sb
            width: 70
            height: parent.height
            anchors.left: parent.left
            color: "#eeeeee"
        }

        Rectangle { id:window
            height: parent.height
            anchors.left: sb.right
            anchors.right: parent.right
            color: rootBgColor
            AppControls {
                id: appControls
                anchors.top:parent.top
                width: parent.width
                height: 40
                onClose: Qt.quit()
                onMaximized: root.showMaximized()
                onMinimized: root.showMinimized()
                onDrag: {
                    root.x += dragX
                    root.y += dragY
                }
            }
        }

        InnerShadow {
            anchors.fill: window
            cached: true
            horizontalOffset: 1
            verticalOffset: 0
            radius: 4
            samples: 32
            color: "#10000000"
            smooth: true
            source: window
        }

    }

}
