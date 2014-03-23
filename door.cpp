#include "door.h"


Door::Door()
{
     this->img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\door.png");
}

Door::Door(int x, int y)
{
    this->setX(x);
    this->setY(y);
    this->img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\door.png");
}

void Door::meetRobot() {

}

