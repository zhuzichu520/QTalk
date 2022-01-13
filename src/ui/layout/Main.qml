import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.0
import "../component"

CusWindow {
    id:root
    width: 800
    height: 600
    minimumWidth: 300
    minimumHeight: 300
    title: qsTr("talk")

    CusSliderBar{
        id:slider
    }

    Rectangle {
        id:content
        height: parent.height
        anchors.left: slider.right
        anchors.right: parent.right
        color: "#f9f9f9"
    }

    InnerShadow {
        anchors.fill: content
        cached: true
        horizontalOffset: 1
        verticalOffset: 0
        radius: 4
        samples: 32
        color: "#10000000"
        smooth: true
        source: content
    }

}
