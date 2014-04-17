/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Aug 13 13:54:41 2010
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pButton_ok;
    QPushButton *pButton_cancel;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QComboBox *comboBox;
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(329, 409);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    groupBox = new QGroupBox(centralWidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(30, 70, 171, 161));
    pButton_ok = new QPushButton(groupBox);
    pButton_ok->setObjectName(QString::fromUtf8("pButton_ok"));
    pButton_ok->setGeometry(QRect(0, 20, 93, 27));
    pButton_ok->setCursor(QCursor(Qt::OpenHandCursor));
    pButton_cancel = new QPushButton(groupBox);
    pButton_cancel->setObjectName(QString::fromUtf8("pButton_cancel"));
    pButton_cancel->setGeometry(QRect(0, 50, 161, 51));
    QFont font;
    font.setFamily(QString::fromUtf8("Serif"));
    font.setPointSize(24);
    font.setBold(true);
    font.setUnderline(true);
    font.setWeight(75);
    pButton_cancel->setFont(font);
    pushButton = new QPushButton(groupBox);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(-10, 110, 191, 21));
    checkBox = new QCheckBox(centralWidget);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    checkBox->setGeometry(QRect(40, 300, 97, 22));
    checkBox_2 = new QCheckBox(centralWidget);
    checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
    checkBox_2->setGeometry(QRect(40, 340, 97, 22));
    radioButton = new QRadioButton(centralWidget);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setGeometry(QRect(40, 260, 110, 22));
    radioButton_2 = new QRadioButton(centralWidget);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
    radioButton_2->setGeometry(QRect(40, 230, 110, 22));
    comboBox = new QComboBox(centralWidget);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(40, 30, 85, 27));
    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(40, 370, 65, 17));
    lcdNumber = new QLCDNumber(centralWidget);
    lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
    lcdNumber->setGeometry(QRect(190, 310, 131, 91));
    lcdNumber->setProperty("value", QVariant(123));
    MainWindow->setCentralWidget(centralWidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
    pButton_ok->setText(QApplication::translate("MainWindow", "ok123", 0, QApplication::UnicodeUTF8));
    pButton_cancel->setText(QApplication::translate("MainWindow", "cancel", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "dddddddddddd", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
    checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
    radioButton->setText(QApplication::translate("MainWindow", "RadioButton", 0, QApplication::UnicodeUTF8));
    radioButton_2->setText(QApplication::translate("MainWindow", "RadioButton", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
