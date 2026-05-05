import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Universal
import QtQuick.Layouts

ApplicationWindow {
    id: root
    width: 640
    height: 480

    visible: true
    title: "History"

    required property var inventoryManager

    ColumnLayout {
        spacing: 20
        anchors {
            fill: parent
            margins: 20
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.minimumWidth: parent.width

            Text {
                text: "History"
                font.pointSize: 20
                font.bold: true
            }

            ComboBox {
                id: shellTypeDropdown
                Layout.alignment: Qt.AlignRight
                model: ["All", "60mm", "82mm", "100mm", "122mm", "152mm"]
                width: 150
                onCurrentTextChanged: {
                    root.inventoryManager.historyFilterModel.filterHistoryByShellType(currentText)
                }
            }
        }

        ListView {
            id: historyListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 5
            clip: true

            model: root.inventoryManager.historyFilterModel

            delegate: Rectangle {
                width: historyListView.width
                height: 60
                radius: 8
                color: "#cccccc"
                border.color: "black"

                Row {
                    anchors.centerIn: parent
                    spacing: 20

                    Text { text: model.action }
                    Text { text: model.type }
                    Text { text: model.amount }
                    Text { text: model.time }
                }
            }
        }

        Button {
            text: "Close"
            Layout.alignment: Qt.AlignRight
            onClicked: root.close()
        }
    }
}

