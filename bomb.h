#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QTimer>

#include "util.h"

class Bomb : public QObject, public Util
{
    Q_OBJECT
private:
    QTimer *timer;
public:
    Bomb(int x, int y, int t);
    void meetRobot();
public slots:
    void boom();
};

#endif // BOMB_H
