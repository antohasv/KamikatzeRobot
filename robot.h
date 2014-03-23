#ifndef ROBOT_H
#define ROBOT_H

#include "util.h"
#include "battery.h"

class Robot : public Util
{
public:
    Battery battery;
public:
    Robot(int x, int y, int limit); // Battery limit
protected:
    void meetRobot();
};

#endif // ROBOT_H
