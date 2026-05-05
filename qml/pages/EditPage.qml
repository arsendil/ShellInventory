import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Universal
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    id: root
    visible: false
    width: 300
    height: 200
    title: (root.forAdd ? "Add" : "Remove") + " Shells"

    required property bool forAdd
    required property var inventoryManager

    Column {
        spacing: 20
        anchors.centerIn: parent

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                text: "Shell Type:"
                font.bold: true
                width: 80
                horizontalAlignment: Text.AlignRight
            }
            ComboBox {
                id: shellTypeDropdown
                model: ["60mm", "82mm", "100mm", "122mm", "152mm"]
                width: 150
            }
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                text: "Quantity:"
                font.bold: true
                width: 80
                horizontalAlignment: Text.AlignRight
            }
            TextField {
                id: quantityField
                width: 150
                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 1 }
                text: "1"
            }
        }

        Row {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Confirm " + (root.forAdd ? "Add" : "Remove")
                background: Rectangle {
                    color: "lightgrey"
                    radius: 5
                }
                onClicked: {
                    var selectedShellType = shellTypeDropdown.currentText;
                    var quantity = quantityField.text;

                    if (forAdd) {
                        root.inventoryManager.addShells(selectedShellType, quantity)
                    } else {
                        var ok = root.inventoryManager.removeShells(selectedShellType, quantity)

                        if (!ok) {
                            warningDialog.open()
                            return;
                        }
                    }

                    quantityField.text = 1;
                    close();
                }
            }

            MessageDialog {
                id: warningDialog

                title: "Warning"
                text: "Something went wrong."
                informativeText: "Please check your input and try again."

                buttons: MessageDialog.Ok

                onAccepted: {
                    console.log("User clicked OK")
                }
            }

            Button {
                text: "Cancel"
                background: Rectangle {
                    color: "lightgrey"
                    radius: 5
                }
                onClicked: {
                    quantityField.text = 1;
                    close();
                }
            }
        }
    }
}
