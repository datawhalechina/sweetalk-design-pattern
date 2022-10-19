#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

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

Pen::Pen(Color color)
{
    m_color = color;
}

void Pen::getColor()
{
    switch(m_color)
    {
    case Color::yellow:
        cout << "使用黄色画笔";
        break;
    case Color::white:
        cout << "使用白色画笔";
        break;
    case Color::blank:
        cout << "使用黑色画笔";
        break;
    }
}

void print(string action, int a, int b, int c, int d)
{
    cout << action << a << " " << b << " " << c << " " << d << endl;
}


void Graphics::drawEllipse(Pen * p, int a, int b, int c, int d)
{
    p->getColor();
    print("画圆：", a, b, c, d);
}

void Graphics::drawRectangle(Pen * p, int a, int b, int c, int d)
{
    p->getColor();
    print("画方：", a, b, c, d);
}

void Graphics::drawLine(Pen * p, int a, int b, int c, int d)
{
    p->getColor();
    print("画线：", a, b, c, d);
}

ThinBuilder::ThinBuilder(Graphics * g, Pen * p)
{
    m_g = g;
    m_pen = p;
};

void ThinBuilder::buildHead()
{
    m_g->drawEllipse(m_pen, 50, 20, 30, 30);
    m_per->add("头部");
}

void ThinBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 50, 20, 30, 30);
    m_per->add("身体");
}

void ThinBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("左手");
}

void ThinBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("右手");
}

void ThinBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("左腿");
}

void ThinBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("右腿");
}

Person * ThinBuilder::getPerson()
{
    return m_per;
}

FatBuilder::FatBuilder(Graphics * g, Pen * p)
{
    m_g = g;
    m_pen = p;
};

void FatBuilder::buildHead()
{
    m_g->drawEllipse(m_pen, 50, 20, 30, 30);
    m_per->add("头部");
}

void FatBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 60, 50, 10, 50);
    m_per->add("身体");
}

void FatBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 60, 50, 40, 100);
    m_per->add("左手");
}

void FatBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 70, 50, 40, 100);
    m_per->add("右手");
}

void FatBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 60, 100, 45, 150);
    m_per->add("左腿");
}

void FatBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 70, 100, 85, 150);
    m_per->add("右腿");
}

Person * FatBuilder::getPerson()
{
    return m_per;
}

Director::Director(Builder * b)
{
    m_b = b;
}

void Director::createPerson()
{
    m_b->buildHead();
    m_b->buildBody();
    m_b->buildArmLeft();
    m_b->buildArmRight();
    m_b->buildLegLeft();
    m_b->buildLegRight();
}


int main()
{   
    Pen * p = new Pen(Color::yellow);
    Graphics * g = new Graphics();

    cout << "\n\n开始创建瘦子" << endl;
    ThinBuilder * tb = new ThinBuilder(g, p);
    Director * dtb = new Director(tb);
    dtb->createPerson();
    Person * tp = tb->getPerson();
    tp->show();

    cout << "\n\n开始创建胖子" << endl;
    FatBuilder * fb = new FatBuilder(g, p);
    Director * dfb = new Director(fb);
    dfb->createPerson();
    Person * fp = fb->getPerson();
    fp->show();

    return 0;
}