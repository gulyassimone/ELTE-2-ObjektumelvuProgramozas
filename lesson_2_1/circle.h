#pragma once
#include "point.h"


class Circle

{
private:
    Point _c;
    double _r;

public:
    Circle() {};
    Circle(const Point &p, double d):_c(p), _r(d) {}
    bool contains(const Point &p) const {
        return p.distance(p)<=_r;
    };


};
