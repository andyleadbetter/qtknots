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

            Common.LineEdit {
                id: editor
                prompt: "Enter Tags..."
                height: 40
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                Keys.onReturnPressed: container.accept( text )
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
                anchors.left: editor.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onClicked: { container.accept(editor.text); }
            }
        }
    }
}


