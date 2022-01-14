﻿import QtQuick 2.15


MouseArea {

    property int border: 5
    property bool fixedSize: (window.minimumWidth === window.maximumWidth && window.minimumHeight === window.maximumHeight)

    anchors.fill: parent
    acceptedButtons: Qt.LeftButton //current use Qt.LeftButton
    hoverEnabled: true
    preventStealing: true
    propagateComposedEvents: true
    z: -65535

    onPressed: {
        //if window is fixedSize, ignore it
        if (fixedSize) {
            return;
        }

        var rc = Qt.rect(0, 0, 0, 0);
        let e = 0;

        //top-left
        rc = Qt.rect(0, 0, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.TopEdge | Qt.LeftEdge;
            window.startSystemResize(e);
            return;
        }

        //top
        rc = Qt.rect(border, 0, window.width-border*2, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.TopEdge;
            window.startSystemResize(e);
            return;
        }

        //top-right
        rc = Qt.rect(window.width-border, 0, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.TopEdge | Qt.RightEdge;
            window.startSystemResize(e);
            return;
        }

        //right
        rc = Qt.rect(window.width-border, border, border, window.height-border*2);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.RightEdge;
            window.startSystemResize(e);
            return;
        }

        //bottom-right
        rc = Qt.rect(window.width-border, window.height-border, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.BottomEdge | Qt.RightEdge;
            window.startSystemResize(e);
            return;
        }

        //bottom
        rc = Qt.rect(border, window.height-border, window.width-border*2, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.BottomEdge;
            window.startSystemResize(e);
            return;
        }

        //bottom_left
        rc = Qt.rect(0, window.height-border,border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.BottomEdge | Qt.LeftEdge;
            window.startSystemResize(e);
            return;
        }

        //left
        rc = Qt.rect(0, border,border, window.height-border*2);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            e = Qt.LeftEdge;
            window.startSystemResize(e);
            return;
        }
    }

    onPositionChanged: {
        //console.log("MouseArea.onPositionChanged=", mouse.x, mouse.y);

        //if window is fixedSize, ignore it
        if (fixedSize) {
            cursorShape = Qt.ArrowCursor;
            return;
        }

        var rc = Qt.rect(0, 0, 0, 0);

        //top-left
        rc = Qt.rect(0, 0, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeFDiagCursor;
            return;
        }

        //top
        rc = Qt.rect(border, 0, window.width-border*2, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeVerCursor;
            return;
        }

        //top-right
        rc = Qt.rect(window.width-border, 0, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeBDiagCursor;
            return;
        }

        //right
        rc = Qt.rect(window.width-border, border, border, window.height-border*2);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeHorCursor;
            return;
        }

        //bottom-right
        rc = Qt.rect(window.width-border, window.height-border, border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeFDiagCursor;
            return;
        }

        //bottom
        rc = Qt.rect(border, window.height-border, window.width-border*2, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeVerCursor;
            return;
        }

        //bottom_left
        rc = Qt.rect(0, window.height-border,border, border);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeBDiagCursor;
            return;
        }

        //left
        rc = Qt.rect(0, border,border, window.height-border*2);
        if (ptInRect(rc, mouse.x, mouse.y)) {
            cursorShape = Qt.SizeHorCursor;
            return;
        }

        //default
        cursorShape = Qt.ArrowCursor;
    }

    onExited: {
        cursorShape = Qt.ArrowCursor;
    }

    function ptInRect(rc, x, y)
    {
        if ((rc.x <= x && x <= (rc.x + rc.width)) &&
                (rc.y <= y && y <= (rc.y + rc.height))) {
            return true;
        }

        return false;
    }

}

