#ifndef ENOR_H
#define ENOR_H
#include <fstream>

struct Recipe
{
    std::string recipe;
    bool needsSugar;
};
class Enor
{
public:
    enum Status {norm,abnorm};
    enum Errors {FILE_NAME_ERROR};
    Enor(std::string x);
    void first()
    {
        read();
        next();
    };
    void next();
    Recipe current() const
    {
        return _curr;
    };
    bool end()const
    {
        return _end;
    };
private:
    struct inpurRecipe
    {
        std::string recipe;
        std::string ingredient;
        int amount;
        std::string measure;
    };
    std::fstream _x;
    inpurRecipe _dx;
    Status _sx;
    Recipe _curr;
    bool _end;

    void read();
};

#endif // ENOR_H
