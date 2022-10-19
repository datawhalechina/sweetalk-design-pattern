#include <string>
#include <list>

using namespace std;

enum Color { yellow, white, blank };

class Person
{
public:
    void show();
    void add(string part);

private:
    list<string> m_parts;
};

class Pen
{
public:
    Pen(enum Color color);
    void getColor();
private:
    Color m_color;
};

class Graphics
{
public:
    Graphics(){};
    void drawEllipse(Pen * p, int a, int b, int c, int d);
    void drawRectangle(Pen * p, int a, int b, int c, int d);
    void drawLine(Pen * p, int a, int b, int c, int d);
};

class Builder
{
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArmLeft() = 0;
    virtual void buildArmRight() = 0;
    virtual void buildLegLeft() = 0;
    virtual void buildLegRight() = 0;
    virtual Person * getPerson() = 0;
};

class ThinBuilder: public Builder
{
public:
    ThinBuilder(Graphics * g, Pen * p);
    void buildHead() override;
    void buildBody() override;
    void buildArmLeft() override;
    void buildArmRight() override;
    void buildLegLeft() override;
    void buildLegRight() override;
    Person * getPerson() override;

private:
    Graphics * m_g;
    Pen * m_pen;
    Person * m_per = new Person();
};

class FatBuilder: public Builder
{
public:
    FatBuilder(Graphics * g, Pen * p);
    void buildHead() override;
    void buildBody() override;
    void buildArmLeft() override;
    void buildArmRight() override;
    void buildLegLeft() override;
    void buildLegRight() override;
    Person * getPerson() override;

private:
    Graphics * m_g;
    Pen * m_pen;
    Person * m_per = new Person();
};


class Director
{
public:
    Director(Builder * builder);
    void createPerson();

private:
    Builder * m_b;
};