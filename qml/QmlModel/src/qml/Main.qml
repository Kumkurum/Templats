import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    width: 600
    height: 900
    visible: true
    color:"grey"

    List{
        anchors.fill: parent
        anchors.margins: 20
    }
}