import Qt 4.7
import "../common" as Common
import Knots 1.0

Rectangle {

    id: container
    color: "#343434";

    Knots { id: knots }

    function accept(tags) {
        console.log( "Searching for " + tags );
        screen.state = "Browsing";
        knots.search( tags );
    }



    Rectangle {
        id: lineEdit
        y: 4; height: 40
        color: "white"
        anchors {
            left: parent.left; right: parent.right; leftMargin: 30; rightMargin: 30
            verticalCenter: parent.verticalCenter
        }

        TextInput {
            id: editor
            anchors {
                left: parent.left; right: parent.right; leftMargin: 10; rightMargin: 10
                verticalCenter: parent.verticalCenter
            }
            cursorVisible: true; font.bold: true
            color: "#151515"; selectionColor: "Green"

        }

        Keys.forwardTo: [ (returnKey), (editor)]

        Item {
            id: returnKey
            Keys.onReturnPressed: container.accept(editor.text);
            Keys.onEscapePressed: titleBar.state = ""
        }


    }
    Button {
        id: tagButton;
        text:  "Search"
        anchors {
            top: lineEdit.bottom
            bottomMargin: 10
            left: lineEdit.left
        }
        width: 45; height: 32;
        onClicked: container.accept(editor.text);
    }

}

