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

void MainWindow::slot1()
{
    int num1, num2;
    int sum;    // 结果
    QString sum_str;    // 字符串型结果
    num1 = ui->lineEdit->text().toInt(0);
    num2 = ui->lineEdit_2->text().toInt(0);
    sum = num1 + num2;
    sum_str = QString::number(sum);
    ui->lineEdit_3->setText(sum_str);

}

void MainWindow::slot_teststr()
{
    QString teststr;
    teststr = ui->lineEdit_3->text();

    ui->textEdit->append(teststr.left(3));
    ui->textEdit->append(teststr.right(3));
    ui->textEdit->append(teststr.insert(2, "---"));

}
