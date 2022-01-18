import QtQuick 2.15
import QtQuick.Controls 2.15
import Qtalk.UI 1.0
import "../storage"

Item {
    anchors.fill: parent

    signal handleUrl

    FontLoader { id: awesome; source: "qrc:/font/fontawesome-webfont.ttf" }

    onHandleUrl: {
        let url = quickConnectUrl.text
        UiManager.quickConnect(url)
        quickConnectUrl.clear()
    }

    Item {
        id: quickConnectForm
        anchors.centerIn: parent
        height: 40
        width: quickConnectUrl.width + quickConnectBtn.width

        Row {
            anchors.fill: parent
            TextField {
                id: quickConnectUrl
                height: parent.height
                width: 300
                placeholderText: qsTr(" URL")
                color: Theme.colorFontPrimary
                onAccepted:{
                    handleUrl()
                }
                background: Rectangle {
                    implicitHeight: 40
                    implicitWidth: 200
                    color: parent.activeFocus ? Theme.colorBackground : Theme.colorBackground2
                    border.color: parent.activeFocus ? Theme.colorPrimary : "#888"
                    border.width: parent.activeFocus ? 2 : 0

                }
            }
            Button {
                id: quickConnectBtn
                text: "\uf0c1"
                font.family: awesome.name
                width: parent.height
                height: parent.height
                onClicked:{
                    handleUrl()
                }
            }
        }
    }
}
