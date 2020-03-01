#include "associativeArray.h"


using namespace std;


void AT::setEmpty()
{
    _vec.clear();
}

unsigned int AT::count() const
{
    return _vec.size();
}
void AT::insert(Item &item)
{
    if(_vec.size()!=0 && Search(item.key))
        throw ALREADY_EXISTS_KEY;
    _vec.push_back(item);
}
void AT::erase( int &key)
{
    if(!Search(key))
        throw NOT_EXISTS_KEY;
    int ind;
    ind=Search(key);
    _vec[ind]=_vec[_vec.size()];
    _vec.pop_back();

}
Item AT::searchItem(const int &key) const
{
    int i=0;
    if(_vec.size()==0)
        throw EMPTY_AT;
    while (_vec[i].key!=key)
    {
        i++;
    }
    return _vec[i];
}
int AT::Search( int &key)
{
    bool find=false;

    for(unsigned int i=0; i<_vec.size(); i++)
    {
        if(_vec[i].key==key)
        {
            find=true;
        }
    }

    return find;
}
ostream& operator << (std::ostream& s, const AT& at)
{
    s << "\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
    s << "Associative array: \n";
    s << "Size: " << at._vec.size() << "\n Datas: \n ";
    for(unsigned i=0; i<at._vec.size(); ++i)
    {
        s << " " << at._vec[i];
    }
    s << "\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n";
    return s;
}
