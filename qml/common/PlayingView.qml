import Qt 4.7
import "../common" as Common

import KnotsPlayer 1.0

import QtMultimediaKit 1.1

Rectangle {
    width:  800;
    height: 480;
    id: playingPage;

    KnotsPlayer {
        id: knots;
        //onCurrentStateChanged: console.log( "State " + currentState )
    }


    Connections {
        target: videoControls
        //onDraggingChanged: console.log( ( videoControls.dragging ? "Dragging" : "Tracking" ) + videoControls.position )
        //onPositionChanged: console.log( videoControls.position )
    }

    state:  "Default"
    color: "Black"

    Video {
        id: videoPlayer
        anchors.bottom: videoControls.top;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        autoLoad: true
        playing: true
        source: knots.currentSource
        fillMode: Video.PreserveAspectFit;
        z: 5
        opacity: 1.0

        Keys.onSpacePressed: videoPlayer.paused = !videoPlayer.paused

        onErrorChanged: {
            //console.log( "Video Error:" + errorString)
        }

        onStatusChanged: {
        }

        onBufferProgressChanged: {
            //console.log( "Buffering : " + bufferProgress )
        }
        onSourceChanged: {
            //console.log( "Starting Stream @ " + source)
            playing = source=="" ? false : true;            
        }

        onPositionChanged: {
//            console.log( "Position :" + position  + "Duration: " + duration)
        }

        MouseArea {
            id: videoArea
            anchors.fill: parent
        }
    }



    Common.VideoControls {
        id: videoControls;
        width: parent.width; opacity: 1.0        


        onStopClicked: {
            knots.stop();            
            videoPlayer.playing=false;
        }

        onPlayClicked: {
            if( videoPlayer.playing ) {
                videoPlayer.playing = false;       
            } else {
                videoPlayer.playing = true;                                
            }
        }

        onDraggedToNewPos: {
            //console.log("Seeking new Position " + newPosition )
            knots.seek( newPosition );
        }


    }

    states: [
        State {
            name: "Fullscreen"
            PropertyChanges { target: videoArea; onClicked: { playingPage.state = "Default" } }
            PropertyChanges { target: videoControls; y: playingPage.height; }
        },
        State {
            name: "Default"
            PropertyChanges { target: videoArea; onClicked: { playingPage.state = "Fullscreen" } }
            PropertyChanges {
                target: videoControls;
                y: playingPage.height - videoControls.height;
                duration: knots.duration
                position:  knots.position
            }
        }

    ]
    transitions: Transition {
        PropertyAnimation { properties: "y"; duration: 200 }
    }
}
