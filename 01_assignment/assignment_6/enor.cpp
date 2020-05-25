#include "enor.h"
#include <iostream>

using namespace std;
Enor::Enor(const std::string fname)
{
    _x.open(fname);
    if(_x.fail()) throw FILEERROR;
}
void Enor::next()
{
    if(!(_end = (abnorm==_sx)))
    {
        _act.food = _dx.food;
        _act.price=0;
        for(; norm==_sx && _dx.food==_act.food; read())
        {
            _act.price+=_dx.price*_dx.portion;
        }

    }
}
void Enor::read()
{
   _sx =(_x >> _dx.number >> _dx.food >> _dx.date >> _dx.portion >> _dx.price)? norm:abnorm;
}
