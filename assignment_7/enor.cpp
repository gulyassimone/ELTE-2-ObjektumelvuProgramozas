#include "enor.h"
using namespace std;

Enor::Enor(string x)
{
    _x.open(x);
    if(_x.fail())
        throw FILE_NAME_ERROR;
}
void Enor::next()
{
    if(!(_end = (abnorm==_sx)))
    {
        _curr.recipe=_dx.recipe;
        _curr.needsSugar=true;
        for(; _curr.needsSugar && norm==_sx; read())
        {
            _curr.needsSugar=!(_dx.ingredient.compare("sugar"));
        }
    }
}
void Enor::read()
{
    _sx=(_x>>_dx.recipe>>_dx.ingredient>>_dx.amount>>_dx.measure)?norm:abnorm;
}
