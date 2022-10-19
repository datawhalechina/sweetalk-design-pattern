#ifndef CASH_H
#define CASH_H

#include <iostream>

class Cash
{
public:
    virtual double acceptCash(double money) const = 0;
};

#endif