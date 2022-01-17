import QtQuick 2.15
import "../view"
import "../storage"

Rectangle {
    id:root

    property int curIndex: 0

    width: 70
    height: parent.height
    anchors.left: parent.left
    color: Theme.colorBackground

    FontLoader { id: linea_basic; source: "qrc:/font/linea-basic-10.ttf" }


    ListModel{
        id:sliderModel
        ListElement{
            icon:"."
        }
        ListElement{
            icon:"F"
        }
        ListElement{
            icon:"P"
        }
        ListElement{
            icon:"8"
        }
        ListElement{
            icon:"\ue007"
        }
    }

    Item{
        id:layout_logo
        width: 70
        height: 70
        anchors.top: parent.top

        Image{
            width: 30
            height: 30
            anchors.centerIn: parent
            source: "qrc:/image/ic_logo.png"
        }

    }


    ListView{
        model:sliderModel
        boundsBehavior: Flickable.StopAtBounds
        anchors{
            top:layout_logo.bottom
            left: parent.left
            right:parent.right
            bottom: parent.bottom
        }
        delegate: Item{
            width: 70
            height: 50
            Text{
                anchors.centerIn: parent
                text:model.icon
                font.family: linea_basic.name
                color:curIndex === model.index ? Theme.colorPrimary : Theme.colorFontPrimary
                font.pixelSize: 24
            }
            MouseArea{
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    curIndex = model.index
                }
            }
        }
    }

}
