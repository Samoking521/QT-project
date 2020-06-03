#ifndef QCLIMAINWIND_H
#define QCLIMAINWIND_H

#include <QMainWindow>
#include <QtNetwork>
#include <QLabel>

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

protected:
    //void closeEvent(QCloseEvent *event());

public:
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
    
private:
    Ui::QCliMainWind *ui;
};

#endif // QCLIMAINWIND_H
