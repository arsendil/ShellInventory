import QtQuick 2.15

Rectangle {

    property alias text: text_.text
    property bool isHeader: false

    height: parent.height
    border.color: "black"

    Text {
        id: text_
        anchors.centerIn: parent
        font.bold: isHeader
    }
}
