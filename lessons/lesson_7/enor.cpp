#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}
void Enor::next()
{
    if(!(_vege = (abnorm==_sx)))
    {
        std::string nev = _dx.nev;
        _akt = false;
        for(; norm==_sx && _dx.nev==nev; read() )
        {
            _akt = _akt || ("MEDVE"==_dx.fajta);
        }
    }
}

void Enor::read()
{
    _x >> _dx.nev >> _dx.fajta >> _dx.suly;
    _sx = _x.fail() ? abnorm : norm;
}
