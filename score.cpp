#include "score.h"

Score::Score(Scen *s)
{
    this->scen = s;
}

void Score::paintEvent(QPaintEvent *paint)
{

}

void Score::keyPressEvent(QKeyEvent * key)
{
    switch(key -> key())
    {
        case Qt::Key_Right:
        break;
    }
}
