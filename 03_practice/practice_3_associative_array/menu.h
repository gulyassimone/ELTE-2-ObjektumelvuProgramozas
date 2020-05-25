#pragma once
#include "associativeArray.h"

class Menu
{
public:
    void run();
private:
    int getMenuPoint();
    void setEmpty();
    void count();
    void insert();
    void erase();
    void search();
    void write();
    AT at;
};
