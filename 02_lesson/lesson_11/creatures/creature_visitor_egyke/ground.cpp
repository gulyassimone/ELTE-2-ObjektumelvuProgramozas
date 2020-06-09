//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    implementation of classes of groundtypes (with visitor design pattern)

#include "ground.h"
#include "creature.h"

using namespace std;

// implementation of class Sand
Sand* Sand::_instance = nullptr;
Sand* Sand::instance()
{
    if(_instance == nullptr) {
        _instance = new Sand();
    }
    return _instance;
}

Ground* Sand::change(Greenfinch *p)
{
    p->changePower(-2);
    return this;
}

Ground* Sand::change(DuneBeetle *p)
{
    p->changePower(3);
    return this;
}

Ground* Sand::change(Squelchy *p)
{
    p->changePower(-5);
    return this;
}

void Sand::destroy() { if ( nullptr!=_instance ) delete _instance; }

// implementation of class Grass
Grass* Grass::_instance = nullptr;
Grass* Grass::instance()
{
    if(_instance == nullptr) {
        _instance = new Grass();
    }
    return _instance;
}

Ground* Grass::change(Greenfinch *p)
{
    p->changePower(1);
    return this;
}

Ground* Grass::change(DuneBeetle *p)
{
    p->changePower(-2);
    return Sand::instance();
}

Ground* Grass::change(Squelchy *p)
{
    p->changePower(-2);
    return Marsh::instance();
}
void Grass::destroy() { if ( nullptr!=_instance ) delete _instance; }

// implementation of class Marsh
Marsh* Marsh::_instance = nullptr;
Marsh* Marsh::instance()
{
    if(_instance == nullptr) {
        _instance = new Marsh();
    }
    return _instance;
}

Ground* Marsh::change(Greenfinch *p)
{
    p->changePower(-1);
    return Grass::instance();
}

Ground* Marsh::change(DuneBeetle *p)
{
    p->changePower(-4);
    return Grass::instance();
}

Ground* Marsh::change(Squelchy *p)
{
    p->changePower(6);
    return this;
}

void Marsh::destroy() { if ( nullptr!=_instance ) delete _instance; }
