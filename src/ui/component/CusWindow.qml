import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id:window

    default property alias children: container.children
    property int borderOffset: 5
    property int toolBarHeight: 30
    property int toolBarleftMargin: 0
    property int containerMargins: window.visibility === Window.Windowed ? borderOffset : 0

    flags: Qt.Window | Qt.FramelessWindowHint
    visible: true
    color: "#00000000"

    DragHandler {
        id: resizeHandler
        grabPermissions: TapHandler.TakeOverForbidden
        target: null
        onActiveChanged:
            if (active) {
                const p = resizeHandler.centroid.scenePressPosition;
                let e = 0;
                if (p.x < borderOffset) { e |= Qt.LeftEdge }
                if (p.x > width-borderOffset) { e |= Qt.RightEdge }
                if (p.y < borderOffset) { e |= Qt.TopEdge }
                if (p.y > height-borderOffset) { e |= Qt.BottomEdge }
                window.startSystemResize(e);
            }
    }

    function toggleMaximized() {
        if (window.visibility === Window.Maximized) {
            window.showNormal();
        } else {
            window.showMaximized();
        }
    }

    MouseArea{
        acceptedButtons: Qt.NoButton
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: {
            if(mouseX<borderOffset && mouseY<borderOffset){
                return Qt.SizeFDiagCursor
            }
            if(mouseX>width-borderOffset && mouseY>height-borderOffset){
                return Qt.SizeFDiagCursor
            }
            if(mouseX>width-borderOffset && mouseY<borderOffset){
                return Qt.SizeBDiagCursor
            }
            if(mouseY>height-borderOffset && mouseX<borderOffset){
                return Qt.SizeBDiagCursor
            }
            if(mouseX>borderOffset && mouseX<width-2*borderOffset && mouseY<borderOffset){
                return Qt.SizeVerCursor
            }
            if(mouseX>borderOffset && mouseX<width-2*borderOffset && mouseY>height-2*borderOffset){
                return Qt.SizeVerCursor
            }
            if(mouseY>borderOffset && mouseY<height-2*borderOffset && mouseX<borderOffset){
                return Qt.SizeHorCursor
            }
            if(mouseY>borderOffset && mouseY<height-2*borderOffset && mouseX>width-2*borderOffset){
                return Qt.SizeHorCursor
            }
            return Qt.ArrowCursor
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


    Rectangle {
        id:container
        anchors.fill: parent
        anchors.margins: containerMargins
        MouseArea{
            anchors.fill: parent
        }
        color:"#F9F9F9"
    }

    CusToolBar {
        anchors{
            left: parent.left
            right: parent.right
            top:parent.top
            margins: containerMargins
        }
        height: toolBarHeight
        title: "局域网聊天"
    }


}
