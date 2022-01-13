import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15


Rectangle {

    property string title

    clip: true
    height: 30

    function toggleMaximized() {
        if (window.visibility === Window.Maximized) {
            window.showNormal();
        } else {
            window.showMaximized();
        }
    }

    FontLoader {
        id: awesome
        source: "qrc:/font/fontawesome-webfont.ttf"
    }


    Rectangle {
        id:layout_top
        color: "#f9f9f9"
        anchors.fill: parent

        TapHandler {
            onTapped: if (tapCount === 2) toggleMaximized()
            gesturePolicy: TapHandler.DragThreshold
        }
        DragHandler {
            grabPermissions: TapHandler.CanTakeOverFromAnything
            onActiveChanged: if (active) { window.startSystemMove(); }
        }

        RowLayout {
            spacing: 5
            anchors.left: parent.left
            anchors.leftMargin: 8
            height: parent.height
            Image {
                id: logo
                sourceSize: Qt.size(15,15)
                source: "qrc:/image/ic_logo.png"
            }

            Text {
                text: title
                font.pixelSize: 12
            }

        }



        RowLayout {
            spacing: 0
            anchors.right: parent.right
            anchors.rightMargin: 5
            height: parent.height
            CusToolButton {
                icon: "\uf068"
                onClickEvent: window.showMinimized();
            }
            CusToolButton {
                icon: window.visibility === Window.Maximized ? "\uf066" : "\uf065"
                onClickEvent: window.toggleMaximized();
            }
            CusToolButton {
                icon: "\uf00d"
                onClickEvent: window.close();
            }
        }
    }

}
