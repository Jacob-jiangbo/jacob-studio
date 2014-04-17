/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Aug 17 16:15:21 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lEdit_out;
    QPushButton *pButton_1;
    QPushButton *pButton_2;
    QPushButton *pButton_3;
    QPushButton *pButton_4;
    QPushButton *pButton_5;
    QPushButton *pButton_6;
    QPushButton *pButton_7;
    QPushButton *pButton_8;
    QPushButton *pButton_9;
    QPushButton *pButton_0;
    QPushButton *pButton_and;
    QPushButton *pButton_sub;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(197, 302);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    lEdit_out = new QLineEdit(centralWidget);
    lEdit_out->setObjectName(QString::fromUtf8("lEdit_out"));
    lEdit_out->setGeometry(QRect(10, 10, 161, 27));
    lEdit_out->setLayoutDirection(Qt::RightToLeft);
    pButton_1 = new QPushButton(centralWidget);
    pButton_1->setObjectName(QString::fromUtf8("pButton_1"));
    pButton_1->setGeometry(QRect(10, 50, 23, 29));
    QFont font;
    font.setFamily(QString::fromUtf8("Bitstream Charter"));
    font.setPointSize(16);
    pButton_1->setFont(font);
    pButton_2 = new QPushButton(centralWidget);
    pButton_2->setObjectName(QString::fromUtf8("pButton_2"));
    pButton_2->setGeometry(QRect(40, 50, 23, 29));
    pButton_2->setFont(font);
    pButton_3 = new QPushButton(centralWidget);
    pButton_3->setObjectName(QString::fromUtf8("pButton_3"));
    pButton_3->setGeometry(QRect(70, 50, 23, 29));
    pButton_3->setFont(font);
    pButton_4 = new QPushButton(centralWidget);
    pButton_4->setObjectName(QString::fromUtf8("pButton_4"));
    pButton_4->setGeometry(QRect(10, 80, 23, 29));
    pButton_4->setFont(font);
    pButton_5 = new QPushButton(centralWidget);
    pButton_5->setObjectName(QString::fromUtf8("pButton_5"));
    pButton_5->setGeometry(QRect(40, 80, 23, 29));
    pButton_5->setFont(font);
    pButton_6 = new QPushButton(centralWidget);
    pButton_6->setObjectName(QString::fromUtf8("pButton_6"));
    pButton_6->setGeometry(QRect(70, 80, 23, 29));
    pButton_6->setFont(font);
    pButton_7 = new QPushButton(centralWidget);
    pButton_7->setObjectName(QString::fromUtf8("pButton_7"));
    pButton_7->setGeometry(QRect(10, 110, 23, 29));
    pButton_7->setFont(font);
    pButton_8 = new QPushButton(centralWidget);
    pButton_8->setObjectName(QString::fromUtf8("pButton_8"));
    pButton_8->setGeometry(QRect(40, 110, 23, 29));
    pButton_8->setFont(font);
    pButton_9 = new QPushButton(centralWidget);
    pButton_9->setObjectName(QString::fromUtf8("pButton_9"));
    pButton_9->setGeometry(QRect(70, 110, 23, 29));
    pButton_9->setFont(font);
    pButton_0 = new QPushButton(centralWidget);
    pButton_0->setObjectName(QString::fromUtf8("pButton_0"));
    pButton_0->setGeometry(QRect(10, 140, 23, 29));
    pButton_0->setFont(font);
    pButton_and = new QPushButton(centralWidget);
    pButton_and->setObjectName(QString::fromUtf8("pButton_and"));
    pButton_and->setGeometry(QRect(100, 50, 23, 29));
    pButton_and->setFont(font);
    pButton_sub = new QPushButton(centralWidget);
    pButton_sub->setObjectName(QString::fromUtf8("pButton_sub"));
    pButton_sub->setGeometry(QRect(100, 80, 23, 29));
    pButton_sub->setFont(font);
    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 197, 24));
    MainWindow->setMenuBar(menuBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);
    QObject::connect(pButton_1, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_1()));
    QObject::connect(pButton_2, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_2()));
    QObject::connect(pButton_3, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_3()));
    QObject::connect(pButton_4, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_4()));
    QObject::connect(pButton_5, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_5()));
    QObject::connect(pButton_6, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_6()));
    QObject::connect(pButton_7, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_7()));
    QObject::connect(pButton_8, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_8()));
    QObject::connect(pButton_9, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_9()));
    QObject::connect(pButton_0, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_0()));
    QObject::connect(pButton_and, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_and()));
    QObject::connect(pButton_sub, SIGNAL(clicked()), MainWindow, SLOT(slot_pbutton_sub()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    pButton_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
    pButton_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
    pButton_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
    pButton_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
    pButton_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
    pButton_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
    pButton_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
    pButton_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
    pButton_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
    pButton_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
    pButton_and->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
    pButton_sub->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
