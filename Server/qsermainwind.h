#ifndef QSERMAINWIND_H
#define QSERMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QList>
#include <QMap>
//#include <QtGlobal>
#include <QtNetwork>
#include <QDebug>

namespace Ui {
class QSerMainWind;
}

class QSerMainWind : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *LabListen;                                  //状态栏标签
    QLabel *LabSocketState;                             //状态栏标签
    QTcpServer *tcpServer;                              //TCP服务器
    QVector<QTcpSocket*> m_tcpSocket;                   //TCP通信的Socket
    QMap<QTcpSocket*,QString> SocketName;               //Socket和用户名的对应
    QString getLocalIP();                               //获取本机IP地址
    QString m_sender;                                   //发送对象
    QString m_receiver;                                 //接收对象

protected:
    //void closeEvent(QCloseEvent *event);

public:
    explicit QSerMainWind(QWidget *parent = 0);
    ~QSerMainWind();

private slots:
    void onNewConnection();                                                 //QTcpServer的NewConnection信号
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    //void onClientConnected();                                               //Client Socket connected
    void onClientDisconnected();                                            //Client Socket disconnected
    void onSocketReadyRead();                                               //读取socket传入的数据

    void on_actStopListen_triggered();

    void on_actBeginListen_triggered();

    void on_SendMessageButton_clicked();

private:
    Ui::QSerMainWind *ui;
};

#endif // QSERMAINWIND_H
