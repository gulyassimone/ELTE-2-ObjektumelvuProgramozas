#include <iostream>
#include <sstream>
#include "summation.hpp"
#include "seqinfileenumerator.hpp"
#include "linsearch.hpp"
#include "stringstreamenumerator.hpp"

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
class MyLinSearch : public LinSearch<Fish, false>
{
protected:
    bool cond(const Fish &e) const override
    {
        return e.species.length()>0;
    }
};
struct Angler
{
    string name;
    string competetiveId;
    bool hascatch;
};
ostream& operator <<(ostream &os,const Angler &e)
{
    cout << " nev: " << e.name << " verseny: " << e.competetiveId;
    return os;
}

istream& operator >>(istream &is, Angler &e)
{
    string line;
    getline(is, line);
    stringstream in(line);
    in>>e.name>>e.competetiveId;
    MyLinSearch p;
    StringStreamEnumerator<Fish> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.hascatch = p.found();

    return is;
}

class UnluckySearch : public LinSearch<Angler>
{
protected:
    bool cond(const Angler &e) const override
    {
        return e.hascatch==false;
    }
};
int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "input.txt";

    UnluckySearch p;
    SeqInFileEnumerator<Angler> enor(fname);
    p.addEnumerator(&enor);
    p.run();
    cout << p.elem() << endl;

    return 0;
}
