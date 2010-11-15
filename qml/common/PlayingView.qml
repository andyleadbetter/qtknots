import Qt 4.7
import "../common" as Common
import "../mobile" as Mobile
import Knots 1.0

//import QtMultimediaKit 1.1
import  Qt.multimedia 1.0



Rectangle {
    anchors.fill:  parent
    id: playingPage;
    Knots {  id: knots }
    state:  "Default"
    color: "black"

    Video {
        id: videoPlayer
        anchors.bottom: videoControls.top;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        autoLoad: true
        playing: false
        fillMode: PreserveAspectFit;
        source: knots.currentSource
        focus: true
        Keys.onSpacePressed: video_control.paused = !video_control.paused
        Keys.onLeftPressed: video_control.position -= 5000
        Keys.onRightPressed: video_control.position += 5000

        onErrorChanged: {
            console.log( "Video Error:" + errorString)
        }
        onStatusChanged: {
            console.log( "Video status:" + status )
            if( status < 6 ){
                playing = true;
            }
        }
        onBufferProgressChanged: {
            console.log( "Buffering : " + bufferProgress )
        }
        onSourceChanged: {
            console.log( "Starting Stream @ " + source)
            playing = true;
        }

        MouseArea {
            id: videoArea
            anchors.fill: parent

        }
    }

    Mobile.VideoControls {
        id: videoControls; z: 5
        height: 40; width: parent.width; opacity: 0.9
        length: videoPlayer.duration
        position: videoPlayer.position
        onPlayClicked: {
            knots.stop();
            parent.state = "Browsing";
        }

    }

    states: [
        State {
            name: "Fullscreen"
            PropertyChanges { target: videoArea; onClicked: { playingPage.state = "Default" } }
            PropertyChanges { target: videoControls; y: screen.height; }
        },
        State {
            name: "Default"
            PropertyChanges { target: videoArea; onClicked: { playingPage.state = "Fullscreen" } }
            PropertyChanges { target: videoControls; y: screen.height - videoControls.height; }
        }

    ]
    transitions: Transition {
        PropertyAnimation { properties: "y"; duration: 200 }
    }
}
