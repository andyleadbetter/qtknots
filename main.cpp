#include <qdeclarative.h>
#include <QtGui/QApplication>

#include "knots.h"
#include "knotsdirectory.h"
#include "knotsdeclarative.h"
#include "models/qrangemodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Knots::instance();

    qmlRegisterType<KnotsDeclarative>("Knots", 1, 0, "Knots");

    qmlRegisterType<ProfileList>("ProfilesList", 1, 0,"ProfilesList");

    qmlRegisterType<KnotsDirectory>("KnotsDirectory", 1, 0,"KnotsDirectory");

    qmlRegisterType<KnotsPlayer>("KnotsPlayer", 1, 0,"KnotsPlayer");

    qmlRegisterType<QRangeModel>("RangeModel", 1, 0, "RangeModel");

    Knots::instance().launch();

    return app.exec();
}
