#include <list>

using namespace std;

class Observer
{
public:
    virtual void update() = 0;
};

class Subject
{
public:
    virtual void attach(Observer * obj) = 0;
    virtual void detach(Observer * obj) = 0;
    virtual void notify() = 0;
};

class Boss: public Subject
{
public:
    string getState()
    {
        return m_action;
    }
    void setState(string action)
    {
        m_action = action;
    }
    void attach(Observer * obj) override;
    void detach(Observer * obj) override;
    void notify() override;

private:
    string m_action;
    list<Observer*> m_objs;
};

class StockObserver: public Observer
{
public:
    StockObserver(string name, Boss * sub)
    {
        m_name = name;
        m_sub = sub;
    }
    void update() override;

private:
    string m_name;
    Boss * m_sub;
};

class NBAObserver: public Observer
{
public:
    NBAObserver(string name, Boss * sub)
    {
        m_name = name;
        m_sub = sub;
    }
    void update() override;

private:
    string m_name;
    Boss * m_sub;
};