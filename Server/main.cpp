#include "qsermainwind.h"
#include <QApplication>

#include <QtCore/QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSerMainWind w;
    w.show();

    return a.exec();
}
