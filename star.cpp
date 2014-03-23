#include "star.h"

Star::Star(int x, int y) {
    setX(x);
    setY(y);
    img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\star.png");
    this ->setIsALive(true);
}

void Star::meetRobot() {
    this ->setIsALive(false);
}

