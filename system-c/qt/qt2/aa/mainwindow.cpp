#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::slot_test()
{
    ui->textEdit->setPlainText("aaaaacccccddddd");
    ui->textEdit_2->setHtml("<font color=red>aa</font><font color=green><h1>aa</b></font>");
}

void MainWindow::slot_textchange()
{
    ui->textEdit_2->append("TextChanged");
}

void MainWindow::slot_copy()
{
    ui->textEdit->copy();
    ui->textEdit_2->append("<h2>copy");
}

void MainWindow::slot_cut()
{
    ui->textEdit->cut();
    ui->textEdit_2->append("<h3>cut");
}

void MainWindow::slot_paste()
{
    ui->textEdit->paste();
    ui->textEdit_2->append("<h4>paste");
}



