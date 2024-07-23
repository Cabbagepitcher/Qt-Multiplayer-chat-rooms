#include "chat.h"
#include "ui_chat.h"
QString textBrowserStyle =

    "QTextBrowser {"
    "   background-color: #f0f0f0;"
    "   border: 1px solid #ccc;"
    "   padding: 10px;"
    "   font-size: 24px;"
    "   color: #333;"
    "   text-align: justify;"
    "   border-radius: 5px;"
    "   selection-background-color: #4a90e2;"
    "   selection-color: #fff;"
    "}"
    "QTextBrowser:hover {"
    "   border-color: #999;"
    "}"
    "QTextBrowser:focus {"
    "   border-color: #007acc;"
    "   box-shadow: 0 0 5px #007acc;"
    "}";
QString plainTextEditStyle =
    "QPlainTextEdit {"
    "   background-color: #f0f0f0;"
    "   border: 1px solid #ccc;"
    "   padding: 10px;"
    "   font-size: 24px;"
    "   color: #333;"
    "   border-radius: 5px;"
    "   selection-background-color: #4a90e2;"
    "   selection-color: #fff;"
    "}"
    "QPlainTextEdit:hover {"
    "   border-color: #999;"
    "}"
    "QPlainTextEdit:focus {"
    "   border-color: #007acc;"
    "   box-shadow: 0 0 5px #007acc;"
    "}";
MYDialog::MYDialog(QTcpSocket *socketed,QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MYDialog)
{
    ui->setupUi(this);
    ui->pushButtonHistory->setStyleSheet(DarkButton_STYTLE);
    ui->pushButtonSend->setStyleSheet(DarkButton_STYTLE);
    ui->pushButton->setStyleSheet(DarkButton_STYTLE);
    ui->textBrowser->setStyleSheet(textBrowserStyle);
    ui->textBrowserMember->setStyleSheet(textBrowserStyle);
    ui->plainTextEdit->setStyleSheet(plainTextEditStyle);
    this->socket=socketed;
    this->name=name;

    connect(ui->pushButtonSend,SIGNAL(clicked()),this,SLOT(btnSendClickedSlot()));
    connect(ui->pushButtonHistory,SIGNAL(clicked()),this,SLOT(historySlot()));
//    connect(ui->plainTextEdit,SIGNAL(returnPressed()),this,SLOT(btnSendClickedSlot()));

    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnectSlot()));

    //接收消息
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));
}

MYDialog::~MYDialog()
{
    qDebug()<<"MYDialog析构函数";

    QString quit="quit:";
    quit.append(name);
        if(socket->state()==QAbstractSocket::ConnectedState)
            qDebug()<<"连接可用";
        else
            qDebug()<<"连接不可用";
    socket->write(quit.toUtf8());
    qDebug()<<"发送"<<quit;

    delete ui;
}

void MYDialog::btnSendClickedSlot()
{
    QString sendText = ui->plainTextEdit->toPlainText();
    if(sendText=="")
    {
        hide();
        show();
        QMessageBox::warning(this,"提示","请输入发送的内容");
        return ;
    }

    sendText.prepend("说：");
    sendText.prepend(name);
    socket->write(sendText.toUtf8());

    ui->plainTextEdit->clear();
}

void MYDialog::disconnectSlot()
{
    //hide();
    //show();
    QMessageBox::information(this,"提示","与服务器链接断开，请重新登录");

    ui->pushButtonSend->setEnabled(false);
    ui->pushButtonHistory->setEnabled(false);

    close();
}

void MYDialog::readyReadSlot()
{
    qDebug()<<"收到消息";
    QByteArray buffer = socket->readAll();
    QString text(buffer);

    if(text.startsWith("join:"))
    {
        text=text.mid(5);
        ui->textBrowserMember->setText(text);

        return ;
    }
    else if(text.startsWith("emoji:")){
        QString combinedText = name + ":" + " <img src=':/kx.svg' width='20' height='20'>";
        ui->textBrowser->append(combinedText);
        return;
    }
    else{
        ui->textBrowser->append(text);

    }
}

void MYDialog::historySlot()
{
    QString sendText="历史查询";

    socket->write(sendText.toUtf8());
}

void MYDialog::on_pushButton_clicked()//表情
{
    QString sendText;
    //sendText.prepend(name);
    sendText.append("emoji:");
    socket->write(sendText.toUtf8());
}

