#pragma once
#include "point.h"


class Circle

{
    private:
    Point c;
    double r;

    public:
    Circle(Point c, double r):c(c), r(r){}
    bool contains(const Point &pont);


};
