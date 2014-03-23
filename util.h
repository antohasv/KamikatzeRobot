#ifndef UTIL_H
#define UTIL_H

#include "image.h"

class Util
{
    // Attributes
  public:
      Image img;
  private:
    int x;
    int y;
    bool isLive;
    // Operations
  public:
    Util();
    void setData(int x, int y, QString path);
    void setX (int x);
    void setY (int y);
    int getX ();
    int getY ();
    void setIsALive (bool isALive);
    bool getIsALive ();
    virtual void meetRobot () = 0;
};

#endif // UTIL_H
