#include "dialog.h"
#include "ui_dialog.h"
#include "qss.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButtonLongin->setStyleSheet(DarkButton_STYTLE);
    ui->pushButtonLongin_2->setStyleSheet(DarkButton_STYTLE);
    ui->lineEdit->setStyleSheet(lineEditStyle);
    ui->lineEdit_2->setStyleSheet(lineEditStyle);

    socket = new QTcpSocket(this);

    connect(ui->pushButtonLongin,SIGNAL(clicked()),this,SLOT(btnClickedSlot()));
    connect(ui->pushButtonLongin_2,SIGNAL(clicked()),this,SLOT(btnClickedSlot()));
    connect(socket,SIGNAL(connected()),this,SLOT(connectSlot()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readReadSlot()));
}

Dialog::~Dialog()
{
    qDebug()<<"dialog析构函数";
    delete ui;
}

void Dialog::btnClickedSlot()
{
    if(sender()==ui->pushButtonLongin)
        state =1;
    if(sender()==ui->pushButtonLongin_2)
        state =2;
    qDebug()<<"登录,连接服务器交互，端口固定8888，本机IP";
    if(ui->lineEdit->text()=="")
    {
        hide();
        show();
        QMessageBox::warning(this,"警告","请输入用户名");
        return ;
    }
    else if(ui->lineEdit_2->text()=="")
    {
        hide();
        show();
        QMessageBox::warning(this,"警告","请输入密码");
        return ;
    }
    socket->connectToHost(getLocalIP(),8888);
    //    socket->connectToHost("192.168.50.245",8888);
}

void Dialog::connectSlot()
{
    if(state==1)
    {
        qDebug()<<"已发送登录消息";
        QString shendText = "login:";
        shendText.append(ui->lineEdit->text());
        shendText.append(":");
        shendText.append(ui->lineEdit_2->text());
        socket->write(shendText.toUtf8());
    }
    else if(state ==2)
    {
        qDebug()<<"已发送注册消息";
        QString shendText = "register:";
        shendText.append(ui->lineEdit->text());
        shendText.append(":");
        shendText.append(ui->lineEdit_2->text());
        socket->write(shendText.toUtf8());
    }
}

void Dialog::readReadSlot()
{
    QByteArray buffer = socket->readAll();
    QString text(buffer);
    if(state==1)
    {
        qDebug()<<"收到服务器回信"<<text;
        if(text=="adopt")
        {
            joinBox = new join(this);

            int x=this->x()+this->width()/2;
            int y=this->y()+this->height()/2;
            joinBox->move(x-joinBox->width()/2,y-joinBox->height()/2);
            joinBox->show();

            hide();
            //    close();
        }
        else if(text=="password err")
        {
            //hide();
            //show();
            socket->close();
            QMessageBox::critical(this,"错误","密码错误");
            return ;
        }
        else if(text=="not find")
        {
            //hide();
            //show();
            socket->close();
            QMessageBox::warning(this,"警告","无此用户，请先注册");
            return ;
        }
    }
    else if(state ==2)
    {
        if(text=="finish")
        {
            //hide();
            //show();
            socket->close();
            QMessageBox::information(this,"提示","注册成功");
            return ;
        }
        else if(text=="err")
        {
            //hide();
            //show();
            socket->close();
            QMessageBox::critical(this,"错误","注册失败");
            return ;
        }
    }
}

QString Dialog::getLocalIP()
{
    QString localIP;
    // 获取本地主机名
    QHostInfo hostInfo = QHostInfo::fromName(QHostInfo::localHostName());

    // 获取本地主机的IP地址列表
    QList<QHostAddress> ipAddresses = hostInfo.addresses();

    // 遍历IP地址列表，找到IPv4地址
    for (const QHostAddress &ipAddress : ipAddresses)
    {
        if (ipAddress.protocol() == QAbstractSocket::IPv4Protocol)
        {
            localIP = ipAddress.toString ();
            break;
        }
    }
    qDebug()<<localIP;
    return localIP;
}
