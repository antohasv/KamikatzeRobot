#ifndef DOOR_H
#define DOOR_H

#include "util.h"

class Door: public Util {
    // Attributes
    // Operations
public:
    Door();
    Door(int x, int y);
    void meetRobot();
};

#endif // DOOR_H
