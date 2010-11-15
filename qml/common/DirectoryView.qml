import Qt 4.7
import "../common" as Common
import "../mobile" as Mobile
import KnotsDirectory 1.0

Rectangle {

    KnotsDirectory { id: knotsData }

    Item {
        x: 2;
        width: parent.width - 4
        height:  parent.height;


        DirectoryDelegate { id: listDelegate }
        ListView {
            id: videoListView; model: knotsData; delegate: listDelegate; z: 6
            width: parent.width; height: parent.height;
        }

    }
}
