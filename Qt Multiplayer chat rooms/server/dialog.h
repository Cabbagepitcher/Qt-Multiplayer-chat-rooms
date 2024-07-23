#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <QDateTime>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QThread>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QTcpServer *server;
    QTcpServer* serverdb;

    QList<QTcpSocket *>USER;
    int MAXPEOPLENUMBER;
    QList<QString>group_chat_members;
    QTcpSocket *socket=NULL;
    QTcpSocket *socketdb=NULL;

    QMap<QTcpSocket *,QString>user;

    QSqlDatabase db;
    //QSqlDatabase db2;
private slots:
    void newConnecttionSlot();//聊天连接
    void disConnectedSlot();//关闭事件
    void readyReadSlot();//聊天事件
    void setSocketSlot();//点击设置后触发
    void loginSlot();//登录事件
    void newConnecttionSlotDb();//数据库登录连接
};


#define DarkButton_STYTLE (QString("\
/*按钮普通态*/\
QPushButton\
{\
    font-family:Microsoft Yahei;\
    /*字体大小*/\
    font-size:13pt;\
    /*字体颜色*/\
color:rgb(23,23,23);\
    /*背景颜色*/\
background:QLinearGradient(spread:pad,x1:0,y1:0,x2:1,y2:1,stop:0 #a8edea,stop:1 #fed6e3);\
    /*边框圆角半径为8像素*/\
    border-radius:8px;\
}\
/*按钮悬停态*/\
QPushButton:hover\
{\
    /*背景颜色*/\
background:QLinearGradient(spread:pad,x1:0,y1:0,x2:1,y2:1,stop:0 #b3ffab,stop:1 #12fff7);\
}\
/*按钮按下态*/\
QPushButton:pressed\
{\
    /*背景颜色*/\
background:QLinearGradient(spread:pad,x1:0,y1:0,x2:1,y2:1,stop:0 #fa709a,stop:1 #fee140);\
    /*左内边距为3像素，让按下时字向右移动3像素*/\
    padding-left:3px;\
    /*上内边距为3像素，让按下时字向下移动3像素*/\
    padding-top:3px;\
}"))

//系统白
/*    background-color:rgb(240,240,240);\ */


#endif // DIALOG_H
