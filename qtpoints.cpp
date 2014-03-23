#include "qtpoints.h"

QtPoints::QtPoints(int x, int y)
{
    this->x = x;
    this->y = y;
}

void QtPoints::setPoints(int x, int y)
{
    this->x = x;
    this->y = y;
}

int QtPoints::getX()
{
    return this->x;
}

int QtPoints::getY()
{
    return this->y;
}
