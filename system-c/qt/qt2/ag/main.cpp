#include <QtCore/QCoreApplication>
#include "QThread"

class myThread: public QThread
{
public :
        virtual void run();
};

void myThread::run()
{
    for(int c=0; c<10; c++)
    {
        sleep(1);
        qDebug("pthread %d", c);
    }
}

int main(int argc, char *argv[])
{
    myThread a,b;
    a.start();
    b.start();
    a.wait();
    b.wait();
    return 0;
}
