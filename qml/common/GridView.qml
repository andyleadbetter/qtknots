import Qt 4.7
import "../common" as Common

import Knots 1.0
import KnotsDirectory 1.0

Item {

    Knots { id: knotsData }

    GridDelegate { id: gridDelegate }

    GridView {
        anchors.fill: parent

        id: videoGridView; delegate: gridDelegate;
        model: knotsData.currentDirectory
    }
}
