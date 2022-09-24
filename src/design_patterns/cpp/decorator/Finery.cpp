#include <iostream>

#include "Finery.h"

using namespace std;

class Person: public Human
{
public:
    explicit Person(string name) 
    {
        m_name = name;
    }

    void show() override
    {
        cout << "装扮的" << m_name << endl;
    }
};

void Finery::decorate(Human * component)
{
    m_component = component;
}

void Finery::show()
{
    m_component->show();
}


class Tshirts: public Finery
{
public:
    void show() override
    {
        cout << "大T恤 ";
        Finery::show();
    }
};

class BigTrouser: public Finery
{
public:
    void show() override
    {
        cout << "垮裤 ";
        Finery::show();
    }
};

class Sneakers: public Finery
{
public:
    void show() override
    {
        cout << "破球鞋 ";
        Finery::show();
    }
};

class LeatherShoes: public Finery
{
public:
    void show() override
    {
        cout << "皮鞋 ";
        Finery::show();
    }
};

class Tie: public Finery
{
public:
    void show() override
    {
        cout << "领带 ";
        Finery::show();
    }
};

class Suit: public Finery
{
public:
    void show() override
    {
        cout << "西装 ";
        Finery::show();
    }
};


int main()
{
    try
    {
        Person *xc = new Person("小菜");
        
        cout << "第一种装扮：" << endl;
        Sneakers *pqx = new Sneakers();
        BigTrouser *kk = new BigTrouser();
        Tshirts *dtx = new Tshirts();
        pqx->decorate(xc);
        kk->decorate(pqx);
        dtx->decorate(kk);
        dtx->show();

        cout << "第二种装扮：" << endl;
        LeatherShoes *px = new LeatherShoes();
        Tie *ld = new Tie();
        Suit *xz = new Suit();
        px->decorate(xc);
        ld->decorate(px);
        xz->decorate(ld);
        xz->show();

        cout << "第三种装扮：" << endl;
        Sneakers *pqx2 = new Sneakers();
        LeatherShoes *px2 = new LeatherShoes();
        BigTrouser *kk2 = new BigTrouser();
        Tie *ld2 = new Tie();
        pqx2->decorate(xc);
        px2->decorate(pqx);
        kk2->decorate(px2);
        ld2->decorate(kk2);
        ld2->show();

    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}