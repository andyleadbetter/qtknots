#include <qdeclarative.h>
#include <QtGui/QApplication>

#include "knots.h"
#include "knotsdirectory.h"
#include "knotsdeclarative.h"
#include "models/qrangemodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setGraphicsSystem("raster");

    Knots::instance();

    qmlRegisterType<KnotsDeclarative>("Knots", 1, 0, "Knots");

    qmlRegisterType<ProfileList>("ProfilesList", 1, 0,"ProfilesList");

    qmlRegisterType<KnotsDirectory>("KnotsDirectory", 1, 0,"KnotsDirectory");

    qmlRegisterType<KnotsPlayer>("KnotsPlayer", 1, 0,"KnotsPlayer");


    qmlRegisterType<QRangeModel>("Qt.labs.components", 1, 0, "RangeModel");


    Knots::instance().launch();

    return app.exec();
}
