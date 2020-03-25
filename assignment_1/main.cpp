//Author:   Gulyás Simone
//Date:     2020.03.09
//Title:    N matrix
#include <iostream>
#include "menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE




int main()
{
    Menu menu;
    menu.run();
    return 0;
}
#else
enum status {abnorm, norm};
bool read(ifstream &f, Matrix &e, Status &st);

bool read(ifstream &f, Matrix &e, Status &st)
{
    String line;
    getline(f,line);
    if(!f.fail() && line!= "")
    {
        int numberOfColumn;
        Matrix m;
        st=norm;
        ifstringstream in(line);
        in>>numberOfColumn;

        in >>m;





    }
}
#endif // NORMAL_MODE
