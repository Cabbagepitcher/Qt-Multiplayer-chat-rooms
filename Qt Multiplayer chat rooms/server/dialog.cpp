#include<QDebug>
#include "dialog.h"
#include "ui_dialog.h"
QString  styleSheet1 =
    "QTextBrowser {"
    "   border: 2px solid #4CAF50; /* 设置边框样式，颜色和宽度 */"
    "   border-radius: 10px; /* 设置边框圆角半径 */"
    "   padding: 10px; /* 内边距，使内容与边框保持一定距离 */"
    "   background-color: #f5f5f5; /* 背景颜色 */"
    "   color: #333333; /* 文本颜色 */"
    "   selection-background-color: #4CAF50; /* 选中文本的背景颜色 */"
    "   selection-color: white; /* 选中文本的颜色 */"
    "   outline: none; /* 去除轮廓线 */"
    "   box-shadow: 3px 3px 10px rgba(0, 0, 0, 0.1); /* 添加阴影效果 */"
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


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet(DarkButton_STYTLE);


    /*创建数据库*/
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chat_history.db");


    server = new QTcpServer(this);
    serverdb = new QTcpServer(this);
    // 创建两个线程
   // QThread *thread1 = new QThread;
    //QThread *thread2 = new QThread;

    // 将server和serverdb移动到不同的线程
    //server->moveToThread(thread1);
    //serverdb->moveToThread(thread2);
    // 启动线程
    //thread1->start();
    //thread2->start();


    //美化
    ui->textBrowser->setStyleSheet(styleSheet1);
    ui->textBrowserEvent->setStyleSheet(styleSheet1);
    ui->textBrowserPersonnelChange->setStyleSheet(styleSheet1);
    ui->textBrowserServer->setStyleSheet(styleSheet1);
    //美化
    ui->spinBoxMaxLen->setStyleSheet(spinBoxStyle1);
    ui->spinBoxPort->setStyleSheet(spinBoxStyle1);


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setSocketSlot()));
}

Dialog::~Dialog()
{
    // 关闭监听
    if(server->isListening()) // 判断是否正在监听
    {
        server->close();
    }
    QString sqlCmd = "DELETE FROM chat";
    if(db.isOpen())
    {
        qDebug()<<"清空表";
        QSqlQuery sq;
        sq.prepare(sqlCmd);
        sq.exec();
        db.close();
    }
    delete ui;
}
void Dialog::newConnecttionSlotDb(){

    socketdb = serverdb->nextPendingConnection();

    //断开连接检测信号槽

    connect(socketdb,SIGNAL(disconnected()),this,SLOT(disConnectedSlot()));

    connect(socketdb,SIGNAL(readyRead()),this,SLOT(loginSlot()));

    QString ip = socketdb->peerAddress().toString();
    qint64 port =socketdb->peerPort();
    ip.prepend("新连接来了<").append("：").append(QString::number(port)).append(">");
    ui->textBrowser->append(ip);

    socketdb=NULL;
}


void Dialog::newConnecttionSlot()
{
    //保存连接对象
    socket = server->nextPendingConnection();
    //socketdb = serverdb->nextPendingConnection();
    if(USER.count()>=MAXPEOPLENUMBER)
    {
        QString text="err:群聊已满";
        ui->textBrowserPersonnelChange->append("群聊已满，无法接入新连接");
        socket->write(text.toUtf8());
        socket->close();
        return ;
    }
    else
    {
        QString text="OK";
        socket->write(text.toUtf8());
    }


        USER.insert(USER.count(),socket);

    //断开连接检测信号槽
    connect(socket,SIGNAL(disconnected()),this,SLOT(disConnectedSlot()));

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));

    QString ip = socket->peerAddress().toString();
    qint64 port =socket->peerPort();
    ip.prepend("新连接来了<").append("：").append(QString::number(port)).append(">");
    ui->textBrowser->append(ip);

    socket=NULL;
}

