#include <iostream>
#include <sstream>
#include "summation.hpp"
#include "seqinfileenumerator.hpp"
#include "linsearch.hpp"
#include "stringstreamenumerator.hpp"
#include "enumerator.hpp"

using namespace std;
struct Fish
{
    string species;
    int weight;
};
istream& operator >>(istream &is, Fish &e)
{
    is >> e.species >> e.weight;
    return is;
}
class MyLinSearch : public LinSearch<Fish>
{
protected:
    bool cond(const Fish &e) const override{ return e.species=="lion"; }
};
struct Angler{
    string name;
    bool haslion;
};

class List:public Summation<Angler,ostream>
{
public:
    List(ostream *o) : Summation<Angler,ostream>(o){}
protected:
    string func(const Angler &e)const override { return e.name+"\n"; }
    bool cond (const Angler& e ) const override {return e.haslion;}
};
struct Hunt{
    string name;
    string date;
    bool haslion;
};
istream& operator >>(istream &is, Hunt &e)
{
    string line;
    getline(is, line);
    stringstream in(line);
    in>>e.name>>e.date;

    MyLinSearch p;
    StringStreamEnumerator<Fish> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.haslion = p.found();
    return is;
}

class MyEnumerator : public Enumerator<Angler>
{
private:
    SeqInFileEnumerator<Hunt> _f;
    Angler _curr;
    bool _end;
public:
    MyEnumerator(const string &fn) : _f(fn) {}
    void first() {_f.first(); next(); }
    void next() override;
    Angler current() const override { return _curr; }
    bool end() const override { return _end; }
};
class MyOr : public Summation<Hunt, bool>
{
private:
    string _name;
public:
    MyOr(const string &str) : _name(str) {}
protected:
    bool neutral() const override {return false; }
    bool add(const bool &a, const bool &b) const override {return a || b; }
    bool func(const Hunt &e) const override { return e.haslion; }
    void first() override {}
    bool whileCond(const Hunt &e) const override { return e.name == _name; }

};

void MyEnumerator::next()
{
    if(( _end = _f.end())) return;

    _curr.name = _f.current().name;
    MyOr p(_curr.name);
    p.addEnumerator(&_f);
    p.run();

    _curr.haslion = p.result();
}
int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "inut.txt";

    List p(&cout);
    MyEnumerator enor(fname);
    p.addEnumerator(&enor);
    p.run();

    return 0;
}
