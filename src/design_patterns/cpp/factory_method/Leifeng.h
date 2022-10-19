#ifndef LEIFENG_H
#define LEIFENG_H

#include <iostream>

using namespace std;

class LeiFeng
{
public:
    LeiFeng(){};
    void sweep();
    void wash();
    void buyRice();
};

class iLeiFeng
{
public:
    iLeiFeng(){};
    virtual LeiFeng * createLeiFeng() const = 0;
};

#endif