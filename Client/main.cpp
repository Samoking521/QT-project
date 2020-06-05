#include "qclimainwind.h"
#include "qdiglogin.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDigLogin *dlgLogin=new QDigLogin;
    if(dlgLogin->exec()==QDialog::Accepted){
        QCliMainWind w;
        w.SetUsername(dlgLogin->GetUsername());
        QString title=w.windowTitle();
        w.setWindowTitle(title+dlgLogin->GetUsername());
        w.show();
        return a.exec();
    }
    else
        return 0;
}
