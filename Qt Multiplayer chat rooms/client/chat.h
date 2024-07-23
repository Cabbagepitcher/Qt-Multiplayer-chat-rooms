#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QTcpSocket>
#include <QMessageBox>

#include <QDebug>
#include <QTimer>
#include <QString>

namespace Ui {
class MYDialog;
}

class MYDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MYDialog(QTcpSocket *socket,QString name,QWidget *parent = 0);
    ~MYDialog();

private:
    Ui::MYDialog *ui;
    QTcpSocket *socket;
    QTimer* timer;//延时器
    QString name;
private slots:

    void btnSendClickedSlot();

    void disconnectSlot();

    void readyReadSlot();
    void historySlot();
    void on_pushButton_clicked();
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

#endif // CHAT_H