void Dialog::disConnectedSlot()
{
    for(int i=0;i<USER.count();i++)
    {
        if(USER[i]->state()==QAbstractSocket::ConnectedState)
        {
            qDebug()<<"该连接可用";
        }
        else
        {
            qDebug()<<"该连接不可用";

            QString text=group_chat_members[i].append("退出群聊");
            ui->textBrowserPersonnelChange->append(text);

            group_chat_members.removeAt(i);
        }
    }

    QString sendText="";
    sendText.append("join:");
    for(int i=0;i<group_chat_members.count();i++)
    {
        sendText.append(group_chat_members[i]);
        sendText.append("\n");
    }

    QTcpSocket *socket=qobject_cast<QTcpSocket *>(sender());
    USER.removeAll(socket);
    socket->close();

    for(int i=0;i<USER.count();i++)
        USER[i]->write(sendText.toUtf8());

    ui->textBrowser->append("一个链接走了");
}

void Dialog::readyReadSlot()
{
    for(int i=0;i<USER.count();i++)
    {
        QByteArray buffer = USER[i]->readAll();
        QString recvText(buffer);

        if(recvText!="")
        {
            if(recvText.startsWith("join:"))
            {
                if(USER.count()<=MAXPEOPLENUMBER)
                {
                    QString text=recvText.mid(5).append("加入群聊");
                    ui->textBrowserPersonnelChange->append(text);

                    group_chat_members<<recvText.mid(5);
                }
                else
                {
                    return ;
                }
                QString sendText="";
                sendText.append("join:");
                //拼接在线成员名单
                for(int i=0;i<group_chat_members.count();i++)
                {
                    sendText.append(group_chat_members[i]);
                    sendText.append("\n");
                }
                //把在线成员名单遍历发送给每个用户
                for(int i=0;i<USER.count();i++)
                    USER[i]->write(sendText.toUtf8());
                return ;
            }
            else if(recvText=="历史查询")
            {
                ui->textBrowserEvent->append("收到用户查询历史记录事件");

                QString sqlcmd ="SELECT * FROM chat";
                QSqlQuery sq;
                if(sq.exec(sqlcmd))
                {
                    USER[i]->write("************历史记录************\n");
                    while(sq.next())
                    {
                        QString history=sq.value("Information").toString();
                        history.append("\n");

                        USER[i]->write(history.toUtf8());
                    }
                    USER[i]->write("**********************************");
                }
                ui->textBrowserEvent->append("已向用户发送历史记录");
                return ;
            }else if(recvText=="emoji:")
            {
                qDebug()<<"emoji";
                for(int i=0;i<USER.count();i++)
                    USER[i]->write(recvText.toUtf8());
                return ;
            }
            else//无前缀的普通聊天事件
            {
                ui->textBrowserEvent->append(recvText);

                QDateTime dt= QDateTime::currentDateTime();
                QString time = dt.toString("yyyy年M月dd日 hh:mm:ss\n");
                recvText.prepend(time);

                QString sqlcmd="INSERT INTO chat VALUES(?)";
                QSqlQuery sq;
                sq.prepare(sqlcmd);
                sq.addBindValue(recvText);
                sq.exec();

                for(int i=0;i<USER.count();i++)
                    USER[i]->write(recvText.toUtf8());
            }
        }
    }
}

