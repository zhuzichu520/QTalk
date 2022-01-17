import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

import QtQuick.Scene3D 2.15
import Qt3D.Core 2.15
import Qt3D.Render 2.15
import Qt3D.Input 2.12
import Qt3D.Extras 2.15
import QtQuick.Dialogs 1.2

import "../component"

CusWindow {
    id:root
    width: 800
    height: 600
    minimumWidth: 300
    minimumHeight: 300
    title: qsTr("talk")

    page: CusPage{

        CusToolBar {
            id:toolBar
        }

        CusSliderBar{
            id:slider


        }

        Item{
            id:content
            anchors{
                top:toolBar.bottom
                left: slider.right
                bottom: parent.bottom
                right:parent.right
            }
        }


        Text {
            id: name
            text: qsTr(" (⊙o⊙)…")
            font.pixelSize: 26
            anchors.centerIn: parent
        }

    }


    //    Welcome{
    //        anchors.fill: parent
    //        anchors.margins: containerMargins
    //        onUpdated: {
    //            console.debug("username:"+username)
    //            console.debug("ddir:"+ddir)
    //        }
    //    }

}
