/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MYDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonHistory;
    QPushButton *pushButton;
    QPushButton *pushButtonSend;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowserMember;

    void setupUi(QDialog *MYDialog)
    {
        if (MYDialog->objectName().isEmpty())
            MYDialog->setObjectName("MYDialog");
        MYDialog->resize(759, 435);
        MYDialog->setStyleSheet(QString::fromUtf8("background:QLinearGradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #ace0f9,stop:1 #fff1eb)"));
        gridLayout = new QGridLayout(MYDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(10, 10, 10, 10);
        textBrowser = new QTextBrowser(MYDialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(500, 200));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(16);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(textBrowser);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(10, 10, 10, 10);
        plainTextEdit = new QPlainTextEdit(MYDialog);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setMinimumSize(QSize(0, 90));
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(plainTextEdit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        pushButtonHistory = new QPushButton(MYDialog);
        pushButtonHistory->setObjectName("pushButtonHistory");
        pushButtonHistory->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Agency FB")});
        font1.setPointSize(14);
        pushButtonHistory->setFont(font1);
        pushButtonHistory->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonHistory->setAutoDefault(false);

        verticalLayout_3->addWidget(pushButtonHistory);

        pushButton = new QPushButton(MYDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 0));
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(pushButton);

        pushButtonSend = new QPushButton(MYDialog);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setMinimumSize(QSize(100, 0));
        pushButtonSend->setFont(font1);
        pushButtonSend->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSend->setCheckable(false);
        pushButtonSend->setAutoDefault(false);
        pushButtonSend->setFlat(false);

        verticalLayout_3->addWidget(pushButtonSend);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(MYDialog);
        label->setObjectName("label");
        label->setMinimumSize(QSize(150, 50));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Agency FB")});
        font2.setPointSize(20);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout->addWidget(label);

        textBrowserMember = new QTextBrowser(MYDialog);
        textBrowserMember->setObjectName("textBrowserMember");
        textBrowserMember->setMinimumSize(QSize(150, 300));
        textBrowserMember->setMaximumSize(QSize(16777215, 16777215));
        textBrowserMember->setFont(font2);
        textBrowserMember->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout->addWidget(textBrowserMember);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(MYDialog);

        pushButtonSend->setDefault(false);


        QMetaObject::connectSlotsByName(MYDialog);
    } // setupUi

    void retranslateUi(QDialog *MYDialog)
    {
        MYDialog->setWindowTitle(QCoreApplication::translate("MYDialog", "\350\201\212\345\244\251", nullptr));
        pushButtonHistory->setText(QCoreApplication::translate("MYDialog", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("MYDialog", "\350\241\250\346\203\205", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MYDialog", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("MYDialog", "<html><head/><body><p align=\"center\">\347\276\244\350\201\212\346\210\220\345\221\230</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MYDialog: public Ui_MYDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
