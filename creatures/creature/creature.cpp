#include "creature.h"

using namespace std;

void Greenfinch::transmute(int &ground)
{
    if ( alive() ){
        switch(ground){
            case sand:  _power-=2; break;
            case grass: _power+=1; break;
            case marsh: _power-=1; ground = grass; break;
        }
    }
}

void DuneBeetle::transmute(int &ground)
{
    if (alive() ){
        switch(ground){
            case sand:  _power+=3; break;
            case grass: _power-=2; ground = sand; break;
            case marsh: _power-=4; ground = grass; break;
        }
    }
}

void Squelchy::transmute(int &ground)
{
    if (alive() ){
        switch(ground){
            case sand:  _power-=5; break;
            case grass: _power-=2; ground = marsh; break;
            case marsh: _power+=6; break;
        }
    }
}
