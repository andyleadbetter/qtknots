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
        Binding { target: frameChange; property: "running"; value:  true; when: screen.state == "Refreshing" }
        Binding { target: frameChange; property: "running"; value:  false; when: screen.state != "Refreshing" }

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



            Timer {
                id: frameChange
                interval: 50;
                onTriggered: indicators.change();
                repeat: true;
                running: false

                onRunningChanged: { console.log( "Animating" + (running==true?"Enabled":"Disabled")) }
            }

            Image {
                id: indicators
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                property int currentFrame: 1;
                property int direction;

                function change() {
                    if( currentFrame == 8 )
                        direction = -1;
                    else if ( currentFrame == 1 )
                        direction = 1;

                    currentFrame = currentFrame + direction;

                    indicators.source = "/qml/images/indicator_update_white" + currentFrame + ".png";
                }
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
                anchors.left: parent.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onClicked: { screen.state = "Browsing" }
            }
        }

    }

}
