#include "enor.h"
#include <iostream>
using namespace std;

Enor::Enor(string x)
{
    _x.open(x);
    if(_x.fail())
        throw FILEERROR;
}
void Enor::next()
{
    if(!(_end = (abnorm==_sx)))
    {
        _curr.recipe=_dx.recipe;
        _curr.needsSugar=false;
        for(; norm==_sx && _curr.recipe==_dx.recipe; read())
        {
            _curr.needsSugar=_curr.needsSugar || _dx.ingredient=="sugar";
        }
    }
}
void Enor::read()
{
    _sx=(_x>>_dx.recipe>>_dx.ingredient>>_dx.amount>>_dx.measure)?norm:abnorm;
}
