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
    id: slider; height: 16

    signal dragged

    property bool dragging: false


    // value is read/write.
    property real value    
    property real maximum: 1
    property real minimum: 0
    property int xMax: slider.width - handle.width - 4
    property real stepPerPixel: ( maximum - minimum ) / width

    onValueChanged: {
        if( !dragging ) {
            handle.x = 2 + (value - minimum) * slider.xMax / (maximum - minimum);
        }
    }

    Rectangle {
        anchors.fill: parent
        border.color: "white"; border.width: 0; radius: 8
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#66343434" }
            GradientStop { position: 1.0; color: "#66000000" }
        }
    }

    MouseArea {
        id: grooveMouseAreaLessThanHandle
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: handle.left
        anchors.left: parent.left
        height: slider.height
        onPressed: {
            value =  Math.min( value, value - ( 5 * stepPerPixel ) )

            console.log( "Position after press " + value );
        }
    }

    MouseArea {
        id: grooveMouseAreaPastThanHandle
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: handle.right
        anchors.right: parent.right

        onPressed: {
            value =  Math.max( value, value + ( 5 * stepPerPixel ) )
            console.log( "Position after press " + value );
        }
    }


    Rectangle {
        id: handle; smooth: true
        x: slider.width / 2 - handle.width / 2; y: 2; width: 30; height: slider.height-4; radius: 6
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightgray" }
            GradientStop { position: 1.0; color: "gray" }
        }

        MouseArea {
            signal seek;
            anchors.fill: parent; drag.target: parent
            drag.axis: Drag.XAxis; drag.minimumX: 2; drag.maximumX: slider.xMax+2
            onPressed: { slider.dragging = true }
            onPositionChanged: { value = (maximum - minimum) * (handle.x-2) / slider.xMax + minimum; }
            onReleased: {console.log( "slider - Released" + value); slider.dragging = false; slider.dragged(); }
        }
    }

}
