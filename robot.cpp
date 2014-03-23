#include "robot.h"

Robot::Robot(int x, int y, int limit) : battery(limit) {
    this->setX(x);
    this->setY(y);
    this->img.setImage("C:\\Qt\\Qt5.0.1\\Tools\\QtCreator\\bin\\KamikazeRobots\\img\\robot.png");
}

void Robot::meetRobot() {

}
