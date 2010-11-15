import Qt 4.7
import "../mobile" as Mobile
import "../common" as Common

Item {
    id: toolbar

    property alias playLabel: play.text
    property alias nextLabel: next.text
    property alias prevLabel: next.text
    property alias length: position.maximum
    property alias position: position.value

    signal playClicked
    signal nextClicked
    signal prevClicked

    BorderImage { source: "../images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {
        id: play
        anchors.left: parent.left; anchors.leftMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.playClicked()
    }

    Button {
        id: prev
        anchors.left: play.right; anchors.rightMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.prevClicked()
    }

    Button {
        id: next
        anchors.left: prev.right; anchors.rightMargin: 5; y: 3; width: 140; height: 32
        onClicked: toolbar.nextClicked()
    }



    Common.Slider {
        id: position
        anchors.left: next.right
        // value is read/write.
        onValueChanged: { handle.x = 2 + (value - minimum) * slider.xMax / (maximum - minimum); }
    }
}
