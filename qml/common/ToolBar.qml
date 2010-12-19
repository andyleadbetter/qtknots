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

Item {
    id: toolbar
    height: 40; anchors.bottom: page.bottom; width: parent.width;

    property alias button1Label: button1.text
    property alias button2Label: button2.text    
    property alias button3Label: button3.text
    property alias button4Label: button4.text

    property alias button1Image: button1.activeImage
    property alias button2Image: button2.activeImage
    property alias button3Image: button3.activeImage
    property alias button4Image: button4.activeImage

    property alias button1Visible: button1.visible
    property alias button2Visible: button2.visible
    property alias button3Visible: button3.visible
    property alias button4Visible: button4.visible

    property alias button1borders: button1.noBorders
    property alias button2borders: button2.noBorders




    signal button1Clicked
    signal button2Clicked
    signal button3Clicked
    signal button4Clicked


    BorderImage { source: "../images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {
        id: button1

        hoverImage: activeImage
        backgroundImage: activeImage

        anchors.left: parent.left; anchors.leftMargin: 5; y: 3; width: text=="" ? 32 : 140; height: 32
        onClicked: toolbar.button1Clicked()
    }

    Rectangle {

        id: smallButtons
        anchors.horizontalCenter: parent.horizontalCenter


        Button {
            id: button2
            hoverImage: activeImage
            backgroundImage: activeImage
            anchors.left: smallButtons.right; anchors.leftMargin: 10; y: 3; width: text=="" ? 32 : 140; height: 32
            onClicked: toolbar.button2Clicked()
        }

        Button {
            id: button3
            noBorders: true
            hoverImage: activeImage
            backgroundImage: activeImage
            anchors.left: button2.right; anchors.leftMargin: 10; y: 3; width: text=="" ? 32 : 140; height: 32
            onClicked: toolbar.button3Clicked()
        }

        Button {
            id: button4
            noBorders: true
            hoverImage: activeImage
            backgroundImage: activeImage
            anchors.left: button3.right; anchors.leftMargin: 10; y: 3; width: text=="" ? 32 : 140; height: 32
            onClicked: toolbar.button4Clicked()
        }

    }

}
