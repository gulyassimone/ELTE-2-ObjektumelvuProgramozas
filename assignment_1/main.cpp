//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix
#include <iostream>

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
#include "menu.h"



int main()
{
    Menu menu;
    menu.run();
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include <fstream>
#include "catch.hpp"
#include "matrix.h"
#include "read.hpp"



TEST_CASE("create", "inp1.txt")
{
    Matrix a;
    ifstream x("inp0.txt");
    REQUIRE(!x.fail());
    try
    {
        x>>a;
    }
    catch(Error ex)
    {
        CHECK(ex==EMPTY_INPUT);
    }

    Matrix b;
    ifstream y("inp1.txt");
    REQUIRE(!y.fail());
    y>>b;
    CHECK(b.write(0,0)==1);


    Matrix c;
    ifstream z("inp2.txt");
    REQUIRE(!z.fail());
    z>>c;
    CHECK(c.write(0,0)==1);
    CHECK(c.write(0,1)==0);
    CHECK(c.write(0,2)==1);
    CHECK(c.write(1,0)==1);
    CHECK(c.write(1,1)==1);
    CHECK(c.write(1,2)==1);
    CHECK(c.write(2,0)==1);
    CHECK(c.write(2,1)==0);
    CHECK(c.write(2,2)==1);

    Matrix d;
    ifstream v("inp3.txt");
    REQUIRE(!v.fail());
    v>>d;
    CHECK(d.write(0,0)==1);
    CHECK(d.write(0,1)==0);
    CHECK(d.write(0,2)==0);
    CHECK(d.write(0,3)==0);
    CHECK(d.write(0,4)==1);
    CHECK(d.write(1,0)==1);
    CHECK(d.write(1,1)==1);
    CHECK(d.write(1,2)==0);
    CHECK(d.write(1,3)==0);
    CHECK(d.write(1,4)==1);
    CHECK(d.write(2,0)==1);
    CHECK(d.write(2,1)==0);
    CHECK(d.write(2,2)==1);
    CHECK(d.write(2,3)==0);
    CHECK(d.write(2,4)==1);
    CHECK(d.write(3,0)==1);
    CHECK(d.write(3,1)==0);
    CHECK(d.write(3,2)==0);
    CHECK(d.write(3,3)==1);
    CHECK(d.write(3,4)==1);
    CHECK(d.write(4,0)==1);
    CHECK(d.write(4,1)==0);
    CHECK(d.write(4,2)==0);
    CHECK(d.write(4,3)==0);
    CHECK(d.write(4,4)==1);
}
#endif // NORMAL_MODE