void Dialog::setSocketSlot()
{
    if(ui->spinBoxPort->value()==8888){
        QMessageBox::warning(this,"端口已被占用","请使用8888端口以外的端口");
        return;
    }
    //更换按钮显示文字且不可使用
    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("已设置");
    //设置只读
    ui->spinBoxMaxLen->setReadOnly(true);
    ui->spinBoxPort->setReadOnly(true);
    //手势禁止
    ui->spinBoxMaxLen->setCursor(QCursor(Qt::ForbiddenCursor));
    ui->spinBoxPort->setCursor(QCursor(Qt::ForbiddenCursor));
    //清空功能区文字
    ui->textBrowser->clear();
    ui->textBrowserEvent->clear();
    ui->textBrowserPersonnelChange->clear();
    ui->textBrowserServer->clear();

    MAXPEOPLENUMBER=ui->spinBoxMaxLen->value();
    //开启监听，任意IP，指定端口
    bool server_db_result=serverdb->listen(QHostAddress::Any,8888);
    if(!server_db_result)
    {
        ui->textBrowserServer->append("监听失败");
        return ;
    }
    bool result =server->listen(QHostAddress::Any,ui->spinBoxPort->value());
    if(!result)
    {
        ui->textBrowserServer->append("监听失败");
        return ;
    }
    QString text="监听开启成功，  端口号为：";
    text.append(ui->spinBoxPort->text());
    ui->textBrowserServer->append(text);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnecttionSlot()));
    connect(serverdb,SIGNAL(newConnection()),this,SLOT(newConnecttionSlotDb()));
    bool ret = db.open();
    if(!ret)
    {
        QSqlError errorInfor=db.lastError();
        QString errText=errorInfor.text();

        hide();
        show();
        QMessageBox::critical(this,"数据库打开出错",errText);
        ui->textBrowserServer->append("数据库打开出错:");
        ui->textBrowserServer->append(errText);
    }
    else if(ret)
    {
        ui->textBrowserServer->append("数据库打开成功");
        QString sqlCmd = "CREATE TABLE chat(Information TEXT);";
        QSqlQuery sq;
        bool creatret = sq.exec(sqlCmd);
        if(creatret)
        {
            qDebug()<<"表头创建成功";
            //ui->textBrowserServer->append("历史记录表头创建成功");
        }
        else
        {
            qDebug()<<"表头创建失败";
            //ui->textBrowserServer->append("历史记录表头创建失败");
        }

        sqlCmd = "CREATE TABLE user(username TEXT,password TEXT);";
        creatret = sq.exec(sqlCmd);
        if(creatret)
        {
            qDebug()<<"表头创建成功";
            //ui->textBrowserServer->append("用户密码表头创建成功");
        }
        else
        {
            qDebug()<<"表头创建失败";
            //ui->textBrowserServer->append("用户密码表头创建失败");
        }
    }
}

void Dialog::loginSlot()
{
    QTcpSocket *socket=qobject_cast<QTcpSocket *>(sender());

    QByteArray buffer = socket->readAll();
    QString recvText(buffer);
    if(recvText.startsWith("login:"))
    {
        QStringList list = recvText.mid(6).split(":");

        QString username =list[0];
        QString password =list[1];
        QString text ="登录";
        text.append(username).append(":").append(password);
        ui->textBrowserServer->append(text);
        QString sqlcmdfind = "SELECT * FROM user WHERE username=?";
        QSqlQuery sq;
        sq.prepare(sqlcmdfind);
        sq.addBindValue(username);
        sq.exec();
        if(sq.next())
        {
            if (password==sq.value("password").toString())
            {
                socket->write("adopt");//通过
                return ;
            }
            else
            {
                socket->write("password err");//密码错误
                return ;
            }
        }
        else
        {
            socket->write("not find");//无此用户
            return ;
        }
    }
    else if(recvText.startsWith("register:"))
    {
        QStringList list = recvText.mid(9).split(":");

        QString username =list[0];
        QString password =list[1];
        QString text="注册";
        text.append(username).append(":").append(password);
        ui->textBrowserServer->append(text);
        QString sqlcmd = "INSERT INTO user VALUES(?,?)";
        QSqlQuery sq;
        sq.prepare(sqlcmd);
        sq.addBindValue(username);
        sq.addBindValue(password);
        if(sq.exec())
        {
            socket->write("finish");
        }
        else
        {
            socket->write("err");
        }
    }
}

