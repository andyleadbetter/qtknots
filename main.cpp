#include <QtGui/QApplication>
#include <qdeclarative.h>
#include "qmlapplicationviewer.h"
#include "knots.h"
#include "knotsdeclarative.h"
#include "knotsdirectory.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Knots& knots = Knots::instance();

    app.addLibraryPath("/usr/lib/qt4/imports");




    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::Auto);

    qmlRegisterType<KnotsDeclarative>("Knots", 1, 0, "Knots");

    qmlRegisterType<ProfileList>("ProfilesList", 1, 0,"ProfilesList");

    qmlRegisterType<KnotsDirectory>("KnotsDirectory", 1, 0,"KnotsDirectory");


    viewer.setMainQmlFile("qrc:///qml/QKnots.qml");
    viewer.show();

    return app.exec();
}
