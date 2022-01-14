﻿pragma Singleton
import QtQuick 2.15
import "../storage"

QtObject{

    property string colorPrimary: "#197DFF"

    property string colorBackground:AppStorage.isDark?"#000000":"#FFFFFF"
    property string colorBackground1:AppStorage.isDark?"#333333":"#F7F7F7"
    property string colorBackground2:AppStorage.isDark?"#444444":"#EFEFEF"

    property string colorItemBackground:AppStorage.isDark?"#000000":"#FFFFFF"
    property string colorDivider: AppStorage.isDark?"#666666":"#EEEEEE"
    property string colorFontPrimary:AppStorage.isDark?"#EEEEEE":"#333333"
    property string colorFontSecondary :AppStorage.isDark?"#666666":"#666666"
    property string colorFontTertiary: AppStorage.isDark?"#666666":"#999999"

}
