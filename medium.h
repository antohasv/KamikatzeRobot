#ifndef MEDIUM_H
#define MEDIUM_H

#include "level.h"

class Medium : public Level
{
public:
    Medium();
    int getStar();
    int getBomb();
    int getPower();
private:
    int nS;
    int nB;
    int nP;
};

#endif // MEDIUM_H
