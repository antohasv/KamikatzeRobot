#include "game.h"

#include <QMessageBox>
#include <QString>

Game::Game(Scen *s): robot(0, 0, 8), points(0), door()
{
    this->scen = s;
}

void Game::init(Level *l, int n, int m)
{
    this->level = l;
    this->n = n;
    this->m = m;
    stime = QTime::currentTime();
    this->start();
}

void Game::start()
{
    placeStars(level->getStar());
    placeBombs(level->getBomb());
    placePowers(level->getPower());

    points.setPoint(level->getStar());
    this->isALive = true;
    scen->update();
}

void Game::clear()
{
    stars.clear();
    bombs.clear();
    powers.clear();
    level = NULL;
    points = NULL;
    robot = Robot(0, 0, 8);
    door = Door();
}

void Game::paintEvent(QPaintEvent *paint)
{
    int height = scen->height();
    int width = scen->width();

    int x = dx;
    int y = dy;

    QPainter p(scen);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    if(this->isALive)
    {
        //Field
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                p.drawRect(QRect(x, y, hw, hw));
                x += hw;
            }
            y += hw;
            x = dx;
        }

        //Robot
        p.drawImage(QPoint(robot.getX() * hw + dx, robot.getY() * hw + dy), robot.img.getImage());

        //Stars
        list<Star>::iterator its;
        for(its = stars.begin(); its != stars.end(); ++its)
        {
            if((*its).getIsALive())
                p.drawImage(QPoint((*its).getX() * hw + dx, (*its).getY()* hw + dy), (*its).img.getImage());
        }

        //Bombs
        list<Bomb*>::iterator itb;
        for(itb = bombs.begin(); itb != bombs.end(); ++itb)
        {
            if((*itb)->getIsALive() == true)
                 p.drawImage(QPoint((*itb)->getX() * hw + dx, (*itb)->getY() * hw + dy), (*itb)->img.getImage());
            else
            {
                this->boomBomb(&p, (*itb)->getX(), (*itb)->getY());
                //this->reviveBomb(*itb);
                itb = bombs.erase(itb);
                this->placeBombs(1);
                this->scen->update();
            }
        }

        //Powers
        list<Power>::iterator itp;
        for(itp = powers.begin(); itp != powers.end(); ++itp)
        {
            if((*itp).getIsALive() == true)
                p.drawImage(QPoint((*itp).getX() * hw + dx, (*itp).getY() * hw + dy), (*itp).img.getImage());
        }

        //Door
        if(door.getIsALive())
            p.drawImage(QPoint(door.getX() * hw + dx, door.getY() * hw + dy), door.img.getImage());

         //Battery
         int bx = 40;
         int by = dy + 100;
         int bw  = 120;
         int bh = 320;
         p.drawRect(bx, by, bw, bh);
         p.drawRect(bx + (bw / 2) - 10, by - 10, 30, 10);

         int d = 5; // distance between two blocks
         //Gradient
         p.setBrush(QBrush(Qt::green, Qt::SolidPattern));

         for(int i = 0; i < robot.battery.getPower(); i++)
         {
             p.drawRect(bx + 5, by + bh - 35 - i*(d + 35), bw - 10, 30);
         }

        //PointBar
         QImage imgs("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\star.png");
         int pb_offsety = 50;
         int pb_offsetx = (hw * m) + dx - 100;
         p.drawImage(QPoint(pb_offsetx, pb_offsety - 30), imgs) ;

         p.setFont(QFont("Times", 15, QFont::Normal));
         p.drawText(pb_offsetx + imgs.width() + 10, pb_offsety, "x" + QString::number( points.getPoint()));

         //Time
         QTime time;
         time = QTime::currentTime();
         QString smin;
         QString ssec;
         int min = time.minute() - stime.minute();
         int sec = time.second();

         int tsec = 0;
         if((tsec = (sec - stime.second())) < 0)
         {
             min--;
             sec = 60 - stime.second() + sec;
         }
         else
             sec = tsec;

         smin = QString::number(min);
         ssec = QString::number(sec);

         if(min < 10)
             smin = "0" + QString::number(min);

         if(sec < 10)
             ssec = "0" + QString::number(sec);

         QString str = smin + ":" + ssec;
         p.drawText(80, pb_offsety + 10, str);

    }
    else
    {
        p.setFont(QFont("Comic Sans MS", 30, QFont::Normal));
        p.drawText(width/2 - 30, height/2, "Wait...");
    }
}

void Game::reviveBomb(Bomb *b)
{
    b->setIsALive(true);

    QtPoints p = getFreeCell();
    b->setX(p.getX());
    b->setY(p.getY());
}

void Game::boomBomb(QPainter *p, int x, int y)
{
    int rx = robot.getX();
    int ry = robot.getY();
    bool t = false;

    for(int i = y - 1; i < y + 2; i++)
        {
            for(int j = x - 1; j < x + 2; j++)
            {
                if((j >= 0 && j < this->n) && ( i >= 0 && i < this->m))
                {
                     if(rx == j && ry == i)
                         t = true;
                }
            }
        }

    if(t)
    {
        robot.battery.setPower(robot.battery.getPower() - 1);
        this->border(p, x, y);
    }
}

