#include <iostream>

#include "Work.h"

using namespace std;


void ForenoonState::writeProgram(Work * w)
{
    if (w->getHour() < 12)
    {
        cout << "当前时间：" << w->getHour() << "点 上午工作，精神百倍" << endl;
    }
    else
    {
        w->setState(new NoonState());
        w->writeProgram();
    }
}

void NoonState::writeProgram(Work * w)
{
    if (w->getHour() < 13)
    {
        cout << "当前时间：" << w->getHour() << "点 饿了，午饭；犯困，午休" << endl;
    }
    else
    {
        w->setState(new AfternoonState());
        w->writeProgram();
    }
}

void AfternoonState::writeProgram(Work * w)
{
    if (w->getHour() < 17)
    {
        cout << "当前时间：" << w->getHour() << "点 下午状态还不错，继续努力" << endl;
    }
    else
    {
        w->setState(new EveningState());
        w->writeProgram();
    }
}

void EveningState::writeProgram(Work * w)
{
    
    if (w->getTaskFinished())
    {
        w->setState(new RestState());
        w->writeProgram();
    } 
    else
    {
        if (w->getHour() < 21)
    {
        cout << "当前时间：" << w->getHour() << "点 加班哦，疲累之极" << endl;
    }
    else
    {
        w->setState(new SleepingState());
        w->writeProgram();
    }
    }
}

void SleepingState::writeProgram(Work * w)
{
    cout << "当前时间：" << w->getHour() << "点 不行了，睡着了。" << endl;
}

void RestState::writeProgram(Work * w)
{
    cout << "当前时间：" << w->getHour() << "点 下班回家了" << endl;
}

int main()
{
    Work * ep = new Work();
    ep->setHour(9);
    ep->writeProgram();
    ep->setHour(10);
    ep->writeProgram();
    ep->setHour(12);
    ep->writeProgram();
    ep->setHour(13);
    ep->writeProgram();
    ep->setHour(14);
    ep->writeProgram();
    ep->setHour(17);
    ep->writeProgram();

    ep->setTaskFinished(false);
    ep->setHour(19);
    ep->writeProgram();
    ep->setHour(22);
    ep->writeProgram();
    
    
    return 0;
}