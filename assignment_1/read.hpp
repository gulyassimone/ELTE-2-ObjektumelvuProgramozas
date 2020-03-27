//Author:    Gregorics Tibor
//Date:     2015.02.22.
//Title:    Universal reading from keyboard

#pragma once

#include <iostream>
#include <string>

//Task: 	Read an Item type data from the keyboard
//Input:    string msg - text that must be written before reading
//          string err - text that must be written after a
//          bool valid(Item) - function that checks the correctness of the data that is read
//Output:   Item  n    - the value the data that is read
//Activity:	Reading a data from the keyboard, checking it according to the function valid
//          if the data is incorrect trying to read it once more
enum Error {INVALID_INPUT, EMPTY_INPUT};
template <typename Item>
Item read( std::istream &s, const std::string &msg, bool valid(Item))
{
    Item n;
    std::cerr << msg;
    s >> n;
    s.clear();
    std::string tmp = "";
    getline(s, tmp);
    if(tmp.size()==0 )
        throw EMPTY_INPUT;
    if(!valid(n))
        throw INVALID_INPUT;
    return n;
}
