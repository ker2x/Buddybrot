#include "buddybrot.h"
#include <QApplication>


/* nothing here */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Buddybrot window;
    window.show();

    return app.exec();
}
