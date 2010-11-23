import Qt 4.7
import "../common" as Common
import "../mobile" as Mobile
import Knots 1.0

import QtMultimediaKit 1.1
import QtMobility.systeminfo 1.1

//import  Qt.multimedia 1.0



Rectangle {
    width:  800;
    height: 480;
    id: playingPage;
    Knots {  id: knots }
    state:  "Default"
    color: "Black"

    Video {
        id: videoPlayer
        anchors.bottom: videoControls.top;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        autoLoad: false
        playing: false        
        source: knots.currentSource
        fillMode: Video.PreserveAspectFit;
        z: 5
        opacity: 1.0

        Keys.onSpacePressed: videoPlayer.paused = !videoPlayer.paused

        onErrorChanged: {
            console.log( "Video Error:" + errorString)
        }

        onStatusChanged: {
        }

        onBufferProgressChanged: {
            //console.log( "Buffering : " + bufferProgress )
        }
        onSourceChanged: {
            //console.log( "Starting Stream @ " + source)
            playing = true;
            videoControls.position = 0;
            backlightControllerTimer.start();
            sliderUpdater.start();
        }

        onPositionChanged: {
//            console.log( "Position :" + position  + "Duration: " + duration)
        }

        MouseArea {
            id: videoArea
            anchors.fill: parent
        }
    }

    Mobile.VideoControls {
        id: videoControls; z: 5

        height: 40; width: parent.width; opacity: 1.0
        position: knots.position
        duration: knots.duration
        onStopClicked: {
            knots.stop();
            backlightControllerTimer.stop()
            sliderUpdater.stop()
            videoPlayer.playing=false;
        }
        onPlayClicked: {
            if( videoPlayer.playing ) {
                videoPlayer.playing = false;
                playLabel = "Play";
            } else {
                videoPlayer.playing = true;                
                playLabel = "Pause"
            }
        }
        onSeek: {
            console.log( "PlayingView - Seeking" + position)
            knots.seek( position );
        }

    }

    ScreenSaver {
        id: backlightControl
        screenSaverDelayed: true
    }

    Timer {
        id: backlightControllerTimer
        interval: 20000 // 20 seconds
        repeat:  true
        onTriggered: {
            backlightControl.screenSaverDelayed = true;
            console.log( "Delayed Screensaver")
        }
    }

    Timer {
        id: sliderUpdater
        interval: 1000 // 1 seconds
        repeat:  true
        onTriggered: {
            videoControls.position = videoControls.position + 1000 ;
            console.log( "update position slider")
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
            PropertyChanges { target: videoControls; y: playingPage.height - videoControls.height; }
        }

    ]
    transitions: Transition {
        PropertyAnimation { properties: "y"; duration: 200 }
    }
}
