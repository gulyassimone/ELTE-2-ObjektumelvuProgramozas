#include "angler.h"
#include <sstream>

using namespace std;
Angler::Angler(string filename)
{
    _x.open(filename);
    if(_x.fail())
        throw FILE_NAME_ERROR;
}

void Angler::next()
{
    _sx=norm;
    _curr.isCatfish=false;
    _curr.isNotCatfish=false;
    string line;
    getline(_x,line);
    if (!_x.fail() && line!="")
    {
        istringstream in(line);

        in >> _dx.anglerId >> _dx.contestId;
        while( in >> _dx.fish >> _dx.sizeOfFish )
        {

            _curr.anglerId=_dx.anglerId;
            _curr.contestId=_dx.contestId;
            if(_dx.fish!="Harcsa")
            {
                _curr.isNotCatfish=true;
            }
            else if(_dx.fish=="Harcsa" && _curr.isCatfish)
            {
                if(_curr.sizeOfFish<_dx.sizeOfFish)
                {
                    _curr.sizeOfFish=_dx.sizeOfFish;
                }
            }
            else if(_dx.fish=="Harcsa" && !_curr.isCatfish)
            {
                _curr.isCatfish=true;
                _curr.sizeOfFish=_dx.sizeOfFish;
            }
        }

    }
    else
    {
        _sx=abnorm;

    }

    _end=(_sx==abnorm);
}
