#include <QtGui/QApplication>
#include "knots.h"
#include "knotsdeclarative.h"
#include <qdeclarative.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Knots::instance();

    qmlRegisterType<KnotsDeclarative>("Knots", 1, 0, "Knots");

    qmlRegisterType<ProfileList>("ProfilesList", 1, 0,"ProfilesList");

    qmlRegisterType<KnotsDirectory>("KnotsDirectory", 1, 0,"KnotsDirectory");

    Knots::instance().launch();

    return app.exec();
}
