#include <qdeclarative.h>
#include <QMainWindow>
#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setGeometry(QRect(QPoint(0,0),QSize(800,480)));
}

void MainWindow::launch()
{
#if defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6) || defined( Q_OS_SYMBIAN )
    _navigator = new QmlApplicationViewer( this, true );
#else
    _navigator = new QmlApplicationViewer( this, false );
#endif
    _navigator->setOrientation(QmlApplicationViewer::Auto);
    _navigator->setMainQmlFile("qrc:///qml/QKnots.qml");
    _navigator->show();

    _videoPlayer = new QmlApplicationViewer( this, false);
    _videoPlayer->setOrientation(QmlApplicationViewer::Auto);
    _videoPlayer->setMainQmlFile("qrc:///qml/common/PlayingView.qml");
    _videoPlayer->hide();

    connect( _navigator, SIGNAL(destroyed()), this, SLOT(onQmlFinished()));

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6) || defined( Q_OS_SYMBIAN )
    showFullScreen();
#else
    show();
#endif
}

void MainWindow::onPlayerStateChange( KnotsPlayer::PlayingState newState )
{
    if( KnotsPlayer::Playing == newState )
    {
        _videoPlayer->show();
        _navigator->hide();
    } else {
        _videoPlayer->hide();
        _navigator->show();
    }
}

MainWindow::~MainWindow()
{
    delete _videoPlayer;
    delete _navigator;
}

void MainWindow::onQmlFinished()
{
    close();
}
