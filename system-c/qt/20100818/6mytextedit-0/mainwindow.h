#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtGui/QTextEdit"

namespace Ui {
    class MainWindow;

}

class myTextEdit: public QTextEdit {
    Q_OBJECT

public:
    QString outstr;

public slots:
    void slot_test(bool);
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    myTextEdit *mytextedit;
};

#endif // MAINWINDOW_H

