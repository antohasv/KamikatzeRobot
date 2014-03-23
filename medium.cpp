#include "medium.h"

Medium::Medium()
{
    this->nB = 10;
    this->nP = 5;
    this->nS = 10;
}

int Medium::getStar()
{
    return this->nS;
}

int Medium::getBomb()
{
    return this->nB;
}

int Medium::getPower()
{
    return this->nP;
}
