import Qt 4.7
import "../common" as Common

Item {

    id: detailsContainer

    anchors.fill: parent

    property string name
    property string duration
    property string position
    property string views
    property string imageUrl
    property string mediaId
    property string addedOn
    property string size


    MouseArea {
        anchors.fill:  parent
        onPressed: screen.state = "Browsing"
    }

    Rectangle {

        Behavior on opacity {  PropertyAnimation { property: "opacity"; duration: 200; } }

        id: container
        width: 500
        height: 357
        color: "#2f2828"
        radius: 14
        border.width: 2
        border.color: "#959090"

        anchors.centerIn: parent

        Rectangle {
            id: rectangle1
            x: 32
            y: 28
            width: 437
            height: 288
            color: "#7a7a7a"
            radius: 14

            Text {
                id: itemName
                color: "#ffffff"
                text:  detailsContainer.name
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.rightMargin: 8
                anchors.leftMargin: 8
                anchors.topMargin: 8
                style: Text.Normal
                font.family: "Arial Black"
                smooth: true
                font.pixelSize: 16
            }

            Text {
                id: viewsLabel
                color: "#ffffff"
                text: "Views"
                anchors.topMargin: 50
                smooth: true
                font.pixelSize: 13
                anchors.top: itemName.bottom
                anchors.left:  itemName.left
                style: Text.Normal
                anchors.bottomMargin: 40
                font.bold: false
                font.family: "Arial"
            }

            Text {
                id: positionLabel
                color: "#ffffff"
                text: detailsContainer.position != "00:00:00" ? "Resume Position" : "Duration"
                anchors.topMargin: 8
                smooth: true
                font.pixelSize: 13
                anchors.top: viewsLabel.bottom
                anchors.left:  itemName.left
                anchors.bottomMargin: 5
                style: Text.Normal
                font.bold: false
                font.family: "Arial"
            }

            Text {
                id: addedLabel
                color: "#ffffff"
                text: "Added"
                anchors.topMargin: 8
                smooth: true
                font.pixelSize: 13
                anchors.top: positionLabel.bottom
                anchors.left:  itemName.left
                style: Text.Normal
                anchors.bottomMargin: 5
                font.family: "Arial"
                font.bold: false
            }

            Text {
                id: sizeLabel
                color: "#ffffff"
                text: "Size"
                anchors.topMargin: 8
                smooth: true
                font.pixelSize: 13
                anchors.top: addedLabel.bottom
                anchors.left:  itemName.left
                style: Text.Normal
                anchors.bottomMargin: -195
                font.family: "Arial"
                font.bold: false
                visible: sizeValue.text != "x"
            }

            Text {
                id: positionValue
                color: "#ffffff"
                text:  detailsContainer.position != "00:00:00"  ?  detailsContainer.position + "/" + detailsContainer.duration : detailsContainer.duration
                smooth: true
                font.pixelSize: 13
                anchors.left: viewsLabel.right
                anchors.verticalCenter: positionLabel.verticalCenter
                anchors.leftMargin: 80
                verticalAlignment: Text.AlignVCenter
                style: Text.Normal
                font.family: "Arial"
                font.bold: false
            }

            Text {
                id: addedValue
                width: 80
                color: "#ffffff"
                text: detailsContainer.addedOn
                smooth: true
                font.pixelSize: 13
                anchors.left: viewsLabel.right
                anchors.verticalCenter: addedLabel.verticalCenter
                anchors.leftMargin: 80
                verticalAlignment: Text.AlignVCenter
                style: Text.Normal
                font.bold: false
                font.family: "Arial"
            }

            Text {
                id: viewsValue
                width: 96
                color: "#ffffff"
                text: detailsContainer.views
                verticalAlignment: Text.AlignVCenter
                anchors.left: viewsLabel.right
                anchors.leftMargin: 80
                anchors.verticalCenter: viewsLabel.verticalCenter
                smooth: true
                font.pixelSize: 15
                style: Text.Normal
                font.family: "Arial"
                font.bold: false
            }

            Text {
                id: sizeValue
                width: 96
                color: "#ffffff"
                text: detailsContainer.size
                anchors.left: viewsLabel.right
                anchors.leftMargin: 80
                anchors.verticalCenter: sizeLabel.verticalCenter
                verticalAlignment: Text.AlignVCenter
                smooth: true
                font.pixelSize: 15
                style: Text.Normal
                font.family: "Arial"
                font.bold: false
                visible: text != "x"
            }

            Image {
                id: image1
                x: 212
                y: 56
                width: 216
                height: 218
                smooth: true
                source: detailsContainer.imageUrl
                fillMode: Image.PreserveAspectFit
            }
        }
    }

}


