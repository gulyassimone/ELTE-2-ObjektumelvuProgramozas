#pragma once
#include <iostream>
#include <math.h>


class Complex
{
private:
    double _real, _imag;

public:
    Complex():_real(0), _imag(0) {}
    Complex(double a):_real(a), _imag(0) {}
    Complex(double a, double b):_real(a), _imag(b) {}

    Complex operator+(const Complex &mc)const
    {
        return Complex(_real+mc.get_real(), _imag+mc.get_imag());
    }

    Complex operator-(const Complex &mc)const
    {
        return Complex(_real-mc.get_real(), _imag-mc.get_imag());
    }

    Complex operator*(const Complex &mc)const
    {
        return Complex(_real*mc.get_real()-_imag*mc.get_imag(), _imag*mc.get_real()+_real*mc.get_imag());
    }

    Complex operator/(const Complex &mc)const
    {
        double a=(_real*_imag+_imag*mc.get_imag())/(pow(mc.get_real(),2)+pow(mc.get_imag(),2));
        double b=(_imag*mc.get_real()-_real*mc.get_imag())/(pow(mc.get_real(),2)+pow(mc.get_imag(),2));
        return Complex(a,b) ;
    }

    void print()
    {
        std::cout<<_real<<"+"<<_imag<<"i"<<std::endl;
    }
    double get_real() const
    {
        return _real;
    }
    double get_imag() const
    {
        return _imag;
    }


};
