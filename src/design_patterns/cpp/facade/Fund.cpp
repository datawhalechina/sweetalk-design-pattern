#include <iostream>

#include "Fund.h"


using namespace std;


void Stock1::buy()
{
    cout << "股票1买入" << endl;
}

void Stock1::sell()
{
    cout << "股票1卖出" << endl;
}

void Stock2::buy()
{
    cout << "股票2买入" << endl;
}

void Stock2::sell()
{
    cout << "股票2卖出" << endl;
}

void Stock3::buy()
{
    cout << "股票3买入" << endl;
}

void Stock3::sell()
{
    cout << "股票3卖出" << endl;
}

void NationalDebt1::buy()
{
    cout << "国债1买入" << endl;
}

void NationalDebt1::sell()
{
    cout << "国债1卖出" << endl;
}

void Realty1::buy()
{
    cout << "房地产1买入" << endl;
}

void Realty1::sell()
{
    cout << "房地产1卖出" << endl;
}


void Fund::buyFund()
{
    m_gu1->buy();
    m_gu2->buy();
    m_gu3->buy();
    m_nd1->buy();
    m_rt1->buy();
}

void Fund::sellFund()
{
    m_gu1->sell();
    m_gu2->sell();
    m_gu3->sell();
    m_nd1->sell();
    m_rt1->sell();
}


int main()
{
    Fund * jijin = new Fund();
    jijin->buyFund();
    jijin->sellFund();
}