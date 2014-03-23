#include "menu.h"
#include <QMessageBox>
#include <QImage>

Menu:: Menu(Scen *s):Window()
{
    this->scen = s;
}

void Menu::paintEvent(QPaintEvent *paint)
{
    int height = scen->height();
    int width = scen->width();

    QPainter p(scen);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    p.setFont(QFont("Comic Sans MS", 30, QFont::Normal));

    QImage img;
    img.load("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\menu.png");
    p.drawImage(QPoint(0, 0), img);

    QColor green(100, 200, 0);
    QColor orange(255, 192, 0);

    if(item == EASY)
        p.setPen(QPen(green, 1, Qt::SolidLine));
    else
        p.setPen(QPen(orange, 1, Qt::SolidLine));

    p.drawText(width/2 - 30, height/2 - 70, "Easy");

    if(item == MEDIUM)
        p.setPen(QPen(green, 1, Qt::SolidLine));
    else
        p.setPen(QPen(orange, 1, Qt::SolidLine));

    p.drawText(width/2 - 60, height/2, "Medium");

    if(item == HARD)
        p.setPen(QPen(green, 1, Qt::SolidLine));
    else
        p.setPen(QPen(orange, 1, Qt::SolidLine));

    p.drawText(width/2 - 30, height/2 + 70, "Hard");

}

void Menu::keyPressEvent(QKeyEvent *key)
{
    switch(key -> key())
    {
        case Qt::Key_Up:
            if(item == MEDIUM)
                item = EASY;
             else if(item == HARD)
                item = MEDIUM;
        break;
        case Qt::Key_Down:
            if(item == EASY)
                item = MEDIUM;
            else if(item == MEDIUM)
                item = HARD;
        break;
        case Qt::Key_Alt:
            ((Game*)scen->getWinGame())->clear();
            switch(item)
            {
                case EASY:
                    ((Game*)scen->getWinGame())->init(new Easy(), 10, 10);
                    break;
                case MEDIUM:
                    ((Game*)scen->getWinGame())->init(new Medium(), 10, 10);
                    break;
                case HARD:
                    ((Game*)scen->getWinGame())->init(new Hard(), 10, 10);
                    break;
            }

            scen->setCurWindow(scen->getWinGame());
        break;
    }
    scen->update();
}
