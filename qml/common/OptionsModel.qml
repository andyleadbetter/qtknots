import Qt 4.7

ListModel {
    id: optionsModel;
    ListElement {
        name: "Search"
        nextState: "Searching"
    }
    ListElement {
        name: "DefaultView"
        nextState: "Browsing"
    }
    ListElement {
        name: "Change Server"
        nextState: "serverSettings"
    }
    ListElement {
        name: "Change Profile"
        nextState: "Profile"
    }
    ListElement {
        name: "Refresh Collection"
        nextState: "refreshCollection"
    }
}
