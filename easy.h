#ifndef EASY_H
#define EASY_H

#include "level.h"

class Easy : public Level
{
public:
    Easy();
    int getStar();
    int getBomb();
    int getPower();
private:
    int nS;
    int nB;
    int nP;
};

#endif // EASY_H
