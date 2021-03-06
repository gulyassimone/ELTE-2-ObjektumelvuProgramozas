//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix
#include <iostream>
#include "matrix.h"
#include "read.hpp"

using namespace std;
inline bool valid(int a)
{
    return true;
}
inline bool unsig_valid(unsigned a)
{
    return true;
}

int Matrix::getVectorIndex (const unsigned i, const unsigned j) const
{
    if(!(i<Matrix::getSize() && i>=0 && j<Matrix::getSize() && j>=0))
        throw OVERINDEXED;
    if(j==0)
    {
        return i;
    }
    else if(j==Matrix::getSize()-1)
    {
        return Matrix::getSize()+i;
    }
    else if (i==j)
    {
        return 2*Matrix::getSize()+i;
    }
    return -1;

}
int Matrix::write( const unsigned i,  const unsigned j) const
{
    int ind = getVectorIndex(i,  j);
    return ind>-1?_v[ind]:0;
}
void Matrix::setElemValue (const unsigned i, const unsigned j, int data)
{

    int ind = Matrix::getVectorIndex(i, j);
    if(!(ind>-1))
        throw NULLPART;
    _v[ind] = data;

}

Matrix Matrix::operator+ ( const Matrix &m)
{

    if(Matrix::getSize()!=m.Matrix::getSize())
        throw INVALID_OPERATION;
    Matrix sum;
    sum.setSize(getSize());
    for(unsigned i=0; i<Matrix::getSize(); i++)
    {
        for(unsigned j=0; j<Matrix::getSize(); j++)
        {
            int ind=getVectorIndex(i,j);

            if(ind>-1)
            {
                sum._v[ind]=write(i,j)+m.write(i,j);
            }
        }
    }
    return sum;
}

Matrix Matrix::operator* ( Matrix &m)
{

    if(Matrix::getSize()!=m.getSize())
        throw INVALID_OPERATION;
    Matrix mult;
    mult.setSize(getSize());
    for(unsigned i=0; i<Matrix::getSize(); i++)
    {
        for(unsigned j=0; j<Matrix::getSize(); j++)
        {
            int ind=getVectorIndex(i,j);
            for(unsigned k=0; k<Matrix::getSize(); k++)
            {
                if(ind>-1)
                {
                    mult._v[ind]+=write(i,k)*m.write(k,j);
                }
            }
        }
    }
    return mult;
}

ostream& operator<< (ostream& s, const Matrix &m)
{

    for(unsigned i=0; i<m.getSize() ; i++)
    {
        for(unsigned j=0; j<m.getSize() ; j++)
        {
            s<< m.write(i,j) << " ";
        }
        s<<endl;
    }

    return s;
}


istream& operator>> (istream& s, Matrix &m)
{
    unsigned a;
    a=read<unsigned>(s,"size of matrix: ", "Type an integer!", unsig_valid);
    m.setSize(a);
    for(unsigned i=0; i<a ; i++)
    {
        for(unsigned j=0; j<a ; j++)
        {
            int ind = m.getVectorIndex(i,j);
            cerr << i<< " row " << j << " coloumn";
            if(ind>-1)
            {
                m._v[ind]=read<int>(s, " data: ","Type an integer!", valid);
            }
            else
            {
                int c;
                c=read<int>(s," data: ","Type an integer!", valid);
                if(c!=0)
                    throw Matrix::NULLPART;
            }
        }
    }
    return s;
}
