import Qt 4.7
import "../mobile" as Mobile
import "../common" as Common

Item {
    id: toolbar

    property alias playLabel: play.text
    property alias nextLabel: next.text
    property alias prevLabel: next.text
    property alias duration: position.maximum
    property alias position: position.value

    signal playClicked
    signal nextClicked
    signal prevClicked
    signal stopClicked
    signal seek

    BorderImage { source: "../images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {
        id: stop
        text: "Stop"
        anchors.left: parent.left; anchors.leftMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.stopClicked()
    }

    Button {
        id: play
        text: "Play"
        anchors.left: stop.right; anchors.leftMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.playClicked()
    }


    Button {
        id: prev
        text: "Prev"
        anchors.left: play.right; anchors.rightMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.prevClicked()
    }

    Button {
        id: next
        text: "Next"
        anchors.left: prev.right; anchors.rightMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.nextClicked()
    }



    Common.Slider {
        id: position
        minimum: 0
        anchors.left: next.right
        anchors.right: parent.right
        anchors.verticalCenter: toolbar.verticalCenter
        anchors.margins: 5
        height: 32;
        onDragged: {
            toolbar.seek();
            console.log( "VideoControls - Dragged" + value)
        }
    }
}
