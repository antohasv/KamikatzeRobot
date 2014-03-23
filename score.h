#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QtGui>
#include "window.h"
#include "scen.h"

class Scen;
class Score : public Window
{
private:
    Scen *scen;
public:
    Score(Scen *s);
    void paintEvent(QPaintEvent *paint);
    void keyPressEvent(QKeyEvent * key);
};

#endif // SCORE_H
