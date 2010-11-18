import Qt 4.7

Component {
    id: listDelegate
    Item {
        id: wrapper; width: wrapper.ListView.view.width; height: 86
        Item {
            id: moveMe
            Rectangle { color: "black"; opacity: index % 2 ? 0.6 : 0.8; height: 84; width: wrapper.width; y: 1 }
            Rectangle {
                x: 6; y: 4; width: 77; height: 77; color: "white"; smooth: true
                Image { id: thumb; source: thumbnail ; x: 1; y: 1;fillMode: Image.PreserveAspectFit; smooth: true; width: 75; height: 75 ; onStatusChanged:  { console.log("Image Status " + Image.status) } }
                Image { source: "../images/gloss.png" }
            }
            Column {
                x: 92; width: wrapper.ListView.view.width - 95; y: 15; spacing: 2
                Text { text: name; color: "white"; width: parent.width; font.bold: true; elide: Text.ElideRight; style: Text.Raised; styleColor: "black" }
             }
        }

        MouseArea {
            anchors.fill: wrapper
            onClicked: {
                videoListView.currentIndex = index;
                console.log( "QML: Selected " + model.id );
                screen.state = knotsData.itemSelected( model.id );
            }
        }
    }
}

