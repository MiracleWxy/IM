/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTableWidget *IPTableWidget;
    QLabel *CurrentLabel;
    QTextEdit *RxTextEdit;
    QTextEdit *TxTextEdit;
    QPushButton *MessPushButton;
    QPushButton *FilePushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(979, 724);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 20, 171, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(23);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        IPTableWidget = new QTableWidget(centralWidget);
        IPTableWidget->setObjectName(QStringLiteral("IPTableWidget"));
        IPTableWidget->setGeometry(QRect(30, 90, 211, 611));
        CurrentLabel = new QLabel(centralWidget);
        CurrentLabel->setObjectName(QStringLiteral("CurrentLabel"));
        CurrentLabel->setGeometry(QRect(250, 100, 171, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        CurrentLabel->setFont(font1);
        CurrentLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 97, 100);"));
        RxTextEdit = new QTextEdit(centralWidget);
        RxTextEdit->setObjectName(QStringLiteral("RxTextEdit"));
        RxTextEdit->setGeometry(QRect(250, 140, 671, 391));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(12);
        RxTextEdit->setFont(font2);
        TxTextEdit = new QTextEdit(centralWidget);
        TxTextEdit->setObjectName(QStringLiteral("TxTextEdit"));
        TxTextEdit->setGeometry(QRect(250, 560, 621, 141));
        MessPushButton = new QPushButton(centralWidget);
        MessPushButton->setObjectName(QStringLiteral("MessPushButton"));
        MessPushButton->setGeometry(QRect(880, 567, 71, 51));
        FilePushButton = new QPushButton(centralWidget);
        FilePushButton->setObjectName(QStringLiteral("FilePushButton"));
        FilePushButton->setGeometry(QRect(880, 640, 71, 51));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "IM\345\215\263\346\227\266\351\200\232", Q_NULLPTR));
        CurrentLabel->setText(QApplication::translate("MainWindow", "192.168.123.123", Q_NULLPTR));
        MessPushButton->setText(QApplication::translate("MainWindow", "\345\217\221  \351\200\201", Q_NULLPTR));
        FilePushButton->setText(QApplication::translate("MainWindow", "\346\226\207  \344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
