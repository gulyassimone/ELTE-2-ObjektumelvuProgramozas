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
        for(Trophy<int>* i:rhinoTrophies)
            delete i;
        for(Trophy<std::string>* i:lionTrophies)
            delete i;
        for(Trophy<IvoryLength>* i:elephantTrophies)
            delete i;
    }
    int MaleLionTrophiesCount();
    std::string getName()
    {
        return name;
    }
private:
    std::string name;
    int age;
    std::vector<Trophy<int>*> rhinoTrophies;
    std::vector<Trophy<std::string>*> lionTrophies;
    std::vector<Trophy<IvoryLength>*> elephantTrophies;
};

#endif // HUNTER_H
