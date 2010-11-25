/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

import Qt 4.7
import Knots 1.0

Item {
    id: titleBar
    property string untaggedString: "Uploads from everyone"
    property string taggedString: "Recent uploads tagged "

    BorderImage { source: "../images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Knots {
        id: knots
    }

    Item {
        id: container
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height

        function changeServer() {
            titleBar.state = ""            
            knots.serverName =  editor.text;
        }

        function search() {
            titleBar.state = ""
            knots.search(editor.text);
        }


        Button {
            id: quitButton;
            text:  ""
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
            }
            width: 45; height: 32; backgroundImage: "../images/quit.png"; activeImage: "../images/quit.png"; hoverImage: "../images/quit.png"
            onClicked: Qt.quit()
        }

        Text {
            id: categoryText
            text:  ""
            anchors {
                left: quitButton.right; right: tagButton.left; leftMargin: 10; rightMargin: 10
                verticalCenter: parent.verticalCenter
            }
            elide: Text.ElideLeft            
            font.bold: true; color: "White"; style: Text.Raised; styleColor: "Black"
        }

        Button {
            id: tagButton;
            text:  "Search"
            anchors {
                right: serverButton.left
                verticalCenter: parent.verticalCenter
            }
            width: 45; height: 32;
            onClicked: container.search();
        }

        Button {
            id: serverButton;
            text:  "Server"
            anchors {
                right: container.right;
                verticalCenter: parent.verticalCenter
            }
            width: 45; height: 32;
            onClicked: container.changeServer();
        }

        Item {
            id: lineEdit
            y: 4; height: parent.height - 9
            anchors {
                left: quitButton.right; right: tagButton.left; leftMargin: 10; rightMargin: 10
                verticalCenter: parent.verticalCenter
            }
            BorderImage { source: "../images/lineedit.sci"; anchors.fill: parent }

            TextInput {
                id: editor
                anchors {
                    left: parent.left; right: parent.right; leftMargin: 10; rightMargin: 10
                    verticalCenter: parent.verticalCenter
                }
                cursorVisible: true; font.bold: true
                color: "#151515"; selectionColor: "Green"
            }

            Keys.forwardTo: [ (returnKey), (editor)]

            Item {
                id: returnKey
                Keys.onReturnPressed: container.accept()
                Keys.onEscapePressed: titleBar.state = ""
            }
        }
    }

    states: [
        State {
            name: "ServerChange"
            PropertyChanges { target: container; x: -tagButton.x + 5 }
            PropertyChanges { target: tagButton; text: "OK";  }
            PropertyChanges { target: editor; text: knots.serverName; focus: true }
        },
        State {
            name: "Search"
            PropertyChanges { target: container; x: -tagButton.x + 5 }
            PropertyChanges { target: tagButton; text: "OK"; }
            PropertyChanges { target: editor; focus: true }
        }
    ]

    transitions: Transition {
        NumberAnimation { properties: "x"; easing.type: Easing.InOutQuad }
    }
}
