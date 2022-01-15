import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import "../storage"

Page {

    id:root

    property alias username: userName.text
    property alias ddir: downloadDirVal.text

    signal updated()

    background: Rectangle{
        color: Theme.colorBackground
    }

    Component.onCompleted: {
        welcomeTimer.start()
    }

    FontLoader {
        id: awesome
        source: "qrc:/font/fontawesome-webfont.ttf"
    }

    Timer {
        id: welcomeTimer
        running: false
        interval: 1000
        repeat: false
        onTriggered: {
            welcomeText.opacity = 0
            settingForm.visible = true
        }
    }

    Text {
        id: welcomeText
        text: qsTr("欢迎使用QTalk")
        color: Theme.colorPrimary
        font.pixelSize: 30
        anchors.centerIn: parent
        Behavior on opacity { NumberAnimation { duration: 500 } }
    }

    Item{
        id:settingForm
        anchors.fill: parent
        visible: false
        Behavior on visible { NumberAnimation { duration: 600 } }

        Text {
            id: settingsTitle
            height: 40
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
            color: Theme.colorPrimary
            text: qsTr("配置设定")
        }


        SwipeView {
            id: inputs
            clip: true
            anchors.centerIn: parent
            width: 400
            height: 400
            interactive: false

            Item{

                Item{
                    anchors.centerIn: parent
                    width: 300
                    height: userName.height + userNameLabel.height

                    Column {
                        anchors.fill: parent

                        Text {
                            id: userNameLabel
                            text: qsTr("用户名")
                            font.pixelSize: 14
                            height: 30
                            color:Theme.colorFontPrimary
                            width: parent.width
                            Behavior on font.pixelSize { NumberAnimation { duration: 100 } }
                        }

                        TextField {
                            id: userName
                            font.pixelSize: 14
                            placeholderText: qsTr("例: 皮卡丘")
                            height: 40
                            width: parent.width
                            color: Theme.colorFontPrimary
                            onActiveFocusChanged: userNameLabel.font.pixelSize = 20
                            background: Rectangle {
                                implicitHeight: 40
                                implicitWidth: 200
                                color: parent.activeFocus ? Theme.colorBackground : Theme.colorBackground2
                                border.color: parent.activeFocus ? Theme.colorPrimary : "#888"
                                border.width: parent.activeFocus ? 2 : 0
                            }
                        }
                    }
                }
            }

            Item{
                Item { id: downloadDirForm
                    anchors.centerIn: parent
                    width: 300
                    height: downloadDirLabel.height + downloadDir.height

                    Column {
                        anchors.fill: parent

                        Text {
                            id: downloadDirLabel
                            text: qsTr("默认下载路径")
                            font.pixelSize: 14
                            height: 40
                            color:Theme.colorFontPrimary
                            width: parent.width
                            Behavior on font.pixelSize { NumberAnimation { duration: 100 } }
                        }

                        Item {
                            id: downloadDir
                            width: parent.width
                            height: 40

                            TextField {
                                id: downloadDirVal
                                anchors.left: parent.left
                                anchors.right: selectBtn.left
                                height: parent.height
                                placeholderText: qsTr("例: ~/Downloads")
                                text: dirDialog.folder
                                color: Theme.colorFontPrimary
                                background: Rectangle {
                                    implicitHeight: 40
                                    implicitWidth: 200
                                    color: parent.activeFocus ? Theme.colorBackground : Theme.colorBackground2
                                    border.color: parent.activeFocus ? Theme.colorPrimary : "#888"
                                    border.width: parent.activeFocus ? 2 : 0
                                }
                            }

                            Button { id: selectBtn
                                anchors.right: parent.right
                                text: qsTr("\uf07b")
                                height: parent.height
                                font.family: awesome.name
                                width: height
                                onClicked: {
                                    if(downloadDirLabel.font.pixelSize != 20)
                                        downloadDirLabel.font.pixelSize = 20
                                    dirDialog.open()
                                }
                            }
                        }
                    }
                    FileDialog { id: dirDialog
                        selectExisting: true
                        selectFolder: true
                    }
                }
            }

            Item{

                Item { id: colorThemeForm
                    anchors.centerIn: parent
                    width: 140
                    height: colorThemeLabel.height + colorView.height

                    Column {
                        anchors.fill: parent


                        Text { id: colorThemeLabel
                            text: qsTr("请选择主题颜色")
                            font.pixelSize: 14
                            color:Theme.colorFontPrimary
                            height: 40
                            width: parent.width
                            Behavior on font.pixelSize { NumberAnimation { duration: 100 } }
                        }

                        Rectangle { id: colorView
                            anchors.horizontalCenter: parent.horizontalCenter
                            color: Theme.colorPrimary
                            width: 100
                            height: 100

                            Text { id: colorText
                                anchors.centerIn: parent
                                text: Theme.colorPrimary
                            }

                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    colorThemeLabel.font.pixelSize = 20
                                    packerColor.show()
                                }
                            }
                        }
                    }
                }
            }

        }


        Item{
            id: btngrp1
            width: 400
            height: 50
            anchors.top: inputs.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            Button { id: prevBtn
                anchors.left: parent.left
                height: parent.height
                text: qsTr("上一步")
                background: Rectangle{
                    implicitWidth: 100
                    color: "#f0f0f0"
                }

                onClicked: {
                    if(inputs.currentIndex > 0)
                        inputs.setCurrentIndex(inputs.currentIndex - 1)
                }
            }

            Button { id: nextBtn
                property bool disable: (page == 0 && userName.text == "") ||
                                       (page == 1 && downloadDirVal.text == "") ||
                                       (page == 2 && colorText.text == "") ? true : false
                property alias page: inputs.currentIndex
                anchors.right: parent.right
                height: parent.height
                text: page == 2 ? qsTr("完成") : qsTr("下一步")

                background: Rectangle{
                    implicitWidth: 100
                    color: nextBtn.disable ? "#d0d0d0" : "#f0f0f0"
                }

                onClicked: {
                    if(!disable)
                    {
                        if(page < 2)
                            inputs.setCurrentIndex(page + 1)
                        else if(page == 2)
                        {
                            root.updated()
                            root.visible = false
                        }
                    }
                }
            }
        }
    }

    PackerColor{
        id:packerColor
        onChooseColor:
            (color) => {
                Theme.colorPrimary = color
            }
    }

}
