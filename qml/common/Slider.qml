/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Components project on Qt Labs.
**
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions contained
** in the Technology Preview License Agreement accompanying this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
****************************************************************************/

import Qt 4.7
import RangeModel 1.0



Item {
    id: basicSlider;

    property variant sliderEdgeOffset: 6
    property real value
    property alias inverted: model.inverted
    property alias minimum: model.minimumValue
    property alias maximum: model.maximumValue

    signal draggedToNewValue( real newValue )



    Connections {
        target: basicSlider
        onValueChanged:{
            if( knobArea.drag.active == false ){
                model.setValue(value);
            }
        }
    }

    Binding {
        target: model
        property:  "position"
        value:     knob.x
        when: knobArea.drag.active
    }

    Binding {
        target: knob
        property:  "x"
        value:     model.position
        when: !knobArea.drag.active
    }


    Text {
        id: label
        font.pixelSize: 32
        color: "white"
        anchors.right:  parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 4
        height: 60
        text: model.label
    }

    Item {
        id: grooveContainer
        height: 22

        anchors.left:  parent.left
        anchors.right: label.left

        BorderImage {
            id: sliderBase
            width: parent.width - 12
            x: 6
            anchors.verticalCenter: parent.verticalCenter
            source: Qt.resolvedUrl("../images/slider-background.png");

            border.left: 10
            border.top: 0
            border.right: 10
            border.bottom: 0


            MouseArea {
                id: grooveArea
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.right: parent.right
                height: 20
                onPressed: { model.setPosition(knob.x - knob.width/2); }
                onReleased: {
                    //console.log( "Groove released at " + model.value )
                    basicSlider.draggedToNewValue(model.value)
                }

            }

            BorderImage {
                id: knob

                anchors.verticalCenter: parent.verticalCenter
                width: 22
                height: 32

                border.left: 10
                border.top: 1
                border.right: 10
                border.bottom: 1

                source: Qt.resolvedUrl("../images/slider-handle.png");

                MouseArea {
                    id: knobArea
                    anchors.fill: knob
                    drag.target: knob
                    drag.axis: "XAxis"
                    drag.minimumX: -sliderEdgeOffset
                    drag.maximumX: sliderBase.width - knob.width / 2 - sliderEdgeOffset
                    onReleased: {
                        //console.log( "Knob Area released at " + model.value )
                        basicSlider.draggedToNewValue(model.value)
                    }
                }

                states: [
                    State {
                        name: "hover"
                        when: !knobArea.pressed && knobArea.containsMouse
                        PropertyChanges { target: knob; source: Qt.resolvedUrl("../images/slider-handle-hover.png"); }
                    },
                    State {
                        name: "pressed"
                        when: knobArea.pressed
                        PropertyChanges { target: knob; source: Qt.resolvedUrl("../images/slider-handle-active.png"); }
                    }
                ]
            }
        }
    }
    RangeModel {
        id: model
        type: RangeModel.TimeScale
        minimumValue: 0
        maximumValue: 100
        positionAtMinimum: -sliderEdgeOffset
        positionAtMaximum: sliderBase.width - knob.width / 2 - sliderEdgeOffset
    }
}
