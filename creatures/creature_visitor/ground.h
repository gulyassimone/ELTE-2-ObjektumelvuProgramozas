//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    classes of ground types (with visitor design pattern)

#pragma once

#include <string>

class Greenfinch;
class DuneBeetle;
class Squelchy;

// class of abstract grounds
class Ground{
public:
    virtual Ground* change(Greenfinch *p) = 0;
    virtual Ground* change(DuneBeetle *p) = 0;
    virtual Ground* change(Squelchy   *p) = 0;
    virtual ~Ground(){}
};

// class of sand
class Sand : public Ground
{
public:
    Ground* change(Greenfinch *p) override;
    Ground* change(DuneBeetle *p) override;
    Ground* change(Squelchy   *p) override;
};

// class of grass
class Grass : public Ground
{
public:
    Ground* change(Greenfinch *p) override;
    Ground* change(DuneBeetle *p) override;
    Ground* change(Squelchy   *p) override;
};


// class of marsh
class Marsh : public Ground
{
public:
    Ground* change(Greenfinch *p) override;
    Ground* change(DuneBeetle *p) override;
    Ground* change(Squelchy   *p) override;
};
