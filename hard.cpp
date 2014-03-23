#include "hard.h"

Hard::Hard()
{
    this->nB = 15;
    this->nP = 17;
    this->nS = 15;
}

int Hard::getStar()
{
    return this->nS;
}

int Hard::getBomb()
{
    return this->nB;
}

int Hard::getPower()
{
    return this->nP;
}
