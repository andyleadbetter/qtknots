import Qt 4.7
import "../common" as Common
import "../mobile" as Mobile
import Knots 1.0
import KnotsDirectory 1.0

Rectangle {

    Knots { id: knotsData }

    Item {
        x: 2;
        width: parent.width - 4
        height:  parent.height;


        DirectoryDelegate { id: listDelegate }
        ListView {
            id: videoListView; model: knotsData.currentDirectory; delegate: listDelegate;
            width: parent.width; height: parent.height;
        }        
    }
}
