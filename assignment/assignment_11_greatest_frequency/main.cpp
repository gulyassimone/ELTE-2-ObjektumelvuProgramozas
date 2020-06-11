#include <iostream>
#include "library/counting.hpp"
#include "library/maxsearch.hpp"
#include "library/arrayenumerator.hpp"
#include "library/intervalenumerator.hpp"
#include <vector>

using namespace std;


//class of counting of ingredients including sugar
//overrides the method cond()
class MyCounting : public Counting<int>
{
private:
    int a;
public:
    MyCounting(const int a) : a(a) {}
protected:
    bool cond(const int &e) const override
    {
        return e==a;
    }
};

class MyMaxSearch : public MaxSearch<int>
{
private:
    vector<int> _x;
public:
    MyMaxSearch(vector<int> x) : _x(x) {}
protected:
    int  func(const int& e) const override
    {
        MyCounting pr(e);

        ArrayEnumerator<int> enor(&_x);
        pr.addEnumerator(&enor);
        pr.run();
        return pr.result();
    }

};

int main()
{

    vector<int> t= {1, 2, 3, 4, 5, 6, 7, 8, 10, 1, 3, 4, 5, 3, 6, 3, 2, 3};
    MyMaxSearch pr(t);
    ArrayEnumerator<int> enor(&t);
    pr.addEnumerator(&enor);

    pr.run();

    cout << "A legtobbszor elofordulo szam: " << pr.optElem();

    return 0;
}

