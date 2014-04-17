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
    if(ui->pushButton->text()=="test")
    {
        ui->pushButton->setText("ok");
        ui->lineEdit->setFocus();

    } else {
        ui->pushButton->setText("test");
        ui->lineEdit_2->setFocus();
    }

}
