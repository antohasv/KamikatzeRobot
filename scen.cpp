#include "scen.h"

#include <QMessageBox>

Scen::Scen()
{
    this->resize(WIDTH, HEIGHT);
    menu = new Menu(this);
    game = new Game(this);
    result = new Result(this);
    score = new Score(this);

    cur = result;

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer->start(300);
}


Window* Scen::getWinMenu()
{
    return menu;
}


Window* Scen::getWinGame()
{
    return game;
}

Window* Scen::getWinScore()
{
    return score;
}

Window* Scen::getCurWin()
{
    return cur;
}

Window* Scen::getWinResult()
{
    return result;
}

void Scen::setCurWindow(Window *win)
{
    this->cur = win;
    this->update();
}

void Scen::paintEvent(QPaintEvent *paint)
{
    this->cur->paintEvent(paint);
}

void Scen::keyPressEvent(QKeyEvent * key)
{
    this->cur->keyPressEvent(key);
}

void Scen::gameUpdate()
{
    this->update();
}
