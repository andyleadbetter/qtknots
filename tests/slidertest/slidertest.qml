import Qt 4.7


Rectangle {
    width: 400
    height: 100

    Slider {
        id: positionSlider
        minimum: 0
        anchors.left: next.right
        anchors.right: parent.right
        anchors.verticalCenter: toolbar.verticalCenter
        anchors.margins: 10
        height: 32;

        onValueChanged: {
            console.log( "Slider repositioned to " + value)
        }
    }
}
