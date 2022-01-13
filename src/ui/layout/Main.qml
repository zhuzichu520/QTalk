import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
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

}
