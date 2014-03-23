#include "points.h"


Points::Points(int points)
{
    this->point = points;
}

void Points::setPoint(int point) {
    this -> point = point;
}

void Points::decrease()
{
    this->point--;
}

int Points::getPoint() {
    return this -> point;
}
