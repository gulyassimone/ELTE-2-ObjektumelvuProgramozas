#include <iostream>
#include "library/maxsearch.hpp"
#include "library/linsearch.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

using namespace std;

struct Data {
    string date;
    int weigth;
    int distance;
};

istream& operator>>(istream& is, Data &e)
{
    is >> e.date >> e.weigth >> e.distance;
    return is;
}

class MyLinSearch : public LinSearch<Data> {
protected:
    bool cond(const Data& e) const override { return e.distance<3; }
};

struct BlackHole {
    string name;
    int weigth;
    bool isCLosed;
};
istream& operator>>(istream& is, BlackHole &e)
{
    string line;
    getline(is, line);
    stringstream in(line);

    in >> e.name;

    MyLinSearch p;
    StringStreamEnumerator<Data> enor(in);
    p.addEnumerator(&enor);
    p.run();
    e.isCLosed = p.found();
    e.weigth = p.elem().weigth;

    return is;
}

class myMaxSearch : public MaxSearch <BlackHole, int> {
protected:
    int func(const BlackHole& e) const override { return e.weigth; }
};

int main(int argc, char* argv[])
{
    string fname = argc>1 ? argv[1] : "input.txt";

    myMaxSearch p;
    SeqInFileEnumerator<BlackHole> enor(fname);
    p.addEnumerator(&enor);

    p.run();

    cout << p.optElem().name<< endl;
    return 0;
}
