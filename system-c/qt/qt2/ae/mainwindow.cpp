#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDate"

void MainWindow::slot1()
{
    QDate d(2010, 8, 16);
    QDate dn = d.addDays(300);
    ui->textEdit->append(QString::number(dn.year()));
    ui->textEdit->append(QString::number(dn.month()));
    ui->textEdit->append(QString::number(dn.day()));

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

