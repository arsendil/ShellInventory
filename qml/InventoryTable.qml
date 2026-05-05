import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Universal

import ShellInventory

Rectangle {
    id: root
    readonly property int kROW_HEIGHT: 30

    InventoryManager {
        id: inventoryManager
    }

    ColumnLayout {
        anchors.fill: parent

        Text {
            text: "Shell Inventory"
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 25
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillWidth: true

            Button {
                text: "Add Shells"
                onClicked: {
                    var component = Qt.createComponent("pages/EditPage.qml")

                    if (component.status !== Component.Ready) {
                        console.log("ERROR:", component.errorString())
                        return;
                    }

                    var editWindow = component.createObject(parent, {
                        forAdd: true,
                        inventoryManager: inventoryManager
                    })

                    if (editWindow) {
                        editWindow.show()
                    }
                }
            }

            Button {
                text: "Remove Shells"
                onClicked: {
                    var component = Qt.createComponent("pages/EditPage.qml")

                    if (component.status !== Component.Ready) {
                        console.log("ERROR:", component.errorString())
                        return;
                    }

                    var editWindow = component.createObject(parent, {
                        forAdd: false,
                        inventoryManager: inventoryManager
                    })

                    if (editWindow) {
                        editWindow.show()
                    }
                }
            }

            Item {
                Layout.fillWidth: true
            }

            Text {
                text: "Sort by"
                verticalAlignment: Text.AlignVCenter
            }

            ComboBox {
                id: shellTypeDropdown
                model: ["Shell Type", "In Stock", "Used", "Total"]
                width: 150
                onCurrentIndexChanged: {
                    switch (currentIndex) {
                    case 0: // Shell Type
                        inventoryManager.inventorySortListModel.sortByRole(InventoryListModel.ShellTypeRole)
                        break
                    case 1: // In Stock
                        inventoryManager.inventorySortListModel.sortByRole(InventoryListModel.InStockRole)
                        break
                    case 2: // Used
                        inventoryManager.inventorySortListModel.sortByRole(InventoryListModel.UsedRole)
                        break
                    case 3: // Total
                        inventoryManager.inventorySortListModel.sortByRole(InventoryListModel.TotalRole)
                        break
                    }
                }
            }
        }

        ListView {
            id: inventoryTableView
            boundsBehavior: Flickable.StopAtBounds
            Layout.fillWidth: true
            height: (model.rowCount() + 1) * root.kROW_HEIGHT
            model: inventoryManager.inventorySortListModel
            header: Row {
                width: inventoryTableView.width
                height: root.kROW_HEIGHT

                Cell {
                    isHeader: true
                    width: parent.width / 3
                    text: "Shell Type"
                }
                Cell {
                    isHeader: true
                    width: parent.width * 2 / 9
                    text: "In Stock"
                }
                Cell {
                    isHeader: true
                    width: parent.width * 2 / 9
                    text: "Used"
                }
                Cell {
                    isHeader: true
                    width: parent.width * 2 / 9
                    text: "Total"
                }
            }

            delegate: Row {
                width: inventoryTableView.width
                height: root.kROW_HEIGHT

                Cell {
                    width: parent.width / 3
                    text: model.shellType
                }
                Cell {
                    width: parent.width * 2 / 9
                    text: model.inStock
                }
                Cell {
                    width: parent.width * 2 / 9
                    text: model.used
                }
                Cell {
                    width: parent.width * 2 / 9
                    text: model.inStock + model.used
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Button {
                text: "History"
                onClicked: {
                    var component = Qt.createComponent("pages/HistoryPage.qml")

                    if (component.status !== Component.Ready) {
                        console.log("ERROR:", component.errorString())
                        return;
                    }

                    var historyWindow = component.createObject(parent, {
                        inventoryManager: inventoryManager
                    })

                    if (historyWindow) {
                        historyWindow.show()
                    }
                }
            }

            Item {
                Layout.fillWidth: true
            }

            Button {
                text: "Exit"
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }
}
