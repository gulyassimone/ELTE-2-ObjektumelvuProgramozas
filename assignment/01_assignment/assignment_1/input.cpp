//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix

#include <iostream>
#include <fstream>

using namespace std;

enum Errors{ WRONG_FILE_NAME };

ifstream openInputFile()

ifstream openInputFile(const string &fnev)
{
    ifstream f(fnev.c_str());
    ig(f.fail())
        throw WRONG_FILE_NAME;
    return f;
}
