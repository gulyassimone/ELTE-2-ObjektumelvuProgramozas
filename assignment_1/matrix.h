#pragma once
#include <vector>


class Matrix
{
public:
    enum matrixError {INVALID_ROW, INVALID_COLOUMN, INVALID_OPERATION};
  /*  int getSize() {return size;};
    int operator() (int i, int j);
    Matrix operator+ (const Matrix &m) const;
    Matrix operator* (const Matrix &m) const;
    friend std::ostream& operator<< (std::ostream& s, const Matrix &m);*/
    friend std::istream& operator>> (std::istream& s, const Matrix &m);

private:
    int size;
    std::vector<int> matrix;
};
