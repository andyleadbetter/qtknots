import Qt 4.7
import "../mobile" as Mobile
import "../common" as Common
import ProfilesList 1.0


Rectangle {
    Item {
        x: 2;
        width: parent.width - 4
        height:  parent.height;

        ProfilesList { id: profilesModel }

        Common.ProfilesDelegate { id: listDelegate }
        ListView {
            id: profilesListView; delegate: listDelegate; z: 6
            width: parent.width; height: parent.height; model: profilesModel

            // Set the highlight delegate. Note we must also set highlightFollowsCurrentItem
            // to false so the highlight delegate can control how the highlight is moved.
            highlight: highlightBar
            highlightFollowsCurrentItem: true

        }
        // Define a highlight with customised movement between items.
        Component {
            id: highlightBar
            Rectangle {
                width: parent.width; height: parent.height;
                color: "#FFFF88"
                y: profilesListView.currentItem.y;
                Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
            }
        }



    }
}
