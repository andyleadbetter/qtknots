import Qt 4.7
import "../common" as Common
import Knots 1.0

Item {

    anchors.fill: parent

    MouseArea {
        anchors.fill:  parent
        onPressed: screen.state = "Browsing"
    }

    Rectangle {

        Behavior on opacity {  PropertyAnimation { property: "opacity"; duration: 200; } }

        id: container
        width: 500
        height: 127
        color: "#2f2828"
        radius: 14
        border.width: 2
        border.color: "#959090"

        anchors.centerIn: parent

        Knots { id: knots }

        function accept(tags) {
            console.log( "Searching for " + tags );
            screen.state = "Browsing";
            knots.search( tags );
        }


        Item {
            id: item1
            x: 30
            y: 34
            width: 378
            height: 65

            Rectangle {
                id: lineEdit
                y: 28
                width: 364
                height: 40
                radius: 18
                border.color: "#000000"
                TextInput {
                    id: editor
                    x: 10
                    y: 7
                    width: 349
                    height: 27
                    color: "#000000"
                    text: ""
                    inputMask: ""
                    font.pointSize: 15
                    horizontalAlignment: TextInput.AlignHCenter
                    smooth: true
                    anchors.rightMargin: 17
                    selectionColor: "#008000"
                    anchors.verticalCenterOffset: 0
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: false
                    anchors.right: parent.right
                    anchors.leftMargin: 17
                    cursorVisible: true
                    anchors.left: parent.left
                    focus: true
                    Keys.onReturnPressed: container.accept( text )
                }
                anchors.rightMargin: 9
                border.width: 0
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.leftMargin: 5
                anchors.left: parent.left
            }

            Item {
                id: returnKey
            }

            Button {
                id: tagButton
                x: 397
                y: 1
                width: 63
                height: 64
                text: ""
                hoverImage: "../images/knots_button_search.png"
                backgroundImage: "../images/knots_button_search.png"
                activeImage: "../images/knots_button_search.png"
                anchors.left: lineEdit.right
                anchors.leftMargin: 10
                anchors.verticalCenter: lineEdit.verticalCenter
                onClicked: { container.accept(editor.text); }
            }
        }

    }

}
