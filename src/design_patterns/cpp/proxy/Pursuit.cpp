#include <iostream>

#include "Pursuit.h"

using namespace std;


class SchoolGirl
{
public:
    SchoolGirl(){};
    
    void setName(string name)
    {
        m_name = name;
    }

    string getName()
    {
        return m_name;
    }

private:
    string m_name;
};


class Pursuit: public IGiveGift
{
public:
    Pursuit(SchoolGirl * mm)
    {
        m_mm = mm;
    }

    void giveDolls() const override
    {
        cout << m_mm->getName() << " 送你洋娃娃" << endl;
    }

    void giveFlowers() const override
    {
        cout << m_mm->getName() << " 送你鲜花" << endl;
    }

    void giveChocolate() const override
    {
        cout << m_mm->getName() << " 送你巧克力" << endl;
    }

private:
    SchoolGirl * m_mm;

};

class Proxy: public IGiveGift
{
public:
    Proxy(SchoolGirl * mm)
    {
        m_gg = new Pursuit(mm);
    }

    void giveDolls() const override
    {
        m_gg->giveDolls();
    }

    void giveFlowers() const override
    {
        m_gg->giveFlowers();
    }

    void giveChocolate() const override
    {
        m_gg->giveChocolate();
    }

private:
    Pursuit * m_gg;
};

int main()
{
    try
    {
        SchoolGirl *jiaojiao = new SchoolGirl();
        jiaojiao->setName("李娇娇");

        Proxy * daili = new Proxy(jiaojiao);
        daili->giveDolls();
        daili->giveFlowers();
        daili->giveChocolate();

    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}