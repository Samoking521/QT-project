#include "qsermainwind.h"
#include "ui_qsermainwind.h"

QString QSerMainWind::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();                        //获取本地主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);                   //根据主机名获取IP地址
    QString localIP="";
    QList<QHostAddress> addList=hostInfo.addresses();                   //返回IP地址列表

    if(!addList.isEmpty())
        for(int i=0;i<addList.count();i++){
            QHostAddress aHost=addList.at(i);
            if(QAbstractSocket::IPv4Protocol==aHost.protocol()){        //获取第一个IPV4的IP地址
                localIP=aHost.toString();
                break;
            }
        }
    return localIP;
}

QSerMainWind::QSerMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QSerMainWind)
{
    ui->setupUi(this);

    LabListen=new QLabel("监听状态：");
    LabListen->setMinimumWidth(150);
    ui->statusBar->addWidget(LabListen);

    LabSocketState=new QLabel("Socket状态：");
    LabSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(LabSocketState);

    QString localIP=getLocalIP();
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->IPcomboBox->addItem(localIP);
    tcpServer=new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

QSerMainWind::~QSerMainWind()
{
    delete ui;
}

void QSerMainWind::onNewConnection()
{
    tcpSocket=tcpServer->nextPendingConnection();
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(onClientConnected()));
    onClientConnected();
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onClientDisconnected()));
    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(tcpSocket->state());
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}

void QSerMainWind::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("socket状态：UnconnectedState");   break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("socket状态：HostLookupState");   break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("socket状态：ConnectingState");   break;
    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("socket状态：ConnectedState");   break;
    case QAbstractSocket::BoundState:
        LabSocketState->setText("socket状态：BoundState");   break;
    case QAbstractSocket::ClosingState:
        LabSocketState->setText("socket状态：ClosingState");   break;
    case QAbstractSocket::ListeningState:
        LabSocketState->setText("socket状态：ListeningState");   break;
    }
}

void QSerMainWind::onClientConnected()
{
    ui->StateText->appendPlainText("**client socket connected");
    ui->StateText->appendPlainText("**peer address:"+tcpSocket->peerAddress().toString());
    ui->StateText->appendPlainText("**peer port:"+QString::number(tcpSocket->peerPort()));
}

void QSerMainWind::onClientDisconnected()
{
    ui->StateText->appendPlainText("**client socket disconnected");
    tcpSocket->deleteLater();
}

void QSerMainWind::onSocketReadyRead()
{
    while(tcpSocket->canReadLine())
        ui->MessageBrowser->appendPlainText("[in] "+tcpSocket->readLine());
}

void QSerMainWind::on_actStopListen_triggered()
{
    if(tcpServer->isListening()){
        tcpServer->close();
        ui->actBeginListen->setEnabled(true);
        ui->actStopListen->setEnabled(false);
        LabListen->setText("监听状态：已停止监听");
    }
}

void QSerMainWind::on_actBeginListen_triggered()
{
    QString IP=ui->IPcomboBox->currentText();
    quint16 port=ui->PortspinBox->value();
    QHostAddress addr(IP);
    tcpServer->listen(addr,port);
    ui->StateText->appendPlainText("**开始监听...");
    ui->StateText->appendPlainText("**服务器地址："+tcpServer->serverAddress().toString());
    ui->StateText->appendPlainText("**服务器端口："+QString::number(tcpServer->serverPort()));
    ui->actBeginListen->setEnabled(false);
    ui->actStopListen->setEnabled(true);
    LabListen->setText("监听状态：正在监听");
}

void QSerMainWind::on_SendMessageButton_clicked()
{
    QString msg=ui->MessageEdit->text();
    ui->MessageBrowser->appendPlainText("[out] "+msg);
    ui->MessageEdit->clear();
    ui->MessageEdit->setFocus();

    QByteArray str=msg.toUtf8();
    str.append('\n');
    tcpSocket->write(str);
}
