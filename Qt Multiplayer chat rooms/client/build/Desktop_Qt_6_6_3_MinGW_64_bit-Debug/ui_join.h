/********************************************************************************
** Form generated from reading UI file 'join.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOIN_H
#define UI_JOIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_join
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxPort;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEditNickname;
    QPushButton *pushButtonConnect;
    QProgressBar *progressBar;

    void setupUi(QDialog *join)
    {
        if (join->objectName().isEmpty())
            join->setObjectName("join");
        join->resize(544, 387);
        join->setStyleSheet(QString::fromUtf8("background:QLinearGradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #ace0f9,stop:1 #fff1eb)"));
        verticalLayout_3 = new QVBoxLayout(join);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(join);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background:transparent"));

        horizontalLayout->addWidget(label);

        lineEditIP = new QLineEdit(join);
        lineEditIP->setObjectName("lineEditIP");
        lineEditIP->setMinimumSize(QSize(200, 0));
        lineEditIP->setFont(font);
        lineEditIP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEditIP->setCursorPosition(15);
        lineEditIP->setDragEnabled(false);

        horizontalLayout->addWidget(lineEditIP);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        label_2 = new QLabel(join);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background:transparent"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxPort = new QSpinBox(join);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setMinimumSize(QSize(200, 0));
        spinBoxPort->setFont(font);
        spinBoxPort->setCursor(QCursor(Qt::PointingHandCursor));
        spinBoxPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBoxPort->setMinimum(5000);
        spinBoxPort->setMaximum(65536);
        spinBoxPort->setValue(9999);

        horizontalLayout_2->addWidget(spinBoxPort);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(10, 10, 10, 10);
        label_3 = new QLabel(join);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background:transparent"));

        horizontalLayout_6->addWidget(label_3);

        lineEditNickname = new QLineEdit(join);
        lineEditNickname->setObjectName("lineEditNickname");
        lineEditNickname->setFont(font);
        lineEditNickname->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEditNickname->setMaxLength(5);

        horizontalLayout_6->addWidget(lineEditNickname);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_3->addLayout(verticalLayout);

        pushButtonConnect = new QPushButton(join);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setMinimumSize(QSize(120, 40));
        pushButtonConnect->setFont(font);
        pushButtonConnect->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(pushButtonConnect);


        verticalLayout_2->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(join);
        progressBar->setObjectName("progressBar");
        progressBar->setFont(font);
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(join);

        QMetaObject::connectSlotsByName(join);
    } // setupUi

    void retranslateUi(QDialog *join)
    {
        join->setWindowTitle(QCoreApplication::translate("join", "\345\212\240\345\205\245\347\276\244\350\201\212", nullptr));
        label->setText(QCoreApplication::translate("join", "IP", nullptr));
        lineEditIP->setInputMask(QCoreApplication::translate("join", "000.000.000.000", nullptr));
        lineEditIP->setText(QCoreApplication::translate("join", "192.168.31.245", nullptr));
        lineEditIP->setPlaceholderText(QCoreApplication::translate("join", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("join", "Port", nullptr));
        label_3->setText(QCoreApplication::translate("join", "\346\230\265\347\247\260", nullptr));
        lineEditNickname->setPlaceholderText(QCoreApplication::translate("join", "\346\234\200\345\244\247\344\272\224\344\270\252\345\255\227\347\254\246", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("join", "\345\212\240\345\205\245\347\276\244\350\201\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class join: public Ui_join {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOIN_H
