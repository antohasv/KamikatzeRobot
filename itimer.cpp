#include "itimer.h"

Itimer::Itimer() {}

Itimer::Itimer(const Itimer& it){}

void Itimer::start(Bomb *bomb)
{
    this->b = bomb;

}

void Itimer::boom()
{
    this->b->setIsALive(false);
    t->stop();
}

