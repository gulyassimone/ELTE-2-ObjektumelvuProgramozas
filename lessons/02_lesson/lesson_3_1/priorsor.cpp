//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Prioritásos sor forrás kódja

#include "priorsor.h"

using namespace std;

void PrQueue::add(const Item &a) //referenciaszeruen kell atadni
{
    _vec.push_back(a);
}

Item PrQueue::remMax()
{
    if(_vec.size()==0) throw EMPTY_PRQUEUE;
    int ind = maxindex();
    Item uj = _vec[ind];
    _vec[ind] = _vec[_vec.size()-1]; //Az utolsó elemet áttesszük a kivett elem helyére
    _vec.pop_back();
    return uj;
}

Item PrQueue::max() const
{
    if(_vec.size()==0) throw EMPTY_PRQUEUE;
    int ind = maxindex();
    return Item(_vec[ind]);
}

int PrQueue::maxindex() const
{
    int ind = 0;
    int maxkey = _vec[0].pr;
    for(unsigned i=1; i<_vec.size(); ++i){
        if(_vec[i].pr>maxkey){
            ind = i;
            maxkey = _vec[i].pr;
        }
    }
    return ind;
}

ostream& operator<<(std::ostream& s, const PrQueue& q)
{
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s << "PrQueue jellemzoi:\n";
    s << "Memória foglalás:" << q._vec.capacity() << " Elemszam:" << q._vec.size() << "\nTartalma: " << endl;
    for(unsigned i=0; i<q._vec.size(); ++i){
        s << " (" << q._vec[i].pr << "," << q._vec[i].data << ")";
    }
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

vector<Item> PrQueue::getItems() const
{
    vector<Item> v;
    for(unsigned i=0; i<_vec.size(); ++i)
        v.push_back(_vec[i]);
    return v;
}
