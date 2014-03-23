#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include "bomb.h"
#include "scen.h"

class Timer : public QObject
{
    Q_OBJECT
private:
    QTimer *t;
public:
    Timer(Scen *s,Bomb *b);
public slots:
    void boom();
};

#endif // TIMER_H
