#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"//

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

void MainWindow::slot_read()
{
    QFile filer( "a.txt" ); // 从文件中读取文本
    if (filer.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->textEdit->setText( filer.readAll() );
        filer.close();
    }
}

void MainWindow::slot_write()
{
    QFile filew( "a.txt" ); // 写到文件
    if (filew.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        filew.write(ui->textEdit->toPlainText().toAscii());
        filew.close();
    }
}
