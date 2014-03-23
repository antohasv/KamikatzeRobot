#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class Window
{
public:
    virtual void paintEvent(QPaintEvent *) = 0;
    virtual void keyPressEvent(QKeyEvent * key) = 0;
};

#endif // WINDOW_H
