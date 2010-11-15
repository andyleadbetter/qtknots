import Qt 4.7


Component {
    id: listDelegate
    Item {
        id: wrapper; width: wrapper.ListView.view.width; height: 86
        Item {
            id: moveMe
            Rectangle { color: "black"; opacity: index % 2 ? 0.6 : 0.8; height: 84; width: wrapper.width; y: 1 }

            Column {
                x: 6; width: wrapper.ListView.view.width; y: 15; spacing: 2
                Text { text: name; font.family: "MS Sans Serif"; font.pointSize: 18; width: parent.width; elide: Text.ElideRight; color: "#cccccc"; style: Text.Raised; styleColor: "black" }
            }
        }
        MouseArea {
            anchors.fill: wrapper
            onClicked: {
                console.log( "Clicked " + index )
                screen.state = "Browsing"
                profilesModel.currentProfile = index;
            }

        }
    }
}

