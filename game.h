#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QtGui>
#include <QTime>

#include <time.h>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "window.h"
#include "scen.h"
#include "level.h"

#include "points.h"
#include "door.h"
#include "bomb.h"
#include "star.h"
#include "robot.h"
#include "power.h"

#include "qtpoints.h"

class Scen;
class Game : public Window
{
    // Attributes
public:
    list<Star> stars;
    list<Bomb*> bombs;
    list<Power> powers;
private:
    bool isALive = false; // Start or Wait Game
    Scen *scen;
    Level *level;
    Points points;
    Door door;
    Robot robot;
    QTime stime; // time when game start
    boost::random::mt19937 gen;
    int n;
    int m;
    const static int dx = 200; // Offset X
    const static int dy = 100; // Offset Y
    const static int hw = 50; // cell height width
public:
    Game(Scen *s);
    void init(Level *l, int n, int m);
    void paintEvent(QPaintEvent *paint);
    void keyPressEvent(QKeyEvent * key);
    void visitLocation(int x, int y);
    void clear();
    void border(QPainter *p, int x, int y);
    void boomBomb(QPainter *p, int x, int y);
    int boostRandom(int begin, int end);
private:
    void start();
    bool testPosition(int x, int y);
    void placeStars(int ns);
    void placeBombs(int nb);
    void placePowers(int np);
    void reviveBomb(Bomb *b);
    QtPoints getFreeCell();
};

#endif // GAME_H
