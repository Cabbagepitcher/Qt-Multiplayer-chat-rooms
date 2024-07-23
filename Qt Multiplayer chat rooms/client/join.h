#ifndef JOIN_H
#define JOIN_H

#include <QDialog>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QString>

#include "chat.h"

namespace Ui {
class join;
}

class join : public QDialog
{
    Q_OBJECT

public:
    explicit join(QWidget *parent = 0);
    ~join();

private:
    Ui::join *ui;
    QTcpSocket *socket;
    QTimer* timer;//延时器
    int time_spent;
    MYDialog *mydlog;
private slots:
    void btnConnectClickedSlot();
    void connectSlot();
    void timeoutSlot();
    void readyReadSlot();
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


#endif // JOIN_H
