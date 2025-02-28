import QtQuick 2.0
import QtQml.Models 2.11
import QtQuick.Controls 2.0
ListView {
    id: view
    anchors.fill: parent
    model: core.model
    ScrollBar.vertical: ScrollBar{}
    spacing: 20
    delegate: DragDelegate{
        onMoveTo:{
            core.model.moveTo(from, to)
        }
    }
}