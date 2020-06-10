#include <iostream>

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Score
{
    string name;
    bool rich;
};

enum Status {abnorm, norm};

bool read(ifstream &f, Score &e, Status &st)
{
    string line;
    getline(f,line);
    if (!f.fail() && line!="")
    {
        st = norm;
        istringstream in(line);
        string product="";
        int price;
        in>>price;
        e.rich = true;

        while(in.fail())
        {
            in.clear();
            e.name+= " " + product;
            in >> product;
            in >> price;
        }

        e.rich = e.rich && price>=20000;

        while( in >> product >> price )
        {
            e.rich = e.rich && price>=20000;
        };
    }
    else
        st=abnorm;

    return norm==st;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    ifstream x("inp1.txt");
    if (x.fail() )
    {
        cout << "Wrong filename!\n";
        return 1;
    }

    Score dx;
    Status sx;
    bool l = false;
    while(read(x,dx,sx) && !l)
    {
        l = l || dx.rich  ;

    }


    cout <<((l) ? "Exist rich customer " : "Not exist rich customer ") <<endl;
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("empty", "inp0.txt")
{
    ifstream x("inp0.txt");REQUIRE(!x.fail());

    Score dx;
    Status sx;
    bool l = false;
    while(read(x,dx,sx) && !l)
    {
        l = l || dx.rich  ;

    }
    CHECK(l==false);
}

TEST_CASE("one", "inp1.txt")
{
    ifstream x("inp1.txt");
    REQUIRE(!x.fail());
    Score dx;
    Status sx;
    bool l = false;
    while(read(x,dx,sx) && !l)
    {
        l = l || dx.rich  ;

    }
    CHECK(l==false);
}

TEST_CASE("two", "inp3.txt")
{
    ifstream x("inp3.txt");
    REQUIRE(!x.fail());
    Score dx;
    Status sx;
    bool l = false;
    while(read(x,dx,sx) && !l)
    {
        l = l || dx.rich  ;

    }
    CHECK(l==true);
}
TEST_CASE("three", "inp4.txt")
{
    ifstream x("inp4.txt");
    REQUIRE(!x.fail());
    Score dx;
    Status sx;
    bool l = false;
    while(read(x,dx,sx) && !l)
    {
        l = l || dx.rich  ;

    }
    CHECK(l==true);
}
#endif
