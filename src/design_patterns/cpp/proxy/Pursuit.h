#ifndef PURSUIT_H
#define PURSUIT_H

#include <iostream>

using namespace std;

class IGiveGift
{
public:
    IGiveGift(){};
    virtual void giveDolls() const = 0;
    virtual void giveFlowers() const = 0;
    virtual void giveChocolate() const = 0;
};

#endif