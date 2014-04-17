#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"
#include "QTimer"

void MainWindow::slot1()
{
    QTime t;
    t.start();
    for(int c=0; c<10000; c++)
    {
        qDebug("%d", c);
    }
    qDebug("ms=%d", t.elapsed());
    for(int c=0; c<100000; c++)
    {
    }
    qDebug("ms=%d", t.elapsed());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(slot1()));
    ui->setupUi(this);
    t->start(5000);

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
