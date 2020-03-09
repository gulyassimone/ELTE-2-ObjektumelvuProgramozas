#include <iostream>
#include "matrix.h"

using namespace std;


int Matrix::operator() (unsigned i, unsigned j)
{
    if(i>=size || i<0)
        throw INVALID_ROW;
    if(j>=size || j<0)
        throw INVALID_COLOUMN;
    if(j>=0 && j<=Matrix::getSize()-1 && !(i==j && i==0 && i==size-1 && j==0 && j==size-1))
    {
        return 0;
    }
    bool l=false;
    while(!l)
    {
        if(j==0)
        {
            return matrix[i];
        }
        else if(j==Matrix::getSize()-1)
        {
            return matrix[size+i];
        }
        else
        {
            return matrix[2*size+i];
        }

    }
}

/*Matrix operator+ (const Matrix &e, const Matrix &m)
{
    Matrix sum;
    if(e.getSize()!=m.getSize()) throw INVALID_OPERATION;
    for(unsigned i=0; i<e.getSize(); i++)
    {
        for(unsigned j=0; j<e.getSize(); j++)
        {
            sum=e(i,j)+m(i,j);
        }
    }
    return sum;
}

Matrix operator* (const Matrix &e, const Matrix &m)
{
    Matrix mult;
    if(e.getSize()!=m.getSize()) throw INVALID_OPERATION
    for(unsigned i=0; i<m.size(); i++))
    {
        for(unsigned j=0; j<m.getSize(); j++))
        {
            for(int j=0; k<m.getSize(); k++))
            {
                mult(i, j)+=e(i,k)*m(k,j)
            }
        }
    }
}*/
ostream& operator<< (std::ostream& s, const Matrix &m)
{
    s << "<------------------------------------------------>\n";
    s << "<-------------------N Matrix--------------------->\n";
    s << "<------------------------------------------------>\n";

    s<< "Size: " << m.getSize() << "x" << m.getSize() << "\n Data: \n" <<endl;
    for(unsigned i=0; i<m.getSize() ; i++)
        for(unsigned j=0; j<m.getSize() ; j++)
        {
            s<< m(i,j);
        }
    s << "<------------------------------------------------>\n";

}
