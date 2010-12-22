import Qt 4.7

ListModel {
    id: optionsModel;
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
