#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtGui>
#include "window.h"
#include "scen.h"
#include "easy.h"
#include "medium.h"
#include "hard.h"


class Scen;
class Menu : public Window
{
private:
    Scen *scen;
    enum Items { EASY, MEDIUM, HARD }item = EASY;
public:
    Menu(Scen *s);
    void paintEvent(QPaintEvent *paint);
    void keyPressEvent(QKeyEvent * key);
};

#endif // MENU_H
