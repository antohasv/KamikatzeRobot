#include "power.h"

Power::Power(int x, int y) {
    setX(x);
    setY(y);
    img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\power.png");
}

void Power::meetRobot() {
    this ->setIsALive(false);
}

