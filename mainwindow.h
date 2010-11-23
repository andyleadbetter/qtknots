#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qmlapplicationviewer.h"
#include "knotsplayer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void launch();
    ~MainWindow();

signals:

public slots:
    void onPlayerStateChange( KnotsPlayer::PlayingState newState );
    void onQmlFinished();

private:
    QmlApplicationViewer* _navigator;
    QmlApplicationViewer* _videoPlayer;

};

#endif // MAINWINDOW_H
