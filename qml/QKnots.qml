
import Qt 4.7
import "common" as Common
import Knots 1.0
import KnotsDirectory 1.0

Item {
    id: screen; width: 800; height: 480
    state: "Browsing"

    property string defaultView: "Grid"

    Knots {
        id: knots     
    }

    Rectangle {
        id: page
        anchors.fill: parent;
        color: "#343434";


        Common.TitleBar { id: titleBar; anchors.top:  page.top; z: 5 }

        Loader {
            id: directoryView
            sourceComponent: defaultView=="List" ? directory : grid ;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
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
                cellHeight:  200
                cellWidth: 200
                delegate: Common.GridDelegate {}
                model: knots.currentDirectory
            }
        }

        Component {
            id: directory
            ListView {
                anchors.fill: parent
                id: videoListView; delegate: Common.DirectoryDelegate {}
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
            x: parent.width;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
        }
    }

    states: [

        State {
            name: "Browsing"
            PropertyChanges { target: directoryView; x: 0 }
            PropertyChanges { target: optionsView; x: parent.width  }
            PropertyChanges { target: profilesView; x: 2*parent.width  }
            PropertyChanges { target: searchView; x:   2*parent.width  }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                button2Label: "Options";
                onButton1Clicked: knots.backSelected();
                onButton2Clicked: screen.state = "Options"
                button4Visible: false;
                button3Visible: false;
            }
        },
        State {
            name: "Options"
            PropertyChanges { target: directoryView; x: -parent.width }
            PropertyChanges { target: profilesView;  x: parent.width  }
            PropertyChanges { target: searchView;    x: parent.width  }
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
            PropertyChanges { target: searchView; x:  parent.width  }
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
            PropertyChanges { target: searchView; x: 0}
            PropertyChanges { target: directoryView; x: parent.width  }
            PropertyChanges { target: optionsView; x: -parent.width  }
            PropertyChanges { target: profilesView; x: -2*parent.width  }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Options";
                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
            }
        }
    ]
    transitions: Transition {
        PropertyAnimation { properties: "x"; duration: 200 }
    }
}
