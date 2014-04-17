#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QEvent"
#include "QKeyEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *target, QEvent *e)
{
    if(e->type()==QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent*>(e);
        if(ke->key()==Qt::Key_Tab)
            ui->textEdit->append("Tab");
        if(target == ui->lineEdit)
        {
            ui->textEdit->append("lineEdit");
        }
        if(target == ui->lineEdit_2)
        {
            ui->textEdit->append("lineEdit_2");
           // ui->textEdit->append(QMainWindow::eventFilter(target, e));
        }
        if(target == ui->lineEdit_3)
        {
            ui->textEdit->append("lineEdit_3");
        }
    }
   return QMainWindow::eventFilter(target, e);
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
