import Qt 4.7

Component {
    id: listDelegate


    Item {
        id: wrapper; width: wrapper.ListView.view.width; height: 100
        Item {


            Rectangle { color: "black"; opacity: index % 2 ? 0.6 : 0.8; height: 98; width: wrapper.width; y: 1 }
            Rectangle {
                Behavior on scale { NumberAnimation { easing.type: Easing.InOutQuad} }
                id: moveMe
                function updateImage(){
                        thumb.source = moveMe.cachedUrl;
                    }
                property string cachedUrl: thumbnail;
                scale: 0
                x: 6; y: 4; width: 99; height: 94; color: "white"; smooth: true
                Image { id: thumb; source: thumbnail;  x: 1; y: 1;fillMode: Image.PreserveAspectFit; smooth: true; width: 95; height: 95 ; }
                Component.onCompleted : moveMe.updateImage();
            }
            Column {
                x: 110; width: wrapper.ListView.view.width - 95; y: 15; spacing: 2
                Text { text: name; color: "white"; width: parent.width; font.pointSize: 15; font.bold: true; elide: Text.ElideRight; style: Text.Raised; styleColor: "black" }
             }

            states: [
                State {
                    name: "Show"; when: thumb.status == Image.Ready
                    PropertyChanges { target: moveMe; scale: 1 }
                }
            ]
        }

        MouseArea {
            anchors.fill: wrapper
            onClicked: {
                videoListView.currentIndex = index;
                console.log( "QML: Selected " + model.id );
                screen.state = knots.currentDirectory.itemSelected( model.id );
            }
        }
    }

}

