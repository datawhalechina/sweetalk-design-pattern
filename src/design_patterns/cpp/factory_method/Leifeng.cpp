#include <iostream>

#include "Leifeng.h"

using namespace std;

void LeiFeng::sweep()
{
    cout << "扫地" << endl;
}

void LeiFeng::wash()
{
    cout << "洗衣" << endl;
}

void LeiFeng::buyRice()
{
    cout << "买米" << endl;
}

class Undergraduate: public LeiFeng{};

class Volunteer: public LeiFeng{};

class UndergraduateLeiFeng: public iLeiFeng
{
public:
    UndergraduateLeiFeng(){};
    LeiFeng * createLeiFeng() const override
    {
        return new Undergraduate();
    }
};

class VolunteerLeiFeng: public iLeiFeng
{
public:
    VolunteerLeiFeng(){};
    LeiFeng * createLeiFeng() const override
    {
        return new Volunteer();
    }
};


int main()
{
    try
    {
        iLeiFeng * factory = new VolunteerLeiFeng();
        LeiFeng * stu_or_vol = factory->createLeiFeng();
        stu_or_vol->buyRice();
        stu_or_vol->sweep();
        stu_or_vol->wash();
    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}