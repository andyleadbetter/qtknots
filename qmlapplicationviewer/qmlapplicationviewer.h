// checksum 0x39ee version 0x10009
#ifndef QMLAPPLICATIONVIEWER_H
#define QMLAPPLICATIONVIEWER_H
class QGLWidget;

#include <QtDeclarative/QDeclarativeView>

class QmlApplicationViewer : public QDeclarativeView
{


public:
    enum Orientation {
        LockPortrait,
        LockLandscape,
        Auto
    };

    QmlApplicationViewer(QWidget *parent = 0, bool useOpenGL = false);

    virtual ~QmlApplicationViewer();

    void setMainQmlFile(const QString &file);
    void addImportPath(const QString &path);
    void setOrientation(Orientation orientation);
    void show();


private:

    class QmlApplicationViewerPrivate *m_d;
    QGLWidget *m_glWidget;
};

#endif // QMLAPPLICATIONVIEWER_H
