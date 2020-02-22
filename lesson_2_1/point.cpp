#include "point.h"
#include <cmath>

double Point::tav(const Point &pont) const
{
        return sqrt(pow((this->x-pont.x),2)+pow((this->y-pont.y),2));
}
