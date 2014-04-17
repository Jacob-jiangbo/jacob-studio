#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui/QTextEdit"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytextedit = new myTextEdit(this);
    mytextedit->setGeometry(20, 100, 100, 100);
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this->mytextedit, SLOT(slot_test(bool)));
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

myTextEdit::myTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    outstr = "myTextEdit";
}

void myTextEdit::slot_test(bool val)
{
    this->append(QString::number(val));
    this->append(outstr);
}
