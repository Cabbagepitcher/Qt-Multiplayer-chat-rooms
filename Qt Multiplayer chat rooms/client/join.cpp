#include "join.h"
#include "ui_join.h"
QString lineEditStylejoin =
    " QLineEdit {"
    "   background-color: #ffffff;"
    "   border: 1px solid #c4c4c3;"
    "   padding: 3px;"
    "   font-size: 24px;"
    "   color: #333333;"
    "   border-radius: 4px;"
    "   transition: border-color 0.2s ease-in-out;"
    "}"
    "QLineEdit:hover {"
    "   border-color: #6ca0d1;"
    "}"
    "QLineEdit:focus {"
    "   border-color: #3d84b6;"
    "   outline: none;"
    "   box-shadow: inset 0 0 2px #3d84b6, 0 0 8px rgba(61, 132, 182, 0.5);"
    "}"
    "QLineEdit[invalid=true] {"
    "   border-color: #ff4d4d;"
    "}";
QString spinBoxStyle1 =
    "QSpinBox {"
    "   border: 1px solid #dadbde;"
    "   border-radius: 5px;"
    "   padding: 1px 3px 1px 3px;"
    "   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
    "                               stop: 0 #f0f0f0, stop: 1 #e5e5e5);"
    "   color: #000;"
    "   selection-background-color: darkblue;"
    "   selection-color: white;"
    "}"
    "QSpinBox::up-button {"
    "   subcontrol-origin: border;"
    "   subcontrol-position: top right;"
    "   width: 16px;"
    "   border-left-width: 1px;"
    "   border-top-right-radius: 4px;"
    "   border-bottom-right-radius: 0;"
    "   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
    "                               stop: 0 #e5e5e5, stop: 1 #dadbde);"
    "}"
    "QSpinBox::down-button {"
    "   subcontrol-origin: border;"
    "   subcontrol-position: bottom right;"
    "   width: 16px;"
    "   border-left-width: 1px;"
    "   border-top-right-radius: 0;"
    "   border-bottom-right-radius: 4px;"
    "   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
    "                               stop: 0 #dadbde, stop: 1 #c2c2c2);"
    "}"
    "QSpinBox::up-arrow {"
    "   image: url(:/uparrow.png);"
    "}"
    "QSpinBox::down-arrow {"
    "   image: url(:/downarrow.png);"
    "}";
QString progressBarStyle =

    "QProgressBar {"
    "   border: 2px solid grey;"
    "   border-radius: 5px;"
    "   text-align: center;"
    "   color: white;"
    "   background-color: #444;"
    "}"
    "QProgressBar::chunk {"
    "   background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
    "                                     stop: 0 #05B8CC, stop: 1 #EAF79A);"
    "   width: 10px;"
    "   margin: 0.5px;"
    "}";
join::join(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::join)
{
    ui->setupUi(this);
    ui->pushButtonConnect->setStyleSheet(DarkButton_STYTLE);
    ui->spinBoxPort->setStyleSheet(spinBoxStyle1);
    ui->lineEditIP->setStyleSheet(lineEditStylejoin);
    ui->lineEditNickname->setStyleSheet(lineEditStylejoin);
    ui->progressBar->setStyleSheet(progressBarStyle);
    mydlog=NULL;

    timer = new QTimer(this);
    timer->setInterval(50);//五秒延时间隔,50毫秒一个1%
    time_spent=0;
    timer->setSingleShot(false);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));

    socket = new QTcpSocket(this);

    connect(ui->pushButtonConnect,SIGNAL(clicked()),this,SLOT(btnConnectClickedSlot()));
    connect(socket,SIGNAL(connected()),this,SLOT(connectSlot()));
}

join::~join()
{
    qDebug()<<"join析构函数";

    if(mydlog!=NULL)
        delete mydlog;

    delete ui;
}

void join::btnConnectClickedSlot()
{
    QString ip = ui->lineEditIP->text();
    int port = ui->spinBoxPort->value();
    QString name = ui->lineEditNickname->text();
    if(ip=="")
    {
        //hide();
        //show();
        QMessageBox::warning(this,"提示","服务器IP不能为空！");
        return ;
    }
    if(port>49151)
    {
        //hide();
        //show();
        QMessageBox::warning(this,"提示","请输入正确的端口号\n范围：5000-49151");
        return ;
    }
    if(name =="")
    {
        //hide();
        //show();
        QMessageBox::warning(this,"提示","昵称不能为空！");
        return ;
    }
    qDebug()<<"连接:";
    qDebug()<<"ip:"<<ip;
    qDebug()<<"port:"<<port;

    socket->connectToHost(ip,port);
    if(!timer->isActive())
    {
        timer->start();
    }
    ui->pushButtonConnect->setEnabled(false);
    ui->pushButtonConnect->setText("连接中");
}

void join::connectSlot()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));
}

void join::timeoutSlot()
{
    if(time_spent!=100)
    {
        time_spent++;
        ui->progressBar->setValue(time_spent);
        timer->start();
    }
    else
    {
        ui->pushButtonConnect->setText("加入群聊");
        ui->pushButtonConnect->setEnabled(true);

        hide();
        show();
        QMessageBox::critical(this,"加入群聊失败","链接服务器超时");
        timer->stop();

        time_spent=0;
        ui->progressBar->setValue(time_spent);
    }
}

void join::readyReadSlot()
{
    QByteArray buffer = socket->readAll();
    QString text(buffer);
    if(text=="OK")
    {
        timer->stop();
        ui->progressBar->setValue(100);

        ui->pushButtonConnect->setText("连接成功");

        //hide();
        //show();
        QMessageBox::information(this,"提示","成功加入群聊");

        time_spent=0;
        ui->progressBar->setValue(time_spent);

        QString joinText;
        joinText.append("join:").append(ui->lineEditNickname->text());

        socket->write(joinText.toUtf8());

        mydlog = new MYDialog(socket,ui->lineEditNickname->text(),this);//0

        int x=this->x()+this->width()/2;
        int y=this->y()+this->height()/2;
        mydlog->move(x-mydlog->width()/2,y-mydlog->height()/2);
        mydlog->show();

        hide();
        //    close();
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));
        return ;
    }
    else if(text=="err:群聊已满")
    {
        timer->stop();
        ui->progressBar->setValue(100);
        time_spent=0;

        //hide();
        //show();
        QMessageBox::warning(this,"提示","群聊已满，请稍后重试！");

        time_spent=0;
        ui->progressBar->setValue(time_spent);

        ui->pushButtonConnect->setText("加入群聊");
        ui->pushButtonConnect->setEnabled(true);
        return ;
    }
}
