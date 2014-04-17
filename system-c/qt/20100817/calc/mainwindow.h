#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QString num;        // 上次输入的数字
    bool oped;          // 操作是否完成
    QChar op;           // 上一次未完成的操作符号

public slots:
    void slot_pbutton_1();
    void slot_pbutton_2();
    void slot_pbutton_3();
    void slot_pbutton_4();
    void slot_pbutton_5();
    void slot_pbutton_6();
    void slot_pbutton_7();
    void slot_pbutton_8();
    void slot_pbutton_9();
    void slot_pbutton_0();
    void slot_pbutton_and();
    void slot_pbutton_sub();
    void slot_pbutton_back();   // backspace
};

#endif // MAINWINDOW_H
