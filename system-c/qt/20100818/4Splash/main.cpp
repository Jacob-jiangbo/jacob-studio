#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QtGui/QSplashScreen"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("splash.jpg"));
    splash->show();\
    splash->showMessage(QObject::tr("Setting up the main window..."),
                        Qt::AlignCenter , Qt::white);
    for(int c=0; c<100000; c++)
        qDebug("%d", c);

    MainWindow w;

    splash->showMessage(QObject::tr("Loading modules..."),
        Qt::AlignCenter , Qt::white);
    for(int c=0; c<100000; c++)
        qDebug("%d", c);

    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}
