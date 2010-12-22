#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#if !defined( Q_OS_SYMBIAN )
    #include <QtOpenGL>
#endif

#include "qmlapplicationviewer.h"
#include "knotsplayer.h"

class     QGLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void launch();
    ~MainWindow();

    void switchViews(bool showPlayer);
    void showExpanded();
    void resizeEvent(QResizeEvent *newSize);
signals:

public slots:
    void onPlayerStateChange( KnotsPlayer::PlayingState newState );
    void onQmlFinished();

private:
    QmlApplicationViewer* _navigator;
    QmlApplicationViewer* _videoPlayer;

#if !defined( Q_OS_SYMBIAN )
    QGLWidget *_glWidget;
#endif

};

#endif // MAINWINDOW_H
