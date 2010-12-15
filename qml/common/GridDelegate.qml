
import Qt 4.7

Component {
    id: gridDelegate;

    Rectangle {
        id: gridWrapper;
        width: GridView.view.cellWidth; height: GridView.view.cellHeight ;
        color: "white"; smooth: true
        Image {
            scale: 0.0
            Behavior on scale { NumberAnimation { easing.type: Easing.InOutQuad} }
            id: scaleMe
            source: thumbnail;
            anchors.centerIn: parent; width: parent.width - 30; height: parent.height - 30; smooth: true; fillMode: Image.PreserveAspectFit;
        }

        states: [
            State {
                name: "Show"; when: scaleMe.status == Image.Ready
                PropertyChanges { target: scaleMe; scale: 1 }
            }
        ]

        Text {
            id: label;
            text: name;

            font {
                family: "Arial";
                pixelSize: 14;
            }
            anchors {
                bottom: parent.bottom;
                horizontalCenter: parent.horizontalCenter;
            }
        }

        MouseArea {
            anchors.fill: gridWrapper
            onClicked: {
                videoGridView.currentIndex = index;
                console.log( "QML: Selected " + model.id );
                screen.state = knots.currentDirectory.itemSelected( model.id );
            }
        }
    }
}
