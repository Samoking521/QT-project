#include "qclimainwind.h"
#include "ui_qclimainwind.h"

QString QCliMainWind::getLocalIP()
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

QCliMainWind::QCliMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCliMainWind)
{
    ui->setupUi(this);

    tcpClient=new QTcpSocket(this);

    LabSocketState=new QLabel("Socket状态：");
    LabSocketState->setMinimumWidth(250);
    ui->statusBar->addWidget(LabSocketState);

    QString localIP=getLocalIP();
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP+"----当前用户：");
    ui->IPcomboBox->addItem(localIP);

    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));

    //m_receiver="admin";
    //qDebug()<<m_receiver;
    QListWidgetItem* aItem=ui->MemberView->item(0);
    m_receiver=aItem->text();
    //qDebug()<<m_receiver;
    //aItem->setForeground(QColor(255,0,0));
    ui->MemberView->setCurrentRow(0,QItemSelectionModel::Select);
    //qDebug()<<ui->MemberView->currentItem();
}

QCliMainWind::~QCliMainWind()
{
    delete ui;
}

void QCliMainWind::onConnected()
{
    QString msg="$";
    msg+=m_username;                                         //建立连接时发送当前用户名
    QByteArray str=msg.toUtf8();
    //str.append('\n');
    tcpClient->write(str);

    ui->StateText->appendPlainText("**已连接到服务器");
    ui->StateText->appendPlainText("**peer address:"+tcpClient->peerAddress().toString());
    ui->StateText->appendPlainText("**peer port:"+QString::number(tcpClient->peerPort()));
    ui->actConnect->setEnabled(false);
    ui->actDisconnect->setEnabled(true);
}

void QCliMainWind::onDisconnected()
{
    ui->StateText->appendPlainText("**已断开与服务器的连接");
    ui->actConnect->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
}

void QCliMainWind::onSocketStateChange(QAbstractSocket::SocketState socketState)
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

void QCliMainWind::onSocketReadyRead()
{
    //while(tcpClient->canReadLine())
    //ui->MessageBrowser->appendPlainText("[in] "+tcpClient->readAll());

    QString msg=tcpClient->readAll();
    qDebug()<<msg;
    msg.remove(0,1);                                                    //获取用户名
    int index=msg.indexOf('$');
    m_sender=msg.mid(0,index);
    qDebug()<<m_sender;
    msg.remove(0,index+1);
    qDebug()<<msg;
    ui->MessageBrowser->appendPlainText("["+m_sender+"] "+msg);
}

void QCliMainWind::on_actConnect_triggered()
{
    QString addr=ui->IPcomboBox->currentText();
    quint16 port=ui->PortspinBox->value();
    tcpClient->connectToHost(addr,port);                               //根据服务器地址和端口连接到服务器
}

void QCliMainWind::on_actDisconnect_triggered()
{
    if(tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}

void QCliMainWind::on_SendMessageButton_clicked()
{
    QString msg1="$"+m_receiver+"$";
    QString msg2=ui->MessageEdit->text();
    //qDebug()<<msg;
    ui->MessageBrowser->appendPlainText("["+m_username+"] "+msg2);
    ui->MessageEdit->clear();
    ui->MessageEdit->setFocus();

    QString msg=msg1+msg2;
    QByteArray str;
    str=msg.toUtf8();
    //str.append('\n');
    tcpClient->write(str);
}

void QCliMainWind::SetUsername(QString str)
{
    m_username=str;
}

void QCliMainWind::on_AddMemberButton_clicked()
{
    QListWidgetItem* aItem=new QListWidgetItem("New Inserted Item");
    aItem->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    ui->MemberView->insertItem(ui->MemberView->currentRow()+1,aItem);
}

void QCliMainWind::on_DelMemberButton_clicked()
{
    int row=ui->MemberView->currentRow();
    if(ui->MemberView->currentItem()->text()=="admin")
        return;
    QListWidgetItem* aItem=ui->MemberView->takeItem(row);
    delete aItem;
}

void QCliMainWind::on_MemberView_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if(current!=NULL){
        if(previous!=NULL){
            previous->setForeground(Qt::black);
            previous->setSelected(false);
            current->setForeground(QColor(0,170,255));
            current->setSelected(true);
            m_receiver=current->text();
        }
    }
}

void QCliMainWind::on_MemberView_itemChanged(QListWidgetItem *item)
{
    m_receiver=item->text();
    //qDebug()<<m_receiver;
}
