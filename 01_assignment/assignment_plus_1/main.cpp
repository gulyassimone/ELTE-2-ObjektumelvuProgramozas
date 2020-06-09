#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int mostFrequency(vector<int> x, unsigned n);
void output(int ind, vector<int> x, unsigned n);

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
    unsigned int n=x.size();

    int ind=mostFrequency(x, n);
    output(ind, x, n);

    return 0;
}

int mostFrequency(vector<int> x, unsigned n)
{

    int max=1, ind=0;

    for (unsigned int i=0; i<n; i++)
    {
        int db=1;
        for( unsigned int j=i+1; j<n; j++)
        {
            if(x[i]==x[j])
            {
                db++;
            }
        }
        if(max<db)
        {
            max=db;
            ind=i;
        }
    }
    return ind;
}

void output(int ind, vector<int> x, unsigned n)
{
    cout << "A tömb legsűrűbben előforduló eleme: " << x[ind] << endl;
    cout << "A tömb elemei: " ;
    for(unsigned int i=0; i<n; i++)
    {
        cout << x[i] << " ";
    }
}
