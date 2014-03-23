#include "easy.h"

Easy::Easy()
{
    this->nB = 10;
    this->nP = 7;
    this->nS = 10;
}

int Easy::getStar()
{
    return this->nS;
}

int Easy::getBomb()
{
    return this->nB;
}

int Easy::getPower()
{
    return this->nP;
}
