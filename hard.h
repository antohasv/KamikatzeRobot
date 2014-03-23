#ifndef HARD_H
#define HARD_H

#include "level.h"

class Hard : public Level
{
public:
    Hard();
    int getStar();
    int getBomb();
    int getPower();
private:
    int nS;
    int nB;
    int nP;
};

#endif // HARD_H
