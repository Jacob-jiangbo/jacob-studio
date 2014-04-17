#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    oped = false;   // ��ǰ�޲���
    op = ' ';       // ��ǰ�޲���
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
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "0");
}

void MainWindow::slot_pbutton_1()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "1");
}

void MainWindow::slot_pbutton_2()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "2");
}

void MainWindow::slot_pbutton_3()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "3");
}

void MainWindow::slot_pbutton_4()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "4");
}

void MainWindow::slot_pbutton_5()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "5");
}

void MainWindow::slot_pbutton_6()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "6");
}

void MainWindow::slot_pbutton_7()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "7");
}

void MainWindow::slot_pbutton_8()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "8");
}

void MainWindow::slot_pbutton_9()
{
    if(oped)
    {   // ����һ�Ρ�����������������
        ui->lEdit_out->setText("");
        oped = false;
    }
    ui->lEdit_out->setText(ui->lEdit_out->text() + "9");
}

void MainWindow::slot_pbutton_and()
{
    // �����δ��ɵļ������㣬�����
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
    // �ж��Ƿ��һ�ΰ�������
    if(num.isEmpty())
    {
        num = ui->lEdit_out->text();
        oped = true;    // �в���δ���
    } else {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                + ui->lEdit_out->text().toDouble()
            )
        );
        num = ui->lEdit_out->text();    // ���������Ϊ��ʷ����
        oped = true;    // �в���δ���
    }
    op = '+';
}

void MainWindow::slot_pbutton_sub()
{
    // �����δ��ɵļӷ����㣬�����
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
    // �ж��Ƿ��һ�ΰ���-��
    if(num.isEmpty())
    {
        num = ui->lEdit_out->text();
        oped = true;    // �в���δ���
    } else {
        ui->lEdit_out->setText(
            QString::number(
                num.toDouble()
                - ui->lEdit_out->text().toDouble()
            )
        );
        num = ui->lEdit_out->text();    // ���������Ϊ��ʷ����
        oped = true;    // �в���δ���
    }
    op = '-';
}

void MainWindow::slot_pbutton_back()
{
    // �˸�һ���ַ�
    if(ui->lEdit_out->text().length()>0)
    {
        ui->lEdit_out->setText(
            ui->lEdit_out->text().left(
                ui->lEdit_out->text().length()-1
            )
        );
    }
}
