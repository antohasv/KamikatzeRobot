#ifndef SCEN_H
#define SCEN_H

#include <QWidget>
#include <QTimer>

#include "window.h"
#include "menu.h"
#include "game.h"
#include "result.h"
#include "score.h"
#include "score.h"

class Scen : public QWidget
{
    Q_OBJECT
private:
    Window *cur;
    Window *menu;
    Window *game;
    Window *result;
    Window *score;
public:
    Scen();
    Window* getWinMenu();
    Window* getWinGame();
    Window* getWinResult();
    Window* getWinScore();
    Window* getCurWin();
    void setCurWindow(Window *win);
    void paintEvent(QPaintEvent *paint);
    void keyPressEvent(QKeyEvent * key);
private:
    const static int HEIGHT = 700;
    const static int WIDTH = 900;
public slots:
    void gameUpdate();
};

#endif // SCEN_H
