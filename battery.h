#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
    // Attributes
private:
    int limit;
    int power;
    // Operations
public:
    Battery(int limit);
    int getPower ();
    void setPower (int power);
    int getLimit();
    bool empty();
    void increase();
    void decrease();
};

#endif // BATTERY_H
