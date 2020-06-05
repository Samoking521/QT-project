#ifndef QDIGLOGIN_H
#define QDIGLOGIN_H

#include <QDialog>

namespace Ui {
class QDigLogin;
}

class QDigLogin : public QDialog
{
    Q_OBJECT
private:
    //bool m_moving=false;                        //表示窗口是否在鼠标操作下移动
    //QPoint m_lastPos;                           //上一次的鼠标位置
    QString m_username;                         //用户名
    //void readSettings();                        //读取设置，注册表
    //void writeSettings();                       //写入设置，注册表

public:
    QString GetUsername();
    explicit QDigLogin(QWidget *parent = 0);
    ~QDigLogin();

private slots:
    void on_LogInButton_clicked();

private:
    Ui::QDigLogin *ui;
};

#endif // QDIGLOGIN_H
