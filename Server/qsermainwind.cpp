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
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP+"----当前用户：admin");
    ui->IPcomboBox->addItem(localIP);
    tcpServer=new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));    //有客户端连接到服务器时
}

QSerMainWind::~QSerMainWind()
{
    delete ui;
}

void QSerMainWind::onNewConnection()
{
    QTcpSocket* tcpSocket=tcpServer->nextPendingConnection();                   //返回服务器下一个已申请建立连接，但还未处理的socket
    m_tcpSocket.push_back(tcpSocket);
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onClientDisconnected()));
    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(tcpSocket->state());
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));

    ui->StateText->appendPlainText("**client socket connected");
    ui->StateText->appendPlainText("**peer address:"+tcpSocket->peerAddress().toString());
    ui->StateText->appendPlainText("**peer port:"+QString::number(tcpSocket->peerPort()));
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

void QSerMainWind::onClientDisconnected()
{
    QTcpSocket* tcpSocket = qobject_cast<QTcpSocket*>(QObject::sender());
    ui->StateText->appendPlainText("**client socket disconnected");
    tcpSocket->deleteLater();
}

void QSerMainWind::onSocketReadyRead()
{
    QTcpSocket* tcpSocket = qobject_cast<QTcpSocket*>(QObject::sender());
    QString msg=tcpSocket->readAll();
    qDebug()<<msg;
    msg.remove(0,1);                                                    //获取用户名
    int index=msg.indexOf('$');
    if(index>-1){
        m_receiver=msg.mid(0,index);
        qDebug()<<m_receiver;
        msg.remove(0,index+1);
        qDebug()<<msg;
        QString name=SocketName[tcpSocket];
        if(m_receiver=="admin"){
            ui->MessageBrowser->appendPlainText("["+name+"] "+msg);
        }
        else{
            QString msg1="$"+name+"$";
            ui->MessageBrowser->appendPlainText("["+name+"] to ["+m_receiver+"] "+msg);
            msg=msg1+msg;
            for(int i=0;i<m_tcpSocket.size(); i++){                     //完成数据的转发
                if(SocketName[m_tcpSocket[i]]==m_receiver){
                    m_tcpSocket[i]->write(msg.toUtf8());
                    break;
                }
            }
        }
    }
    else{
        SocketName[tcpSocket]=msg.trimmed();
        QListWidgetItem* aItem=new QListWidgetItem(SocketName[tcpSocket]);
        aItem->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        qDebug()<<ui->MemberView->currentRow();
        ui->MemberView->insertItem(ui->MemberView->currentRow()+1,aItem);
        ui->MemberView->setCurrentRow(ui->MemberView->currentRow()+1,QItemSelectionModel::Select);
        qDebug()<<ui->MemberView->currentRow();
    }
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
    tcpServer->listen(addr,port);                                      //对指定的IP地址和端口进行监听
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
    ui->MessageBrowser->appendPlainText("[admin] "+msg);
    ui->MessageEdit->clear();
    ui->MessageEdit->setFocus();

    QString msg1="$admin$";
    msg=msg1+msg;
    QByteArray str=msg.toUtf8();
    //str.append('\n');
    if(m_tcpSocket.size()>0){
        for(int i=0;i<m_tcpSocket.size(); i++){
            m_tcpSocket[i]->write(str);
        }
    }
}
