#pragma once

#include <vector>

class Registration
{
public:
    virtual int getSize() const = 0;
    virtual ~Registration(){}
};

class File : public Registration
{
public:
    File(int s) : _size(s) {};
    void setSize(int s) { _size = s; }
    int getSize() const override { return _size;}
protected:
    int _size;
};

class Folder : public Registration
{
public:
    ~Folder() {
        for( Registration *f : _content ) delete f;
    }
    void add(Registration* r) { _content.push_back(r); }
    int getSize() const override {
        int sum = 0;
        for(Registration* r : _content){
            sum += r->getSize();
        }
        return sum;
    }
protected:
    std::vector<Registration*> _content;
};

class FileSystem
{
public:
    Folder root;
};
