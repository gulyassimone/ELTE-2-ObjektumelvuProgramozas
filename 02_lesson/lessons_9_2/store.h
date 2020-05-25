#pragma once
#include "department.h"

class Store
{
    public:
        Store();
        ~Store(){ delete _foods; delete _technical; }

        Department* _technical;
        Department* _foods;
};
