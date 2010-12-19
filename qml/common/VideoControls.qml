import Qt 4.7

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

    height:  64


    BorderImage { source: "../images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {
        id: prev
        activeImage: "../images/knots_button_prev.png"
        hoverImage: activeImage
        backgroundImage: activeImage
        anchors.left: parent.left ; anchors.rightMargin: 5; y: 3;
        noBorders: true
        width: 60; height: 60
        onClicked: toolbar.prevClicked()
    }

    Button {
        id: stop

        activeImage: "../images/knots_button_stop.png"
        hoverImage: activeImage
        backgroundImage:  activeImage
        anchors.left: prev.right; anchors.leftMargin: 5; y: 3;
        noBorders: true
        width: 60; height: 60

        onClicked: toolbar.stopClicked()
    }

    Button {
        id: play
        activeImage: "../images/knots_button_play.png"
        hoverImage: activeImage
        backgroundImage: activeImage
        anchors.left: stop.right; anchors.leftMargin: 5; y: 3;
        noBorders: true
        width: 60; height: 60

        onClicked: toolbar.playClicked()
    }

    Button {
        id: next
        activeImage:"../images/knots_button_next.png"
        hoverImage: activeImage
        backgroundImage: activeImage
        anchors.left: play.right; anchors.rightMargin: 5; y: 3;
        noBorders: true
        width: 60; height: 60

        onClicked: toolbar.nextClicked()
    }


    Common.Slider {
        id: position
        minimum: 0
        anchors.left: next.right
        anchors.right: parent.right
        anchors.verticalCenter: toolbar.verticalCenter
        anchors.margins: 10
        height: 32;
        onDraggingChanged: {
            if( !dragging )
                toolbar.seek();
        }

        onValueChanged: {
        }        

    }

}
