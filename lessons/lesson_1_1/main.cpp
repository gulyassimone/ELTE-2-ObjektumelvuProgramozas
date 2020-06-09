#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream f( "input.txt" );
    if( f.fail() )
    {
        cout << "File open error!\n";
        return 1;
    }
    vector<int> x;
    int e;
    while( f >> e )
    {
        x.push_back(e);
    }
    bool l=false;
    int max, ind;
    unsigned int n=x.size();


    for(unsigned int i=2; i<n-1; i++)
    {
        if(l && (x[i-1] >= x[i] && x[i]<= x[i+1] ))
        {
            if(max<x[i])
            {
                ind=i;
                max=x[i];
            }
        }
        else if( !l && (x[i-1]>= x[i] && x[i] <= x[i+1]))
        {
            l=true;
            max=x[i];
            ind=i;
        }

    }


    for(unsigned int i=0; i<n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "index " << ind << " max "<< max<<endl;
    return 0;
}
