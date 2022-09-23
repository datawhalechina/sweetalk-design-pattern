#include <iostream>
#include <math.h>

#include "Cash.h"

using namespace std;

enum Strategy
{
    eNormal,
    eRebate,
    eReturn,
};

Strategy hashit(string const &type)
{
    if (type == "正常收费")
        return eNormal;
    if (type == "满300返100")
        return eRebate;
    if (type == "打8折")
        return eReturn;
    return eNormal;
};

class CashNormal : public CashInterface
{
public:
    CashNormal() : CashInterface(){};
    virtual ~CashNormal(){};

    double acceptCash(double money) const override
    {
        return money;
    }
};

class CashRebate : public CashInterface
{
public:
    explicit CashRebate(string moneyRebate)
    {
        m_moneyRebate = stod(moneyRebate);
    }
    virtual ~CashRebate(){};

    double acceptCash(double money) const override
    {
        return money * m_moneyRebate;
    }

private:
    double m_moneyRebate = 1.0;
};

class CashReturn : public CashInterface
{
public:
    explicit CashReturn(string moneyCondition, string moneyReturn)
    {
        m_moneyContion = stod(moneyCondition);
        m_moneyReturn = stod(moneyReturn);
    }

    virtual ~CashReturn(){};

    double acceptCash(double money) const override
    {
        double result = money;
        if (money >= m_moneyContion)
            result = money - floor(money / m_moneyContion) * m_moneyReturn;
        return result;
    }

private:
    double m_moneyContion = 0.0;
    double m_moneyReturn = 0.0;
};

class CashContext
{
public:
    CashContext(){};
    explicit CashContext(CashInterface *cash)
    {
        m_cash = cash;
    };

    void setStrategy(CashInterface *cash)
    {
        m_cash = cash;
    }

    double getResult(double money)
    {
        return m_cash->acceptCash(money);
    }

private:
    CashInterface *m_cash;
};

void print(int price, int count, int totalPrice, string type)
{
    cout << "单价: " << price << " "
         << "数量：" << count << " "
         << type << " 合计：" << totalPrice << endl;
}

int main()
{
    try
    {
        string scount;
        string sprice;
        cout << "请输入单价： ";
        cin >> sprice;
        cout << "请输入数量： ";
        cin >> scount;

        double total = 0.0;
        double totalPrice = 0.0;
        double price = stod(sprice);
        double count = stod(scount);
        double initPrice = price * count;

        CashNormal normal = CashNormal();
        CashRebate rebate = CashRebate("0.8");
        CashReturn retun = CashReturn("300", "100");

        CashContext ctx = CashContext(&normal);
        totalPrice = ctx.getResult(initPrice);
        print(price, count, totalPrice, "正常收费");
        total += totalPrice;

        ctx.setStrategy(&retun);
        totalPrice = ctx.getResult(initPrice);
        total += totalPrice;
        print(price, count, totalPrice, "满300返100");

        ctx.setStrategy(&rebate);
        totalPrice = ctx.getResult(initPrice);
        total += totalPrice;
        print(price, count, totalPrice, "打8折");

        cout << "总计：" << total << endl;
    }
    catch (char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}