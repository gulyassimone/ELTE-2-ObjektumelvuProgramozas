#ifndef HUNTER_H
#define HUNTER_H
#include <vector>
#include "trophy.h"


class Hunter
{
    public:
        enum error{WRONG_FILENAME,UNEXPECTED_SPIECES};
        Hunter(string filename);
        int MaleLionTrophyCount();
    private:
        std::string name;
        int age;
        std::vector<Trophy> trophies;

};

#endif // HUNTER_H
