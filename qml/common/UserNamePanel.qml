import Qt 4.7
import "../common" as Common
import Knots 1.0

Item {
    width: 800
    height: 480

    MouseArea {
        anchors.fill: parent
        onPressed: screen.state = "Browsing"
    }

    Rectangle {

        Behavior on opacity {  PropertyAnimation { property: "opacity"; duration: 200; } }

        id: container
        width: 473
        height: 124
        color: "#2f2828"
        radius: 14

        border.width: 2
        border.color: "#959090"

        anchors.centerIn: parent

        Knots { id: knots }

        FocusScope {
            id: item1
            width: 378
            height: 98
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5

            Common.LineEdit {
                id: lineEditUser                
                prompt: "Tap to enter username"
                height: 40
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                Component.onCompleted: { text = knots.userName }
            }

            Common.LineEdit {
                id: lineEditPass
                prompt: "Tap to enter password"
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                height: 40
                Component.onCompleted: { text = knots.password }
            }


            Item {
                id: returnKey
            }

            Button {
                id: tagButton
                x: 394
                y: 36
                width: 64
                height: 64
                text: ""
                noBorders: true
                hoverImage: "../images/lock-icon.svg"
                backgroundImage: "../images/lock-icon.svg"
                activeImage: "../images/lock-icon.svg"
                anchors.left: item1.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    knots.userName = lineEditUser.text;
                    knots.password = lineEditPass.text;
                    knots.login();
                    screen.state = "Browsing"
                }
            }

        }

    }

}
