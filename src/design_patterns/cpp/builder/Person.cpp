#include <iostream>

#include "Person.h"

using namespace std;


Person::Person(enum Person::Color color)
{
    m_color = color;
}

void Person::add(string part)
{
    m_parts.push_back(part);
}

void Person::show()
{
    cout << "\n人物 展示 --- " << endl;
    for (auto v: m_parts)
    {
        cout << v << endl;
    }
}

void print(string action, int a, int b, int c, int d)
{
    cout << action << ": " << a << " " << b << " " << c << " " << d << endl;
}


void Graphics::drawEllipse(Person * p, int a, int b, int c, int d)
{
    print("draw ellipse", a, b, c, d);
}

void Graphics::drawRectangle(Person * p, int a, int b, int c, int d)
{
    print("draw rectangle", a, b, c, d);
}

void Graphics::drawLine(Person * p, int a, int b, int c, int d)
{
    print("draw line", a, b, c, d);
}


void ThinBuilder::buildHead()
{
    m_g->drawEllipse(m_p, 50, 20, 30, 30);
    m_p->add("头部");
}

void ThinBuilder::buildBody()
{
    m_g->drawRectangle(m_p, 50, 20, 30, 30);
    m_p->add("身体");
}

void ThinBuilder::buildArmLeft()
{
    m_g->drawLine(m_p, 50, 20, 30, 30);
    m_p->add("左手");
}

void ThinBuilder::buildArmRight()
{
    m_g->drawLine(m_p, 50, 20, 30, 30);
    m_p->add("右手");
}

void ThinBuilder::buildLegLeft()
{
    m_g->drawLine(m_p, 50, 20, 30, 30);
    m_p->add("左腿");
}

void ThinBuilder::buildLegRight()
{
    m_g->drawLine(m_p, 50, 20, 30, 30);
    m_p->add("右腿");
}

Person * ThinBuilder::getPerson()
{
    return m_p;
}

void FatBuilder::buildHead()
{
    m_g->drawEllipse(m_p, 50, 20, 30, 30);
    m_p->add("头部");
}

void FatBuilder::buildBody()
{
    m_g->drawRectangle(m_p, 60, 50, 10, 50);
    m_p->add("身体");
}

void FatBuilder::buildArmLeft()
{
    m_g->drawLine(m_p, 60, 50, 40, 100);
    m_p->add("左手");
}

void FatBuilder::buildArmRight()
{
    m_g->drawLine(m_p, 70, 50, 40, 100);
    m_p->add("右手");
}

void FatBuilder::buildLegLeft()
{
    m_g->drawLine(m_p, 60, 100, 45, 150);
    m_p->add("左腿");
}

void FatBuilder::buildLegRight()
{
    m_g->drawLine(m_p, 70, 100, 85, 150);
    m_p->add("右腿");
}

Person * FatBuilder::getPerson()
{
    return m_p;
}


void Director::createPerson(Builder * builder)
{
    builder->buildHead();
    builder->buildBody();
    builder->buildArmLeft();
    builder->buildArmRight();
    builder->buildLegLeft();
    builder->buildLegRight();
}


int main()
{
    Director * director = new Director();
    
    Builder * bc = new ThinBuilder();
    Builder * bf = new FatBuilder();

    cout << "开始创建瘦子" << endl;
    director->createPerson(bc);
    Person * p1 = bc->getPerson();
    p1->show();

    cout << "\n\n开始创建胖子" << endl;
    director->createPerson(bf);
    Person * p2 = bf->getPerson();
    p2->show();

    return 0;
}