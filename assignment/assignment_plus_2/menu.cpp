#include "menu.h"
#include <iostream>
#include <fstream>
using namespace std;
void Menu::run()
{
    int v = 0;
    do
    {
        menuWrite();
        cout << "Choose a menu point: " << endl;
        cin >> v;
        switch(v)
        {
        case 0 :
            cout << "Bye!";
            break;
        case 1:
            case1() ;
            break;
        case 2:
            case2()
            ;
            break;
        case 3:
            case3();
            break;
        case 4:
            case4();
            break;
        case 5:
            case5();
            break;
        default :
            cout << "An integer between 0 and 5 is needed." << endl;
            break;
        }
    }
    while(v != 0);
}

void Menu::menuWrite()
{
    cout << "0-exit\n";
    cout << "1-create\n";
    cout << "2-add\n";
    cout << "3-sub\n";
    cout << "4-mult\n";
    cout << "5-div\n";
}
void Menu::case1()
{
    cout << "Complex number file name: ";
    string fn;
    cin>> fn;
    ifstream inp(fn);
    if(inp.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int a, b;
    inp>>a>>b;
    Complex c(a,b);
    c.print();
}



void Menu::case2()
{
    cout << "First complex number file name: ";
    string fn1;
    cin>> fn1;
    ifstream inp1(fn1);
    if(inp1.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int a, b;
    inp1>>a>>b;
    Complex c1(a,b);
    cout << "Second complex number file name: ";
    string fn2;
    cin>> fn2;
    ifstream inp2(fn2);
    if(inp2.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int c, d;
    inp2>>c>>d;
    Complex c2(c,d);
    Complex c3=c1+c2;
    c3.print();
}
void Menu::case3()
{
    cout << "First complex number file name: ";
    string fn1;
    cin>> fn1;
    ifstream inp1(fn1);
    if(inp1.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int a, b;
    inp1>>a>>b;
    Complex c1(a,b);
    cout << "Second complex number file name: ";
    string fn2;
    cin>> fn2;
    ifstream inp2(fn2);
    if(inp2.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int c, d;
    inp2>>c>>d;
    Complex c2(c,d);
    Complex c3=c1-c2;
    c3.print();
}
void Menu::case4()
{
    cout << "First complex number file name: ";
    string fn1;
    cin>> fn1;
    ifstream inp1(fn1);
    if(inp1.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int a, b;
    inp1>>a>>b;
    Complex c1(a,b);
    cout << "Second complex number file name: ";
    string fn2;
    cin>> fn2;
    ifstream inp2(fn2);
    if(inp2.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int c, d;
    inp2>>c>>d;
    Complex c2(c,d);
    Complex c3=c1*c2;
    c3.print();
}
void Menu::case5()
{
    cout << "First complex number file name: ";
    string fn1;
    cin>> fn1;
    ifstream inp1(fn1);
    if(inp1.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int a, b;
    inp1>>a>>b;
    Complex c1(a,b);
    cout << "Second complex number file name: ";
    string fn2;
    cin>> fn2;
    ifstream inp2(fn2);
    if(inp2.fail())
    {
        cout << "Wrong file name!";
        return;
    }
    int c, d;
    inp2>>c>>d;
    Complex c2(c,d);
    Complex c3=c1/c2;
    c3.print();
}