void Game::border(QPainter *p, int x, int y)
{
    p->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    for(int i = y - 1; i < y + 2; i++)
        {
            for(int j = x - 1; j < x + 2; j++)
            {
                if((j >= 0 && j < this->n) && ( i >= 0 && i < this->m))
                {
                    if(i != y || j != x)
                       p->drawRect(QRect(i*hw + this->dx, j*hw + this->dy, hw, hw));
                }
            }
        }
    p->setBrush(QBrush(Qt::NoBrush));
}

void Game::keyPressEvent(QKeyEvent * key)
{
    if(this->isALive)
    {
        switch(key -> key())
        {
            case Qt::Key_Up:
                if(testPosition(robot.getX(), robot.getY() - 1))
                {
                    visitLocation(robot.getX(), robot.getY() - 1);
                    robot.setY(robot.getY() - 1);
                }
            break;
            case Qt::Key_Down:
                if(testPosition(robot.getX(), robot.getY() + 1))
                {
                    visitLocation(robot.getX(), robot.getY() + 1);
                    robot.setY(robot.getY() + 1);
                }
            break;
            case Qt::Key_Left:
                if(testPosition(robot.getX() - 1, robot.getY()))
                {
                    visitLocation(robot.getX() - 1, robot.getY());
                    robot.setX(robot.getX() - 1);
                }
            break;
            case Qt::Key_Right:
            if(testPosition(robot.getX() + 1, robot.getY()))
            {
                visitLocation(robot.getX() + 1, robot.getY());
                robot.setX(robot.getX() + 1);
                //
            }
            break;
        }
        scen -> update();
    }
}

bool Game::testPosition(int x, int y)
{
    if ((x >= 0) && (x < m) && (y >= 0) && (y < n))
        return true;
    return false;
}

void Game::visitLocation(int x, int y)
{
    list<Star>::iterator its;
    list<Bomb*>::iterator itb;
    list<Power>::iterator itp;

    if(door.getIsALive())
    {
        if((door.getX() == x) && (door.getY() == y))
        {
            scen->setCurWindow(scen->getWinResult());
        }
    }

    for(its = stars.begin(); its != stars.end(); ++its)
    {
        if((*its).getIsALive() == true)
        {
            if(((*its).getX() == x) && ((*its).getY() == y))
            {
                its = stars.erase(its);
                points.decrease();
            }
        }
    }

    if(stars.empty())
    {
        if(!door.getIsALive())
        {
            QtPoints dp = getFreeCell();
            door.setX(dp.getX());
            door.setY(dp.getY());
            door.setIsALive(true);
        }
    }

    for(itb = bombs.begin(); itb != bombs.end(); ++itb)
    {
        if((*itb)->getIsALive() == true)
        {
            if(((*itb)->getX() == x) && ((*itb)->getY() == y))
            {
                (*itb)->setIsALive(false);
                robot.battery.setPower(robot.battery.getPower() - 1);
            }
        }
    }

    for(itp = powers.begin(); itp != powers.end(); ++itp)
    {
        if((*itp).getIsALive() == true)
        {
            if(((*itp).getX() == x) && ((*itp).getY() == y))
            {
                (*itp).setIsALive(false);
                robot.battery.setPower(robot.battery.getPower() + 1);
            }
        }
    }

    if(robot.battery.empty())
    {
        scen->setCurWindow(scen->getWinMenu());
    }
}

int Game::boostRandom(int begin, int end)
{
    boost::random::uniform_int_distribution<> dist(begin, end);
    return dist(gen);
}

void Game::placeStars(int ns) {

    for(int i = 0; i < ns; i++)
    {
        QtPoints p = getFreeCell();
        stars.push_back(Star(p.getX(), p.getY()));
    }
}

void Game::placeBombs(int nb)
{
    for(int i = 0; i < nb; i++)
    {
        QtPoints p = getFreeCell();
        Bomb *b = new Bomb(p.getX(), p.getY(), boostRandom(1, 3));
        bombs.push_back(b);
    }
}

void Game::placePowers(int np)
{
    for(int i = 0; i < np; i++)
    {
        QtPoints p = getFreeCell();
        powers.push_back(Power(p.getX(), p.getY()));
    }
}

QtPoints Game::getFreeCell()
{
    list<Star>::iterator its;
    list<Bomb*>::iterator itb;
    list<Power>::iterator itp;

    int rx = 0;
    int ry = 0;

    //srand (time(NULL));

    bool t = false;

    while(true)
    {
           rx = boostRandom(0, this->m - 1);
           ry = boostRandom(0, this->n - 1);

           if((robot.getX() == rx) && (robot.getY() == ry))
               continue;

           if(door.getX() == rx && door.getY() == ry)
               continue;

           t = false;
           for(its = stars.begin(); its != stars.end(); ++its)
           {

               if(((*its).getX() == rx) && ((*its).getY() == ry))
                   t = true;
           }

           if(t)
               continue;

           t = false;
           for(itb = bombs.begin(); itb != bombs.end(); ++itb)
           {
               if(((*itb)->getX() == rx) && ((*itb)->getY() == ry))
                   t = true;
           }

           if(t)
               continue;


           t = false;
           for(itp = powers.begin(); itp != powers.end(); ++itp)
           {
               if(((*itp).getX() == rx) && ((*itp).getY() == ry))
                   t = true;
           }

           if(t)
               continue;
           else
               break;

       }

    return QtPoints(rx, ry);

}


