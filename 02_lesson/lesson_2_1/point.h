#pragma once
#include <cmath>

class Point
{
public:
    double _x, _y;

public:

    Point(double a=0, double b=0):_x(a), _y(b) {}
    double distance(const Point &pont) const{
        return sqrt(pow((_x-pont._x),2)+pow((_y-pont._y),2));
    }
};
