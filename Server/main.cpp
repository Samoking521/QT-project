#include "qsermainwind.h"
#include <QApplication>

#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSerMainWind w;
    w.show();

    return a.exec();
}
