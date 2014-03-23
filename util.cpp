#include "util.h"

Util::Util(){}

void Util::setX(int x) {
    this -> x = x;
}

void Util::setY(int y) {
    this -> y = y;
}


int Util::getX() {
    return this -> x;
}

int Util::getY() {
    return this -> y;
}

void Util::setIsALive(bool isLive) {
    this -> isLive = isLive;
}

bool Util::getIsALive() {
    return this -> isLive;
}
