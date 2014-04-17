#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    oped = false;   // 当前无操作
    op = ' ';       // 当前无操作
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

void MainWindow::slot_pbutton_0()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "0");
}

void MainWindow::slot_pbutton_1()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "1");
}

void MainWindow::slot_pbutton_2()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "2");
}

void MainWindow::slot_pbutton_3()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "3");
}

void MainWindow::slot_pbutton_4()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "4");
}

void MainWindow::slot_pbutton_5()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "5");
}

void MainWindow::slot_pbutton_6()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "6");
}

void MainWindow::slot_pbutton_7()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "7");
}

void MainWindow::slot_pbutton_8()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "8");
}

void MainWindow::slot_pbutton_9()
{
    if(oped)
    {   // 按过一次‘＋’，则清空输入框
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "9");
}

void MainWindow::slot_pbutton_and()
{
    // 如果有未完成的减法运算，完成它
    if(op=='-')
    {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                - ui->lEdit_out->text().toDouble()
            )
        );
        num = "";
        op = ' ';
    }
    // 判断是否第一次按‘＋’
    if(num.isEmpty())
    {
        num = ui->lEdit_out->text();
        oped = true;    // 有操作未完成
    } else {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                + ui->lEdit_out->text().toDouble()
            )
        );
        num = ui->lEdit_out->text();    // 将结果保存为历史输入
        oped = true;    // 有操作未完成
    }
    op = '+';
}

void MainWindow::slot_pbutton_sub()
{
    // 如果有未完成的加法运算，完成它
    if(op=='+')
    {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                + ui->lEdit_out->text().toDouble()
            )
        );
        num = "";
        op = ' ';
    }
    // 判断是否第一次按‘-’
    if(num.isEmpty())
    {
        num = ui->lEdit_out->text();
        oped = true;    // 有操作未完成
    } else {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                - ui->lEdit_out->text().toDouble()
            )
        );
        num = ui->lEdit_out->text();    // 将结果保存为历史输入
        oped = true;    // 有操作未完成
    }
    op = '-';
}

void MainWindow::slot_pbutton_back()
{
    // 退格一个字符
    if(ui->lEdit_out->text().length()>0)
    {
        ui->lEdit_out->setText(
            ui->lEdit_out->text().left(
                ui->lEdit_out->text().length()-1
            )
        );
    }
}
