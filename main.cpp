#include <QtGui/QApplication>
#include "knots.h"
#include "knotsdirectory.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Knots::instance();

    return app.exec();
}
