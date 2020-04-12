#ifndef ENOR_H
#define ENOR_H
#include <string>
#include <fstream>
#include <iostream>

struct angler
{
    std::string anglerId;
    std::string contestId;
    bool isCatfish;
    bool isNotCatfish;
    int sizeOfFish;
    friend std::ostream& operator<<(std::ostream& s, const angler& e)
    {
        s << " Horgász: " << e.anglerId << " Verseny: " << e.contestId << std::endl;
        return s;
    }
};

struct inputAngler
{
    std::string anglerId;
    std::string contestId;
    std::string fish;
    int sizeOfFish;

};
class Angler
{
public:

    enum error {FILE_NAME_ERROR};
    Angler(std::string filename);
    Angler();
    void first()
    {
        next();
    };
    void next();
    bool end()
    {
        return _end;
    };
    angler current()
    {
        return _curr;
    };

private:
    std::ifstream _x;
    inputAngler _dx;
    angler _curr;
    bool _end;

};

#endif // ENOR_H
