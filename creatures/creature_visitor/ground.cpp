//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    implementation of classes of ground types (with visitor design pattern)

#include "ground.h"
#include "creature.h"

using namespace std;

// implementation of class Sand
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

// implementation of class Grass
Ground* Grass::change(Greenfinch *p)
{
    p->changePower(1);
    return this;
}

Ground* Grass::change(DuneBeetle *p)
{
    p->changePower(-2);
    return new Sand;
}

Ground* Grass::change(Squelchy *p)
{
    p->changePower(-2);
    return new Marsh;
}

// implementation of class Marsh
Ground* Marsh::change(Greenfinch *p)
{
    p->changePower(-1);
    return new Grass;
}

Ground* Marsh::change(DuneBeetle *p)
{
    p->changePower(-4);
    return new Grass;
}

Ground* Marsh::change(Squelchy *p)
{
    p->changePower(6);
    return this;
}
