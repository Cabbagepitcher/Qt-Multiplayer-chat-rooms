/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *spinBoxMaxLen;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QSpinBox *spinBoxPort;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTextBrowser *textBrowserServer;
    QLabel *label_2;
    QTextBrowser *textBrowserEvent;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QTextBrowser *textBrowserPersonnelChange;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(665, 615);
        Dialog->setStyleSheet(QString::fromUtf8("background:QLinearGradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #ace0f9,stop:1 #fff1eb)"));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout_5->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        label_6 = new QLabel(Dialog);
        label_6->setObjectName("label_6");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Agency FB")});
        font1.setPointSize(14);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background:transparent"));

        horizontalLayout_2->addWidget(label_6);

        spinBoxMaxLen = new QSpinBox(Dialog);
        spinBoxMaxLen->setObjectName("spinBoxMaxLen");
        spinBoxMaxLen->setFont(font1);
        spinBoxMaxLen->setCursor(QCursor(Qt::PointingHandCursor));
        spinBoxMaxLen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBoxMaxLen->setValue(3);

        horizontalLayout_2->addWidget(spinBoxMaxLen);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        label_7 = new QLabel(Dialog);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background:transparent"));

        horizontalLayout_3->addWidget(label_7);

        spinBoxPort = new QSpinBox(Dialog);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setFont(font1);
        spinBoxPort->setCursor(QCursor(Qt::PointingHandCursor));
        spinBoxPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBoxPort->setMinimum(5000);
        spinBoxPort->setMaximum(19151);
        spinBoxPort->setValue(9999);

        horizontalLayout_3->addWidget(spinBoxPort);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(120, 40));
        pushButton->setMaximumSize(QSize(120, 40));
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        label_5 = new QLabel(Dialog);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout_3->addWidget(label_5);

        textBrowserServer = new QTextBrowser(Dialog);
        textBrowserServer->setObjectName("textBrowserServer");
        textBrowserServer->setMinimumSize(QSize(280, 150));
        textBrowserServer->setFont(font1);
        textBrowserServer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(textBrowserServer);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout_3->addWidget(label_2);

        textBrowserEvent = new QTextBrowser(Dialog);
        textBrowserEvent->setObjectName("textBrowserEvent");
        textBrowserEvent->setMinimumSize(QSize(280, 150));
        textBrowserEvent->setFont(font1);
        textBrowserEvent->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(textBrowserEvent);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout->addWidget(label_4);

        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(280, 0));
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(textBrowser);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background:transparent"));

        verticalLayout->addWidget(label_3);

        textBrowserPersonnelChange = new QTextBrowser(Dialog);
        textBrowserPersonnelChange->setObjectName("textBrowserPersonnelChange");
        textBrowserPersonnelChange->setMinimumSize(QSize(280, 0));
        textBrowserPersonnelChange->setFont(font1);
        textBrowserPersonnelChange->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(textBrowserPersonnelChange);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\347\275\221\347\273\234\350\201\212\345\244\251\345\256\244\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">\347\275\221\347\273\234\350\201\212\345\244\251\345\256\244\346\234\215\345\212\241\345\231\250</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "\346\234\200\345\244\247\344\272\272\345\221\230\346\225\260\351\207\217\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        spinBoxPort->setSuffix(QString());
        spinBoxPort->setPrefix(QString());
        pushButton->setText(QCoreApplication::translate("Dialog", "\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\346\234\215\345\212\241\345\231\250\344\272\213\344\273\266</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">\347\224\250\346\210\267\344\272\213\344\273\266</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">\351\223\276\346\216\245\344\272\213\344\273\266</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\">\344\272\272\345\221\230\345\217\230\345\212\250</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
