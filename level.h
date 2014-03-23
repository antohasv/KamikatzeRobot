#ifndef LEVEL_H
#define LEVEL_H

class Level
{
public:
    virtual int getStar() = 0;
    virtual int getBomb() = 0;
    virtual int getPower() = 0;
};

#endif // LEVEL_H
