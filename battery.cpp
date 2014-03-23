#include "battery.h"

Battery::Battery(int limit)
{
    this ->limit = limit;
    this ->power = limit;
}

int Battery::getPower()
{
    return this -> power;
}

void Battery::setPower(int power)
{
    if (power >= 0 && power <= limit)
        this -> power = power;
}

int Battery::getLimit()
{
    return this->limit;
}

bool Battery::empty()
{
    if(this->power == 0)
        return true;
    return false;
}

void Battery::increase()
{
    if (power >= 0 && power <= limit)
        this -> power++;
}

void Battery::decrease()
{
    if (power >= 0 && power <= limit)
        this->power--;
}
