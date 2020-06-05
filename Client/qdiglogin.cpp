#include "qdiglogin.h"
#include "ui_qdiglogin.h"

QDigLogin::QDigLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDigLogin)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::SplashScreen);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    //this->setWindowFlags(Qt::WindowCloseButtonHint);
}

QDigLogin::~QDigLogin()
{
    delete ui;
}

void QDigLogin::on_LogInButton_clicked()
{
    m_username=ui->UserNameEdit->text().trimmed();
    this->accept();
}

QString QDigLogin::GetUsername()
{
    return m_username;
}
