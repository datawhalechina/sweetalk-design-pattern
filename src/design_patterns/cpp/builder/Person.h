#include <list>

using namespace std;



class Person
{
public:
    enum Color { yellow, white, blank };
    explicit Person(enum Person::Color);
    void add(string part);
    void show();
private:
    Color m_color;
    list<string> m_parts;
};

class Graphics
{
public:
    void drawEllipse(Person * p, int a, int b, int c, int d);
    void drawRectangle(Person * p, int a, int b, int c, int d);
    void drawLine(Person * p, int a, int b, int c, int d);
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
    void buildHead() override;
    void buildBody() override;
    void buildArmLeft() override;
    void buildArmRight() override;
    void buildLegLeft() override;
    void buildLegRight() override;
    Person * getPerson() override;

private:
    Graphics * m_g = new Graphics();
    Person * m_p = new Person(Person::Color::yellow);
};

class FatBuilder: public Builder
{
public:
    void buildHead() override;
    void buildBody() override;
    void buildArmLeft() override;
    void buildArmRight() override;
    void buildLegLeft() override;
    void buildLegRight() override;
    Person * getPerson() override;

private:
    Graphics * m_g = new Graphics();
    Person * m_p = new Person(Person::Color::yellow);
};


class Director
{
public:
    void createPerson(Builder * builder);
};