#include "menu.h"
#include <iostream>
#include <sstream>
#include "read.hpp"
#define menudb 6

using namespace std;

bool check(int a)
{
    return a>0 && a<=menudb;
}

void Menu::run()
{
    int v;
    do
    {
        v=getMenuPoint();
        switch(v)
        {
        case 1:
            Menu::setEmpty();
            break;
        case 2:
            Menu::count();
            break;
        case 3:
            Menu::insert();
            break;
        case 4:
            Menu::erase();
            break;
        case 5:
            Menu::search();
            break;
        case 6:
            Menu::write();
            break;
        default:
            cout << "\n Bye!\n";
            break;
        }
    }
    while (v!=0);
}

int Menu::getMenuPoint()
{
    int v;
    cout << "\n <------------------------------------------------->\n";
    cout << "0. Quit\n";
    cout << "1. Set Empty\n";
    cout << "2. Count\n";
    cout << "3. Insert\n";
    cout << "4. Erase\n";
    cout << "5. Search an element\n";
    cout << "6. Write all data\n";
    cout << "\n <------------------------------------------------->\n";
    ostringstream s;
    s<<"Write between 0 and "<<menudb<<"!"<<endl;
    string errmsg=s.str();
    v=read<int>("Valasztas: ", errmsg, check);

    return v;
}

void Menu::setEmpty()
{
    at.setEmpty();
    cout << "The program cleared data from the array!\n";
}
void Menu::count()
{
    cout << "The array size: "<< at.count() << endl;
}
void Menu::insert()
{
    bool incident=false;
    Item e;
    cout << "Please type an element: " << endl;
    cin >> e;
    try
    {
        at.insert(e);
    }
    catch(AT::ATError err)
    {
        incident=true;
        if(err==AT::ALREADY_EXISTS_KEY)

            cerr << "The insert failed. The key's already exists. " <<endl;
        else
            cerr << "This is a bug. Please contact the programmer! " <<endl;
    }
    if(!incident)
        cout << "The inserted data: " << e << endl;
}
void Menu::erase()
{
    bool incident=false;
    int e;
    cout<<"Please type a key: ";
    cin >> e;
    try
    {
        at.erase(e);
    }
    catch(AT::ATError err)
    {
        incident=true;
        if(err==AT::NOT_EXISTS_KEY)
            cerr << "The erase failed. The key's not exists. " <<endl;
        else if(err==AT::EMPTY_AT)
            cerr << "The search is failed. The array is empty. " <<endl;
        else
            cerr << "This is a bug. Please contact the programmer! " <<endl;
    }
    if(!incident)
        cout << "The erased key: " << e << endl;
}
void Menu::search()
{
    Item b;
    bool incident=false;
    int e;
    cout<<"Please type a key: ";
    cin >> e;
    try
    {
        at.searchItem(e);
    }
    catch(AT::ATError err)
    {
        incident=true;
        if(err==AT::NOT_EXISTS_KEY)
            cerr << "The search is failed. The key's not exists. " <<endl;
        else if(err==AT::EMPTY_AT)
            cerr << "The search is failed. The array is empty. " <<endl;
        else
            cerr << "This is a bug. Please contact the programmer! " <<endl;
    }
    if(!incident)
        cout << "The found data: " << b << endl;
}
void Menu::write()
{
    cout <<  at;
}
