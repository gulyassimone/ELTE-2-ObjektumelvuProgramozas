#pragma once

class Point
{
    private:
    double _x, _y;

    public:

    Point(int _x=0, int _y=0):x(x), y(y){}
    double tav(const Point &pont) const;
    };
