#include "mainwindow.h"
#include <QApplication>

#include "scen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scen *s = new Scen();
    s->show();
    
    return a.exec();
}
