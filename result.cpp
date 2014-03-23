#include "result.h"

Result::Result(Scen *s)
{
    this->scen = s;
}

void Result::init(int time, Items itm)
{

}

void Result::paintEvent(QPaintEvent *paint)
{
    int height = scen->height();
    QPainter p(scen);
    QImage img;
    img.load("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\win.png");
    p.drawImage(QPoint(0, 0), img);

    p.setFont(QFont("Comic Sans MS", 30, QFont::Normal));
    QColor green(100, 200, 0);
    QColor orange(255, 192, 0);

    p.setPen(QPen(orange, 1, Qt::SolidLine));
    if(menu == Restart)
        p.setPen(QPen(green, 1, Qt::SolidLine));
    p.drawText(150, height - 100, "Play Again");

    p.setPen(QPen(orange, 1, Qt::SolidLine));
    if(menu == Score)
        p.setPen(QPen(green, 1, Qt::SolidLine));
    p.drawText(150 + 300, height - 100, "Score");
}

void Result::keyPressEvent(QKeyEvent * key)
{
    switch(key -> key())
    {
        case Qt::Key_Right:
        if(menu == Restart)
            menu = Score;

        break;
    case Qt::Key_Left:
        if(menu == Score)
            menu = Restart;
        break;
    case Qt::Key_Alt:
        switch(menu)
        {
        case Restart:
            this->scen->setCurWindow(scen->getWinMenu());
            break;
        case Score:
            this->scen->setCurWindow(scen->getWinScore());
            break;
        }
        break;
    }
}
