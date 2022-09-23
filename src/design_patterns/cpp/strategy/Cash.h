#ifndef CASH_H
#define CASH_H

#include <iostream>

class CashInterface
{
public:
    virtual double acceptCash(double money) const = 0;
};

#endif