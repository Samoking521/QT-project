#include "qclimainwind.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCliMainWind w;
    w.show();

    return a.exec();
}
