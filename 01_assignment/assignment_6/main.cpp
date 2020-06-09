#include <iostream>
#include <fstream>

#include "enor.h"

using namespace std;
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {
        Enor orderList("input.txt");
        Order max;

        for(orderList.first(); !orderList.end(); orderList.next())
        {
            if(orderList.current().price>max.price)
            {
                max=orderList.current();
            }
        }

        cout << "The winner food name: "<< max.food << endl;

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }


    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("empty", "inp0.txt")
{

    try
    {
        Enor orderList("inp0.txt");
        Order max;
        int c=0;

        for(orderList.first(); !orderList.end(); orderList.next())
        {
            c++;
        }

        CHECK(0==c);

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("first", "inp1.txt")
{

    try
    {
        Enor orderList("inp1.txt");
        Order max;

        for(orderList.first(); !orderList.end(); orderList.next())
        {
             if(orderList.current().price>max.price)
            {
                max=orderList.current();
            }
        }

        CHECK(max.food.compare("A"));

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}
TEST_CASE("second", "inp2.txt")
{

    try
    {
        Enor orderList("inp2.txt");
        Order max;

        for(orderList.first(); !orderList.end(); orderList.next())
        {
             if(orderList.current().price>max.price)
            {
                max=orderList.current();
            }
        }

        CHECK(max.food.compare("C"));

    }
    catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
        {
            cout << "Wrong filename!";
        }
    }
}

TEST_CASE("exception", "inp3.txt")
{

    try
    {
        Enor orderList("inp3.txt");
        Order max;

        for(orderList.first(); !orderList.end(); orderList.next())
        {
             if(orderList.current().price>max.price)
            {
                max=orderList.current();
            }
        }

    }
    catch(Enor::Errors err)
    {
        CHECK(err==Enor::FILEERROR);
    }
}
#endif
