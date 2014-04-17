
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

public slots:
    void slot_test();
    void slot_textchange();
    void slot_copy();
    void slot_cut();
    void slot_paste();
};

#endif // MAINWINDOW_H
