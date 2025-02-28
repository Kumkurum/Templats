import QtQuick 2.12
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3


Item {
    id: rootItem
    width: parent ? parent.width : 0
    height: {
        return 200
        // if(dragRect.held)
        //     return 0
        // return  dropArea.containsDrag ? 400 + 20: 200
    }
    // Rectangle {
    //     anchors.top:  parent.top
    //     // anchors.bottom: dragRect.fromTop ? parent.bottom : undefined
    //     anchors.left: parent.left
    //     width: parent.width
    //     height: 200
    //     visible: dropArea.containsDrag
    //     color: "transparent"
    //     border.width: 5
    //     border.color: dropArea.containsDrag ? "blue" : "grey"
    //     radius: height / 4
    // }
    Rectangle {
        id: dragRect
        property bool held: false
        property int visualIndex: index
        property bool fromTop: false
        anchors.bottom : dragRect.held ? undefined : dragRect.fromTop ?  undefined : rootItem.bottom
        anchors.top : dragRect.held ? undefined : dragRect.fromTop ?  rootItem.top : undefined
        width: parent.width
        height: 200
        Label {
            anchors.centerIn: parent
            text: _index
            font.pixelSize: 20
        }
        color: "white"
        radius: height / 4
        Drag.source: dragRect
        Drag.active: dragArea.drag.active
        Drag.hotSpot.x: width
        Drag.hotSpot.y: height/2

        border.width: 5
        border.color: dropArea.containsDrag ? "blue" : "grey"
    }
    DropArea {
        id: dropArea
        anchors.fill: parent
        onEntered:{
            dragRect.fromTop = drag.source.visualIndex < index
            // console.log(drag.source.visualIndex < index ? "СВЕРХУ" : "СНИЗУ")
        }
        onDropped: {
            moveTo(drag.source.visualIndex, index)
            drag.source.held = false
        }
    }
    MouseArea {
        id: dragArea
        anchors.fill: parent
        hoverEnabled: true
        drag.axis: Drag.YAxis
        drag.target: dragRect.held ? dragRect : undefined
        drag.onActiveChanged: {
            dropArea.enabled = !dropArea.enabled
            dragRect.Drag.drop()
            if (dropArea.enabled) {
                dragRect.z = parent.z - 1
            } else {
                dragRect.z = parent.z + 1
            }
        }
        onPressAndHold: dragRect.held = true
        Timer{
            id: timer
            repeat: false
            interval: 200
            running: false
            onTriggered:{
                dragRect.held = false
            }
        }
        onReleased:{
            timer.start()
        }
    }
    signal moveTo(int from, int to)
}