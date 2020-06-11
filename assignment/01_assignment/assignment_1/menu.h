#pragma once

#include "matrix.h"

class Menu
{
public:
    void run();
private:
    Matrix a;

    int menuWrite();
    void getElement() const;
    void setElement();
    void readMatrix();
    void writeMatrix();
    void sum();
    void mul();
};
