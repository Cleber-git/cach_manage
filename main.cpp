#include "mainwindow.h"
#include "cont_all.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cont_all ct_a;
    MainWindow w;

    QObject::connect(&w, SIGNAL(sendTableDB(QString)), &ct_a, SLOT(Slot_execute(QString)));


    w.show();
    return a.exec();
}
