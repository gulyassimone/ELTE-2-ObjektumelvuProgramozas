#pragma once

#include <vector>

class Surface
{
    private:
        std::vector<int> x;
        bool l=false;
        int max, ind;
        unsigned int n=x.size();
    public:
        Surface(vector<int> x);
        int largest_dent();
}