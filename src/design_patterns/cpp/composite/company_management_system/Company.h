//
// Created by HuRF on 2022/9/21.
//

#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <list>
#include <utility>

using namespace std;

class Company {
protected:
    string name;
public:
    explicit Company(string n);

    // 增加
    virtual void Add(Company *c) = 0;

    // 移除
    virtual void Remove(Company *c) = 0;

    // 显示
    virtual void Display(int depth) = 0;

    // 履行职责
    virtual void LineOfDuty() = 0;
};

// 具体公司类
class ConcreteCompany : public Company {
private:
    list<Company *> children;
public:
    explicit ConcreteCompany(string n) : Company(std::move(n)) {};

    void Add(Company *c) override;

    void Remove(Company *c) override;

    void Display(int depth) override;

    void LineOfDuty() override;
};

// 人力资源部类
class HRDepartment : public Company {
public:
    explicit HRDepartment(string n) : Company(std::move(n)) {};

    void Add(Company *c) override;

    void Remove(Company *c) override;

    void Display(int depth) override;

    void LineOfDuty() override;
};

// 财务部类
class FinanceDepartment : public Company {
public:
    explicit FinanceDepartment(string n) : Company(std::move(n)) {};

    void Add(Company *c) override;

    void Remove(Company *c) override;

    void Display(int depth) override;

    void LineOfDuty() override;
};

#endif //COMPANY_H
