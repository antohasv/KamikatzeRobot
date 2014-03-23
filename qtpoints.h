#ifndef QTPOINTS_H
#define QTPOINTS_H

class QtPoints
{
private:
    int x;
    int y;
public:
    QtPoints(int x, int y);
    void setPoints(int x, int y);
    int getX();
    int getY();
};

#endif // QTPOINTS_H
