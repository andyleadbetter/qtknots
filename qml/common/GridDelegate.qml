import Qt 4.7
import QtQuick 1.0

Component {
    id: gridDelegate;

    Rectangle {
        function showDetails()
        {
            mediaDetails.name =  model.name;
            mediaDetails.duration = duration;
            mediaDetails.views = views;
            mediaDetails.position = lastposition;
            mediaDetails.imageUrl = thumbnail;
            mediaDetails.mediaId =  model.mediaId;
            mediaDetails.addedOn = addedOn;
            mediaDetails.size = model.width + "x" + model.height
        }

        id: gridWrapper;
        width: GridView.view.cellWidth; height: GridView.view.cellHeight ;
        color: "white"; smooth: false
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
            elide: Text.ElideLeft
            smooth:  true
            wrapMode: Text.WordWrap

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
                showDetails();
                screen.state = knots.currentDirectory.itemSelected( model.id );
            }
        }
    }
}
