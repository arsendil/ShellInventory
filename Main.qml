import QtQuick
import QtQuick.Controls.Universal

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Shell Inventory")

    InventoryTable {
        anchors {
            fill: parent
            margins: 20
        }
    }
}

