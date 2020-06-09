//Author:   Gregorics Tibor
//Date:     2017.12.15.
//Title:    classes of creatures

#pragma once

#include <string>

enum Ground { sand, grass, marsh };

// class of abstract creatures
class Creature{
protected:
    std::string _name;
    int _power;
    Creature (const std::string &str, int e = 0) :_name(str), _power(e) {}
public:
    std::string name() const { return _name; }
    bool alive() const { return _power > 0; }
    void changePower(int e) { _power += e; }
    virtual void transmute(int &court) = 0;
    virtual ~Creature () {}
};

// class of green finches
class Greenfinch : public Creature {
public:
    Greenfinch(const std::string &str, int e = 0) : Creature(str, e){}
    void transmute(int &court) override;
};

// class of dune beetles
class DuneBeetle : public Creature {
public:
    DuneBeetle(const std::string &str, int e = 0) : Creature(str, e){}
    void transmute(int &court) override;
};

// class of squelchies
class Squelchy : public Creature {
public:
    Squelchy(const std::string &str, int e = 0) : Creature(str, e){}
    void transmute(int &court) override;
};

