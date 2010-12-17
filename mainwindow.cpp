#include <qdeclarative.h>
#include <qdeclarativeengine.h>
#include <QMainWindow>
#include <QVBoxLayout>

#if !defined( Q_OS_SYMBIAN )
#include <QtOpenGL/QGLWidget>
#endif


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setGeometry(QRect(QPoint(0,0),QSize(800,480)));
}

void MainWindow::launch()
{
#if !defined( Q_OS_SYMBIAN )

     QGLWidget *glWidget = new QGLWidget(this);
     glWidget->setAutoFillBackground(false);
     glWidget->setGeometry(QRect(QPoint(0,0),QSize(800,480)));
     QGLFormat format = QGLFormat::defaultFormat();
     format.setSampleBuffers(false);

     _navigator = new QmlApplicationViewer( glWidget );



#else
    _navigator = new QmlApplicationViewer( this );
#endif
    _navigator->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    _navigator->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    _navigator->setSource(QUrl("qrc:///qml/QKnots.qml"));




    _videoPlayer = new QmlApplicationViewer( this );
    _videoPlayer->setOrientation(QmlApplicationViewer::ScreenOrientationLockLandscape);
    _videoPlayer->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    _videoPlayer->setSource(QUrl("qrc:///qml/common/PlayingView.qml"));

     QObject::connect(_navigator->engine(), SIGNAL(quit()), QCoreApplication::instance(),SLOT(quit()));


    switchViews(false);

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6) || defined( Q_OS_SYMBIAN )
    showFullScreen();
#else
    show();
#endif
}

void MainWindow::switchViews( bool showPlayer )
{
    if( showPlayer )
    {
        _navigator->hide();
        _videoPlayer->showExpanded();
    }
    else
    {
        _navigator->showExpanded();
        _videoPlayer->hide();
    }

}

void MainWindow::onPlayerStateChange( KnotsPlayer::PlayingState newState )
{
    switchViews(KnotsPlayer::Playing == newState );
}

MainWindow::~MainWindow()
{
    delete _videoPlayer;
    delete _navigator;
}

void MainWindow::onQmlFinished()
{    
    _navigator->close();
    _videoPlayer->close();
    close();
}
