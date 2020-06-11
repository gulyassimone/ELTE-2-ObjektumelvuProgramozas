//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix

#pragma once
#include <vector>
#include "read.hpp"

//class of N matrices

class Matrix
{
public:
    enum matrixError {OVERINDEXED, INVALID_OPERATION, NULLPART};

    int write( const unsigned i,  const unsigned j) const;
    void setElemValue (const unsigned i, const unsigned j, int data);
    unsigned getSize()const
    {
        return (_v.size()+1)/3;
    };
    void setSize(int a)
    {
        _v.resize(3*a-1);
    };
    Matrix operator+ (const Matrix &m);
    Matrix operator* ( Matrix &m);
    friend std::ostream& operator<< (std::ostream& s, const Matrix &m);
    friend std::istream& operator>> (std::istream& s, Matrix &m);

private:
    std::vector<int> _v;
    int getVectorIndex (const unsigned i, const unsigned j) const;
};
