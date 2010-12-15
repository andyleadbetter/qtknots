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
import "../common" as Common


Flipable {
    id: container

    property variant frontContainer: containerFront
    property string videoTitle: ""
    property string videoDuration: ""
    property string videoWidth
    property string videoHeight
    property string videoType
    property string videoAuthor
    property string videoDate
    property string videoUrl
    property int rating: 2
    property variant prevScale: 1.0

    signal closed

    transform: Rotation {
        id: itemRotation
        origin.x: container.width / 2;
        axis.y: 1; axis.z: 0
    }

    front: Item {
        id: containerFront; anchors.fill: container

        Rectangle {
            anchors.fill: parent
            color: "black"; opacity: 0.4
        }

        Column {
            spacing: 10
            anchors {
                left: parent.left; leftMargin: 20
                right: parent.right; rightMargin: 20
                top: parent.top; topMargin: 180
            }
            Text { font.bold: true; color: "white"; elide: Text.ElideRight; text: container.videoTitle }
            Text { color: "white"; elide: Text.ElideRight; text: "<b>Size:</b> " + container.videoWidth + 'x' + container.videoHeight }
            Text { color: "white"; elide: Text.ElideRight; text: "<b>Duration:</b> " + container.videoDuration}
            Text { color: "white"; elide: Text.ElideRight; text: "<b>Published:</b> " + container.videoDate }
            Text { color: "white"; elide: Text.ElideRight; text: container.videoTags == "" ? "" : "<b>Tags:</b> " }            
        }
    }


    states: State {
        name: "Back"
        PropertyChanges { target: itemRotation; angle: 180 }
    }

}
