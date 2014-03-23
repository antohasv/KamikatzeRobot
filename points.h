#ifndef POINTS_H
#define POINTS_H

class Points
{
    // Attributes
private:
    int point;
    // Operations
public:
    Points(int point);
    void setPoint (int point);
    int getPoint ();
    void decrease();
};

#endif // POINTS_H
