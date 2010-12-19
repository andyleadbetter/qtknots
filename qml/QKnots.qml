
import Qt 4.7
import "common" as Common
import Knots 1.0
import KnotsDirectory 1.0

Item {
    id: screen;
    width: 800
    height: 480
    state: "Browsing"

    property string defaultView: "Grid"

    Knots {
        id: knots     
    }

    Rectangle {
        Component.onCompleted:  { console.log( width + "x" + height) }
        id: page
        anchors.fill: parent;
        color: defaultView == "List" ? "#343434" : "white";

        Item {
            id:titleBar
            y: 0
            x: 0
            visible: false
        }

        /*Common.TitleBar { id: titleBar; anchors.top:  page.top; z: 5;  onTaskSwitch: knots.taskSwitch() }*/

        Loader {
            id: directoryView
            sourceComponent: defaultView=="List" ? directory : grid ;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;           
            Behavior on scale { NumberAnimation { easing.type: Easing.InOutQuad} }
        }

        Common.ToolBar {
            id: toolBar; z: 5; anchors.bottom: parent.bottom;            
            button1Label: "Profile"; button2Label: "Back"
        }


        Component {
            id: grid
            GridView {
                anchors.fill: parent
                id: videoGridView;
                cellHeight:  cellWidth
                cellWidth: Qt.isQtObject( parent ) ? parent.width / 4 : 0
                delegate: Common.GridDelegate {}
                model: knots.currentDirectory

                Component.onCompleted: { console.log( Component.objectName + " " + width + "x" + height + "Parent:" ) }
            }
        }

        Component {
            id: directory
            ListView {
                id: videoListView; delegate: Common.DirectoryDelegate {}
                anchors.fill: parent
                model: knots.currentDirectory
            }
        }

        Common.ProfilesView {
            id: profilesView;
            x: 2*parent.width;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
        }


        Common.OptionsView {
            id: optionsView;
            x: parent.width;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
        }


        Common.SearchView {
            id: searchView;
            anchors.centerIn: parent
        }
    }

    states: [

        State {
            name: "Browsing"
            PropertyChanges { target: directoryView; x: 0 }
            PropertyChanges { target: optionsView; x: parent.width  }
            PropertyChanges { target: profilesView; x: 2*parent.width  }
            PropertyChanges { target: searchView; opacity: 0.0 }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                button2Label: "";
                button2Image: "/qml/images/icon-m-toolbar-settings.svg"
                button2borders: false
                button3Label: ""
                button3Image: "/qml/images/knots_button_search.png"
                button4Image: screen.defaultView == "List" ? "/qml/images/icon-m-toolbar-grid.svg" :  "/qml/images/icon-m-toolbar-list.svg"
                onButton1Clicked: knots.backSelected();
                onButton2Clicked: screen.state = "Options";
                onButton3Clicked: screen.state = "Searching";
                onButton4Clicked: screen.defaultView == "List" ? screen.defaultView = "Grid" : screen.defaultView = "List";
                button4Visible: true;
                button3Visible: true;
            }
        },
        State {
            name: "Options"
            PropertyChanges { target: directoryView; x: -parent.width }
            PropertyChanges { target: profilesView;  x: parent.width  }
            PropertyChanges { target: searchView;    opacity: 0 }
            PropertyChanges { target: optionsView;   x: 0}
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Browsing"
                button2Visible: false
                button4Visible: false;
                button3Visible: false;
            }
        },
        State {
            name: "Profile"
            PropertyChanges { target: profilesView; x: 0}
            PropertyChanges { target: directoryView; x: -2*parent.width  }
            PropertyChanges { target: searchView;    opacity: 0 }
            PropertyChanges { target: optionsView; x: -parent.width  }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Options";
                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
            }
        },
        State {
            name: "Searching"
            PropertyChanges { target: searchView; opacity: 1.0 }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Browsing";
                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
            }
        }
    ]
    transitions: Transition {
        PropertyAnimation { properties: "x"; duration: 200 }
        PropertyAnimation { properties: "opacity"; duration:  150 }

    }
    Component.onCompleted: { console.log( width + "x" + height) }
}
