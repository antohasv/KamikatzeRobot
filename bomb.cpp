#include "bomb.h"

#include <QMessageBox>
#include <QString>

Bomb::Bomb(int x, int y, int t)
{
    this->setX(x);
    this->setY(y);
    setIsALive(true);
    img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\bomb.png");

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(boom()));

    timer->start( t * 1000);
}

void Bomb::boom()
{
     this->setIsALive(false);
     timer->stop();
}

void Bomb::meetRobot()
{
    this ->setIsALive(false);
}
