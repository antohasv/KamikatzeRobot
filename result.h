#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QtGui>
#include "window.h"
#include "scen.h"

class Scen;
class Result : public Window
{
private:
    Scen *scen;
public:
    Result(Scen *s);
    enum Items { EASY, MEDIUM, HARD }item = EASY;
    enum Menu { Restart, Score}menu = Restart;
    void init(int, Items);
    void paintEvent(QPaintEvent *paint);
    void keyPressEvent(QKeyEvent * key);
};

#endif // RESULT_H
