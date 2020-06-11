#ifndef CONTEST_H
#define CONTEST_H
#include "angler.h"

struct contest
{
    std::string contestId;
    bool isCatfish;
    bool isNotCatfish;
    friend std::ostream& operator<<(std::ostream& s, const contest& e)
    {
        s << " Verseny: " <<  e.contestId <<std::endl;
        return s;
    }
};

class Contest
{
public:
    Contest(std::string filename): _tt(filename) {};
    void first()
    {
        _tt.next();
        next();
    };
    void next();
    contest current()
    {
        return _curr;
    };
    bool end()
    {
        return _end;
    };

private:
    Angler _tt;
    std::ifstream _x;
    contest _curr;
    bool _end;
};

#endif // CONTEST_H
