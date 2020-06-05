#ifndef QCLIMAINWIND_H
#define QCLIMAINWIND_H

#include <QMainWindow>
#include <QtNetwork>
#include <QLabel>
#include <QListWidgetItem>

namespace Ui {
class QCliMainWind;
}

class QCliMainWind : public QMainWindow
{
    Q_OBJECT
private:
    QTcpSocket *tcpClient;
    QLabel *LabSocketState;                     //状态栏显示标签
    QString getLocalIP();                       //获取本机IP地址
    QString m_username;                         //用户名
    QString m_sender;                         //发送对象
    QString m_receiver;                         //接收对象

protected:
    //void closeEvent(QCloseEvent *event());

public:
    void SetUsername(QString str);
    explicit QCliMainWind(QWidget *parent = 0);
    ~QCliMainWind();

private slots:
    void onConnected();
    void onDisconnected();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onSocketReadyRead();                   //读取socket传入的数据

    void on_actConnect_triggered();
    
    void on_actDisconnect_triggered();
    
    void on_SendMessageButton_clicked();
    
    void on_AddMemberButton_clicked();

    void on_DelMemberButton_clicked();

    void on_MemberView_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_MemberView_itemChanged(QListWidgetItem *item);

private:
    Ui::QCliMainWind *ui;
};

#endif // QCLIMAINWIND_H
