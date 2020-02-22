#include "circle.h"


bool Circle::contains(const Point &pont)
{
        return pont.tav(c)<=r;
}
