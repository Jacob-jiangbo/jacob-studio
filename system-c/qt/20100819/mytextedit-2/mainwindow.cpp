#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui/QTextEdit"
#include "QKeyEvent"
#include "QTextEdit"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytextedit = new myTextEdit(this);
    mytextedit->setGeometry(20, 100, 300, 300);
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)),
                     this->mytextedit, SLOT(slot_test(bool)));
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


void myTextEdit::keyPressEvent(QKeyEvent *e)
{
    this->append("Key=" + QString::number(e->key()));
    if(e->key() == Qt::Key_Tab)
        this->append("Key= Tab");
    if(e->key() == Qt::Key_Home)
        this->append("Key= Home");
    QTextEdit::keyPressEvent(e);
}

void myTextEdit::mousePressEvent(QMouseEvent *e)
{
    this->append("X=" + QString::number(e->globalX()));
    this->append("Y=" + QString::number(e->globalY()));
    this->append("x=" + QString::number(e->x()));
    this->append("y=" + QString::number(e->y()));
    if(e->button()==Qt::LeftButton)
        this->append("Left");
    if(e->button()==Qt::RightButton)
        this->append("Right");
}
