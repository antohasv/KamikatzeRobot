#ifndef ITIMER_H
#define ITIMER_H

#include <QObject>
#include <QTimer>

#include "bomb.h"

class Itimer : public QObject
{
    Q_OBJECT
private:
    Bomb *b;
    QTimer *t;
public:
    Itimer();
    Itimer(const Itimer&);
    void start(Bomb *bomb);
public slots:
    void boom();
};

#endif // ITIMER_H

