#include <iostream>

#include "Boss.h"

using namespace std;


void Boss::attach(Observer * obj)
{
    m_objs.push_back(obj);
}


void Boss::detach(Observer * obj)
{
    m_objs.remove(obj);
}

void Boss::notify()
{
    for (auto const& o: m_objs)
    {
        o->update();
    }
}

void StockObserver::update()
{
    cout << m_sub->getState() << m_name << " 关闭股票行情，继续工作！" << endl;
}


void NBAObserver::update()
{
    cout << m_sub->getState() << m_name << " 关闭NBA直播，继续工作！" << endl;
}


int main()
{
    Boss * huhansan = new Boss();
    StockObserver * tongshi1 = new StockObserver("魏关姹", huhansan);
    NBAObserver * tongshi2 = new NBAObserver("易管查", huhansan);

    huhansan->attach(tongshi1);
    huhansan->attach(tongshi2);

    huhansan->detach(tongshi1);

    huhansan->setState("我胡汉三回来了！");
    huhansan->notify();

    return 0;
}



