//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    implementation of point

#include "point.h"

//Task: 	writing a point
//Input:    ostream o   -  output adatfolyam
//          Point p     -  point
//Output:   ostream o   -  output adatfolyam
//Activity: writing the coordinates of the point
std::ostream& operator<<(std::ostream &o, const Point &p)
{
    o << "(" << p._x << "," << p._y << ")";
    return o;
}
