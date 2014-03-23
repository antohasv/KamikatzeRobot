#ifndef STAR_H
#define STAR_H

#include "util.h"

class Star: public Util {
    //private:
      //  Field field;
public:
    Star(int x, int y);
    void meetRobot();
};

#endif // STAR_H
