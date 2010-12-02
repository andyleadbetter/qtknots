import Qt 4.7
import "../common" as Common


Rectangle {
    id: optionsPage;

    state: "Browsing"

    Common.ProfilesView {
        anchors.fill: parent
        id: profilesView;
    }



    states: [
        State {
            name: "Profile"
            PropertyChanges { target: optionsView; x: -width}
            PropertyChanges { target: profilesView; x: 0 }
            PropertyChanges { target: toolBar;
                button1Label: "Profiles Back";
                button2Label: "";
                onButton1Clicked: screen.state = "Options";
                button1Visible: true;
                button2Visible: false;
                button3Visible: false;
                button4Visible: false;
            }
        },
        State {
            name: "Options"
            PropertyChanges { target: optionsView; x: 0 }
            PropertyChanges { target: toolBar;
                button1Label: "Options Back";
                button2Label: "";
                onButton1Clicked: screen.state = "Browsing";
                button1Visible: true;
                button2Visible: false;
                button3Visible: false;
                button4Visible: false;
            }
        },
        State {
            name: "Browsing"
            PropertyChanges {
                target: optionsPage; x: -width;
            }
        }

    ]
    transitions: Transition {
        PropertyAnimation { properties: "x"; duration: 200 }
    }
}
