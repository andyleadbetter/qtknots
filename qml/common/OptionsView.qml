import Qt 4.7

import "../common" as Common

Rectangle {
    Item {
        width: parent.width - 4;
        height:  parent.height;


        Common.OptionsModel {
            id: optionsModel
        }

        Component {
            id: optionsDelegate
            Item {
                id: optionsWrapper; width: optionsWrapper.ListView.view.width; height: 86
                Item {
                    Rectangle { color: "black"; opacity: index % 2 ? 0.6 : 0.8; height: 84; width: optionsWrapper.width; y: 1 }
                    Column {
                        x: 6; width: optionsWrapper.ListView.view.width; y: 15; spacing: 2
                        Text { text: name; font.family: "MS Sans Serif"; font.pointSize: 18; width: parent.width; elide: Text.ElideRight; color: "#cccccc"; style: Text.Raised; styleColor: "black" }
                    }
                }
                MouseArea {
                    anchors.fill: optionsWrapper
                    onClicked: {
                        console.log( "Clicked " + index +" Next State " + nextState )
                        if( name == "DefaultView" ) {
                            if( screen.defaultView == "List" ) {
                                screen.defaultView = "Grid"
                            } else {
                                screen.defaultView = "List"
                            }
                        }

                        screen.state = nextState
                    }
                }
            }
        }

        ListView {
            id: optionsList; delegate: optionsDelegate; z: 6
            width: parent.width; height: parent.height; model: optionsModel
        }
    }
}
