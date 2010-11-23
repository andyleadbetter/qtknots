
import Qt 4.7
import "common" as Common
import "mobile" as Mobile
import Knots 1.0

Item {
    id: screen; width: 800; height: 480
    state: "Browsing"


    Knots {
        id: knots     
    }

    Rectangle {
        id: page
        anchors.fill: parent; color: "#343434";


        Image { source: "images/stripes.png"; fillMode: Image.Tile; anchors.fill: parent; opacity: 0.3 }

        Mobile.TitleBar { id: titleBar; width: parent.width; height: 40; opacity: 0.9; z: 5 }

        Common.DirectoryView {
            id: mainView;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
        }

        Common.ProfilesView {
            id: profilesView;
            x: -parent.width;
            width: parent.width;
            anchors.top: titleBar.bottom;
            anchors.bottom: toolBar.top;
        }

        Mobile.ToolBar {
            id: toolBar; z: 5
            height: 40; anchors.bottom: parent.bottom; width: parent.width; opacity: 0.9
            button1Label: "Profile"; button2Label: "Back"        
        }
    }
    states: [
        State {
            name: "Profile"
            PropertyChanges { target: mainView; x: parent.width }
            PropertyChanges { target: profilesView; x: 0 }            
            PropertyChanges { target: page; x: 0 }
            PropertyChanges { target: toolBar; }
            PropertyChanges { target: toolBar; button1Label: "Back"; }
            PropertyChanges { target: toolBar; button2Label: ""; }
            PropertyChanges { target: toolBar; onButton1Clicked: screen.state = "Browsing"; }
            PropertyChanges { target: toolBar; visible: true}
            PropertyChanges { target: toolBar; visible: true }
            PropertyChanges { target: titleBar; visible: true }
            PropertyChanges { target: page; z: 1}



        },
        State {
            name: "Browsing"
            PropertyChanges { target: page; x: 0 }
            PropertyChanges { target: mainView; x: 0 }
            PropertyChanges { target: profilesView; x: -parent.width  }
            PropertyChanges { target: toolBar; button1Label: "Back"; }
            PropertyChanges { target: toolBar; button2Label: "Profile" }
            PropertyChanges { target: toolBar; onButton1Clicked: knots.backSelected(); }
            PropertyChanges { target: toolBar; onButton2Clicked: screen.state = "Profile" }
            PropertyChanges { target: toolBar; visible: true }
            PropertyChanges { target: titleBar; visible: true }
            PropertyChanges { target: page; z: 1}
        }
    ]

    transitions: Transition {
        PropertyAnimation { properties: "x"; duration: 200 }
    }
}
