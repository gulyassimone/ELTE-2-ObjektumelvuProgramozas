#pragma once
#include <vector>
#include <iostream>
#include "read.hpp"

inline bool valid(int a)
{
    return true;
}
struct Item
{
    int key;
    std::string data;
    Item() {};
    Item(int p, std::string s):key(p),data(s) {}
    bool operator==(const int &key)
    {
        return(key==this->key);
    }
    Item operator=(Item &item)
    {
        item.key=key;
        item.data=data;
        return item;
    }

    friend std::istream& operator>>(std::istream& s,  Item& e)
    {
        e.key=read<int>("Please type a key: ","Please type an Integer", valid );
        std::cout<<"Inserting data: ";
        s >> e.data;
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s << "(" << e.key << ", " << e.data <<")";
        return s;
    }
};

class AT
{
public:
    enum ATError {EMPTY_AT,ALREADY_EXISTS_KEY, NOT_EXISTS_KEY};

    void setEmpty();
    unsigned int count() const;
    void insert(Item &item);
    void erase(int &key);
    int searchItem(const int &key) const;

    friend std::ostream& operator<<(std::ostream& s, const AT& at);
private:
    std::vector<Item> _vec;
    int Search(int &key);
};
