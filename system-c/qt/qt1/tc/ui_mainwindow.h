/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Aug 13 15:37:06 2010
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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pButton_test;
    QLineEdit *lEdit_out;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(159, 149);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    pButton_test = new QPushButton(centralWidget);
    pButton_test->setObjectName(QString::fromUtf8("pButton_test"));
    pButton_test->setGeometry(QRect(30, 20, 93, 41));
    QFont font;
    font.setFamily(QString::fromUtf8("Bitstream Charter"));
    font.setPointSize(20);
    font.setBold(true);
    font.setWeight(75);
    pButton_test->setFont(font);
    lEdit_out = new QLineEdit(centralWidget);
    lEdit_out->setObjectName(QString::fromUtf8("lEdit_out"));
    lEdit_out->setGeometry(QRect(20, 80, 113, 41));
    QFont font1;
    font1.setFamily(QString::fromUtf8("URW Chancery L"));
    font1.setPointSize(26);
    font1.setItalic(true);
    lEdit_out->setFont(font1);
    MainWindow->setCentralWidget(centralWidget);

    retranslateUi(MainWindow);
    QObject::connect(pButton_test, SIGNAL(clicked()), MainWindow, SLOT(slot_test()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    pButton_test->setText(QApplication::translate("MainWindow", "test", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
