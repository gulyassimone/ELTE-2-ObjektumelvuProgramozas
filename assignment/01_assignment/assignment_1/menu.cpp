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
inline bool int_valid(int a)
{
    return true;
}
inline bool unsigned_valid(unsigned a)
{
    return true;
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

    v=read<int>(cin,"Your choose: ", "Please type an integer from 0 to 6", check);
    return v;
}
void Menu::getElement() const
{
    int i, j;

    i=read<unsigned>(cin,"row = ","Type an unsigned integer", unsigned_valid);
    j=read<unsigned>(cin,"coloumn = ","Type an unsigned integer", unsigned_valid);


    try
    {
        cout << "a["<<i<<"," <<j<<"]= " << a.write(i-1, j-1) << endl;
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

    unsigned i, j;
    int e;

    i=read<unsigned>(cin,"row = ","Type an unsigned integer", unsigned_valid);
    j=read<unsigned>(cin,"coloumn = ","Type an unsigned integer", unsigned_valid);
    e=read<int>(cin,"data = ", "Type an integer",int_valid);
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
        else if (ex==Matrix::NULLPART)
        {
            cout << "This part must be 0! "<< endl;
        }
        else
        {
            cout << "Unhandle exception!"<<endl;
        }
    }

}

void Menu::readMatrix()
{
    cerr<<"Give a number of coloumn and data of Matrix!" << endl;
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
        else
        {
            cout << "Unhandled exception!" << endl;
        }

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

        cerr << "Give second matrix: " << endl;
        cin >> b;
        cerr << "Sum of the matrixes" << endl;
        cout << "A matrix: \n"<< a  << " + \n" << "b matrix: \n"<< b << " = \n Result: \n" <<a + b << endl;
    }
    catch(Matrix::matrixError ex)
    {
        if(ex==Matrix::INVALID_OPERATION)
        {
            cout << "Different sizes! " << endl;
        }
        else if (ex==Matrix::NULLPART)
        {
            cout << "This part must be 0! "<< endl;
        }
        else
        {
            cout << "Unhandled exception!" << endl;
        }
    }
}
void Menu::mul()
{
    try
    {
        Matrix b;
        cerr << "Give the size and the items of the second matrix: "<<endl;
        cin >> b;
        cerr <<"Multiply of the matrixes: " << endl;
        cout << "A matrix: \n"<< a  << " * " << "B matrix: \n"<< b << " = \n Result: \n" <<a * b << endl;
    }
    catch(Matrix::matrixError ex)
    {
        if(ex==Matrix::INVALID_OPERATION)
        {
            cout << "Different sizes! "<< endl;
        }
        else if (ex==Matrix::NULLPART)
        {
            cout << "This part must be 0! "<< endl;
        }
        else
        {
            cout << "Unhandled exception!" << endl;
        }
    }
}
