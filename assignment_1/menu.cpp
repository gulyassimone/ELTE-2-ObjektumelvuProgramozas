#include "menu.h"
#include <iostream>
#include <sstream>
#include "read.hpp"

#define MENU_DB 6

using namespace std;

bool check(int n)
{
    return 0<=n && n<=MENU_DB;
}

void Menu::run()
{
    int v;
    do
    {
        v=menuWrite();
        switch(v)
        {
        case 1:
            getElement();
            break;
        case 2:
            setElement();
            break;
        case 3:
            readMatrix();
            break;
        case 4:
            writeMatrix();
            break;
        case 5:
            sum();
            break;
        case 6:
            mul();
            break;
        }
    }
    while (v!=0);
}
int Menu::menuWrite()
{
    int v;

    cout << endl << endl;
    cout << "0. - Quit" << endl;
    cout << "1. - Get an element of the matrix" << endl;
    cout << "2. - OverWrite an element of the matrix" << endl;
    cout << "3. - Read matrix" << endl;
    cout << "4. - Write matrix" << endl;
    cout << "5. - Add matrixes" << endl;
    cout << "6. - Multiply matrixes" << endl << endl;
    cout << "Type a number of menu!"<< endl;

    ostringstream s;
    s<<"Write between 0 and "<<MENU_DB<<"!"<<endl;
    string errmsg=s.str();
    v=read<int>("Your choose: ", errmsg, check);
    return v;
}
void Menu::getElement() const
{
    int i, j;

    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the coloumn: ";
    cin >> j;

    try
    {
        cout << "a["<<i<<"," <<j<<"}= " << a.write(i-1, j-1) << endl;
    }
    catch(Matrix::matrixError ex)
    {
        if (ex==Matrix::OVERINDEXED)
        {
            cout << "Overindexing!"<<endl;
        }
        else
        {
            cout << "Unhandle exception!"<<endl;
        }
    }
}
void Menu::setElement()
{
    int i, j, e;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the coloumn: ";
    cin >> j;
    cout << "Give the value: ";
    cin >> e;
    try
    {
        a.setElemValue(i-1,j-1,e);
    }
    catch(Matrix::matrixError ex)
    {
        if (ex == Matrix::OVERINDEXED)
        {
            cout << "Overindexing!"<<endl;
        }
        else if (ex == Matrix::NULLPART)
        {
            cout << "These indexes do not point to the n matrix!"<<endl;
        }
        else
        {
            cout << "Unhandle exception!"<<endl;
        }
    }
}

void Menu::readMatrix()
{
    try
    {
        cin >>a;
    }
    catch(Matrix::matrixError ex)
    {
        if(ex==Matrix::OVERINDEXED)
        {
            cout << "Overindexed!" << endl;
        }
        else if(ex==Matrix::NULLPART)
        {
            cout << "This elem must be 0" <<endl;
        }
        cout << "Unhandled exception!" << endl;
    }
}
void Menu::writeMatrix()
{
    cout << a<< endl;;
}
void Menu::sum()
{
    try
    {
        Matrix b;

        cout << "Give second matrix: " << endl;
        cin >> b;
        cout << "Sum of the matrixes" << endl;
        cout << "A matrix: \n"<< a  << " + \n" << "b matrix: \n"<< b << " = \n Result: \n" <<a + b << endl;
    }
    catch(Matrix::matrixError ex)
    {
        if(ex==Matrix::INVALID_OPERATION)
        {
            cout << "Different sizes! " << endl;
        }
    }
}
void Menu::mul()
{
    try
    {
        Matrix b;
        cout << "Give the size and the items of the second matrix: "<<endl;
        cin >> b;
        cout <<"Multiply of the matrixes: " << endl;
        cout << "A matrix: \n"<< a  << " * " << "B matrix: \n"<< b << " = \n Result: \n" <<a * b << endl;
    }
    catch(Matrix::matrixError ex)
    {
        if(ex==Matrix::INVALID_OPERATION)
        {
            cout << "Different sizes! "<< endl;
        }
    }
}
