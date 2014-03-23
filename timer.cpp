#include "timer.h"

#include <QMessageBox>

Timer::Timer(Scen *s, Bomb *b)
{
    t = new QTimer(this);
    QObject::connect(t, SIGNAL(timeout()), s, SLOT(Timer::boom()));
    t->start(1000);
}

void Timer::boom()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}
