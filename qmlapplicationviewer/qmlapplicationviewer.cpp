// checksum 0x4534 version 0x10009
#include "qmlapplicationviewer.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtDeclarative/QDeclarativeComponent>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeContext>
#include <QtOpenGL/QGLWidget>

#if defined(QMLJSDEBUGGER) && !defined(NO_JSDEBUGGER)
#include <jsdebuggeragent.h>
#endif
#if defined(QMLJSDEBUGGER) && !defined(NO_QMLOBSERVER)
#include <qdeclarativeviewobserver.h>
#endif

#if defined(Q_OS_SYMBIAN) && defined(ORIENTATIONLOCK)
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#endif // Q_OS_SYMBIAN && ORIENTATIONLOCK

class QmlApplicationViewerPrivate
{
    QString mainQmlFile;
    friend class QmlApplicationViewer;
    static QString adjustPath(const QString &path);
};

QString QmlApplicationViewerPrivate::adjustPath(const QString &path)
{
#ifdef Q_OS_UNIX
#ifdef Q_OS_MAC
    if (!QDir::isAbsolutePath(path))
        return QCoreApplication::applicationDirPath()
                + QLatin1String("/../Resources/") + path;
#else
    const QString pathInShareDir = QCoreApplication::applicationDirPath()
        + QLatin1String("/../share/")
        + QFileInfo(QCoreApplication::applicationFilePath()).fileName()
        + QLatin1Char('/') + path;
    if (QFileInfo(pathInShareDir).exists())
        return pathInShareDir;
#endif
#endif
    return path;
}

QmlApplicationViewer::QmlApplicationViewer(QWidget *parent, bool useOpenGL ) :
    QDeclarativeView(parent),
    m_d(new QmlApplicationViewerPrivate)
{
    // Set optimizations not already done in QDeclarativeView
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground); // Make QDeclarativeView use OpenGL backend

    if( useOpenGL )
    {
        QGLWidget *glWidget = new QGLWidget(this);
        glWidget->setAutoFillBackground(false);
        setViewport(glWidget);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        QGLFormat format = QGLFormat::defaultFormat();
        format.setSampleBuffers(false);
    }

    connect(engine(), SIGNAL(quit()), SLOT(close()));
    setResizeMode(QDeclarativeView::SizeRootObjectToView);
#if defined(QMLJSDEBUGGER) && !defined(NO_JSDEBUGGER)
    new QmlJSDebugger::JSDebuggerAgent(engine());
#endif
#if defined(QMLJSDEBUGGER) && !defined(NO_QMLOBSERVER)
    new QmlJSDebugger::QDeclarativeViewObserver(this, parent);
#endif
}

QmlApplicationViewer::~QmlApplicationViewer()
{
    delete m_d;
}

void QmlApplicationViewer::setMainQmlFile(const QString &file)
{
    m_d->mainQmlFile = QmlApplicationViewerPrivate::adjustPath(file);
    setSource(m_d->mainQmlFile);
}

void QmlApplicationViewer::addImportPath(const QString &path)
{
    engine()->addImportPath(QmlApplicationViewerPrivate::adjustPath(path));
}

void QmlApplicationViewer::setOrientation(Orientation orientation)
{
#ifdef Q_OS_SYMBIAN
    if (orientation != Auto) {
#if defined(ORIENTATIONLOCK)
        const CAknAppUiBase::TAppUiOrientation uiOrientation =
                (orientation == LockPortrait) ? CAknAppUi::EAppUiOrientationPortrait
                    : CAknAppUi::EAppUiOrientationLandscape;
        CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
        TRAPD(error,
            if (appUi)
                appUi->SetOrientationL(uiOrientation);
        );
#else // ORIENTATIONLOCK
        qWarning("'ORIENTATIONLOCK' needs to be defined on Symbian when locking the orientation.");
#endif // ORIENTATIONLOCK
    }
#elif defined(Q_WS_MAEMO_5)
    Qt::WidgetAttribute attribute;
    switch (orientation) {
    case LockPortrait:
        attribute = Qt::WA_Maemo5PortraitOrientation;
        break;
    case LockLandscape:
        attribute = Qt::WA_Maemo5LandscapeOrientation;
        break;
    case Auto:
    default:
        attribute = Qt::WA_Maemo5AutoOrientation;
        break;
    }
    setAttribute(attribute, true);
#else // Q_OS_SYMBIAN
    Q_UNUSED(orientation);
#endif // Q_OS_SYMBIAN
}

void QmlApplicationViewer::show()
{
#ifdef Q_OS_SYMBIAN
    showFullScreen();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
    showFullScreen();
#else
    QDeclarativeView::show();
#endif
}
