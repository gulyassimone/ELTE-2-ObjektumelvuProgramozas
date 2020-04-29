#ifndef HUNTER_H
#define HUNTER_H
#include <string>
#include <vector>
#include "trophy.h"


class Hunter
{
public:
    enum error {WRONG_FILENAME,UNEXPECTED_SPIECES, UNEXPECTED_DATA};

    Hunter(std::string filename);
    ~Hunter()
    {
        for(Trophy* i:trophies)
            delete i;
    }
    int MaleLionTrophyCount();
    std::string getName()
    {
        return name;
    }
private:
    std::string name;
    int age;
    std::vector<Trophy*> trophies;

};

#endif // HUNTER_H
