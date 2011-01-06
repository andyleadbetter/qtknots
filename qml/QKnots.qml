
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

        Common.TitleBar { id: titleBar; anchors.top:  page.top; z: 5;  onTaskSwitch: knots.taskSwitch() }

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
                cacheBuffer: cellHeight * 2
                snapMode: GridView.SnapToRow
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


        Common.SearchPanel {
            opacity: 0.0
            id: searchView;
            anchors.centerIn: parent
        }

        Common.UserNamePanel {
            opacity: 0.0
            id: userNameView;
            anchors.centerIn: parent
        }

        Common.RefreshView {
            opacity: 0.0
            id: refreshView;
            anchors.centerIn: parent
        }

        Common.DetailsPanel {
            id: mediaDetails
            opacity:  0.0
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
                button5Image: "/qml/images/lock-icon.svg"
                onButton1Clicked: knots.backSelected();
                onButton2Clicked: screen.state = "Options";
                onButton3Clicked: screen.state = "Searching";
                onButton4Clicked: screen.defaultView == "List" ? screen.defaultView = "Grid" : screen.defaultView = "List";
                onButton5Clicked: screen.state = "UserName";
                button4Visible: true;
                button3Visible: true;
                button5Visible: true;
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
                button5Visible: false;
            }
        },
        State {
            name: "Searching"
            PropertyChanges { target: searchView; opacity: 1.0; z: 1 }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Browsing";
                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
                button5Visible: false;
            }
        },
        State {
            name: "UserName"
            PropertyChanges { target: userNameView; opacity: 1.0 }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Browsing";
                button2Visible: false;
                button3Visible: false;
                button4Visible: false;
                button5Visible: false;

            }
        },
        State {
            name: "Refreshing"
            PropertyChanges { target: refreshView; opacity: 1.0 }
            PropertyChanges { target: toolBar;
                button1Label: "Back";
                onButton1Clicked: screen.state = "Browsing";
                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
                button5Visible: false;
            }
        },
        State {
            name: "Details"
            PropertyChanges { target: mediaDetails; opacity: 1.0 }
            PropertyChanges { target: toolBar;
                button1Label: "Play";
                onButton1Clicked: {
                    knots.play( mediaDetails.mediaId );
                    screen.state = "Browsing"
                }

                button2Visible: false;
                button4Visible: false;
                button3Visible: false;
                button5Visible: false;
            }
        }
    ]
    transitions: Transition {
        PropertyAnimation { properties: "x"; duration: 200 }
        PropertyAnimation { properties: "opacity"; duration:  150 }

    }
}
