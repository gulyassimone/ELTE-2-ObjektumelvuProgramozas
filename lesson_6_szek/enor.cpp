#include "enor.h"

Enor::Enor(const std::string fnev)
{
    _x.open(fnev);
    if(_x.fail()) throw FILEERROR;
    //ctor
}

void Enor::next()
{
    _vege = (abnorm==_sx);
    if(!_vege)
    {
        _akt.szaml = _dx.szaml;
        _akt.egy = 0;
        for(; norm==_sx && _dx.szaml == _akt.szaml; read()){
            _akt.egy += _dx.ossz;
        }
    }
}

void Enor::read()
{
    _x >> _dx.szaml >> _dx.datum >> _dx.ossz;
    if(_x.fail()) _sx=abnorm;
    else _sx=norm;
}
