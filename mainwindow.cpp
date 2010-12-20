#include <qdeclarative.h>
#include <qdeclarativeengine.h>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QtGui>

#if !defined( Q_OS_SYMBIAN )
    #include <QtOpenGL>
#endif

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    #if defined( Q_WS_MAEMO_5 )
    , _glWidget(0)
    #endif

{
    resize(QSize(800,480));
}

void MainWindow::launch()
{
#if defined( Q_WS_MAEMO_5 )
    _navigator = new QmlApplicationViewer( this );
    QGLFormat format = QGLFormat::defaultFormat();
    format.setSampleBuffers(false);

    Qt::WidgetAttribute attribute = Qt::WA_Maemo5NonComposited;
    setAttribute(attribute, true);

    _glWidget = new QGLWidget(format);

    //### potentially faster, but causes junk to appear if top-level is Item, not Rectangle
    _glWidget->setAutoFillBackground(false);
    _glWidget->setAttribute(attribute, true);
    _navigator->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    _navigator->setAttribute(attribute, true);

    _navigator->setViewport(_glWidget);
#else
    _navigator = new QmlApplicationViewer( this );
#endif

    _navigator->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    _navigator->setSource(QUrl("qrc:///qml/QKnots.qml"));
    _navigator->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    _videoPlayer = new QmlApplicationViewer( this );
    _videoPlayer->setOrientation(QmlApplicationViewer::ScreenOrientationLockLandscape);
    _videoPlayer->setSource(QUrl("qrc:///qml/common/PlayingView.qml"));
    _videoPlayer->setResizeMode(QDeclarativeView::SizeRootObjectToView);


    QObject::connect(_navigator->engine(), SIGNAL(quit()), QCoreApplication::instance(),SLOT(quit()));
    connect( QCoreApplication::instance(), SIGNAL(aboutToQuit()), this, SLOT(onQmlFinished()));


    switchViews(false);
    showExpanded();

}

void MainWindow::switchViews( bool showPlayer )
{
    if( showPlayer )
    {
        _navigator->hide();
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
        showFullScreen();
        _videoPlayer->showFullScreen();
#else
        show();
        _videoPlayer->show();
#endif
    }
    else
    {
        _navigator->showExpanded();
        _videoPlayer->hide();
        showExpanded();

    }

}

void MainWindow::showExpanded()
{
#ifdef Q_OS_SYMBIAN
    showFullScreen();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
    showFullScreen();
#else
    show();
#endif
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
    delete this;
}

void MainWindow::resizeEvent(QResizeEvent *newSizeEvent)
{
    QSize newSize = newSizeEvent->size();
    qDebug() << "Width:"  << newSize.width() << "\n" << "Height:" << newSize.height();

    _videoPlayer->resize(newSize);     
    _navigator->resize(newSize);
    QMainWindow::resizeEvent(newSizeEvent);
}
