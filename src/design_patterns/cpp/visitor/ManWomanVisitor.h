//
// Created by HuRF on 2022/9/22.
//

#ifndef MANWOMANVISITOR_H
#define MANWOMANVISITOR_H

#include <string>
#include <list>

using namespace std;

class Action;

class Person {
public:
    virtual void Accept(Action * visitor) = 0;
};

class Man : public Person {
public:
    string name = "男人";
    void Accept(Action *visitor) override;
};

class Woman : public Person {
public:
    string name = "女人";
    void Accept(Action *visitor) override;
};

class Action {
public:
    // 得到男人结论或反应
    virtual void GetManConclusion(Man * concreteElementA) = 0;
    // 得到女人结论或反应
    virtual void GetWomanConclusion(Woman * concreteElementB) = 0;
};

// 成功
class Success : public Action {
public:
    string name = "成功";
    void GetManConclusion(Man *concreteElementA) override;
    void GetWomanConclusion(Woman *concreteElementB) override;
};

// 失败
class Failing : public Action {
public:
    string name = "失败";
    void GetManConclusion(Man *concreteElementA) override;
    void GetWomanConclusion(Woman *concreteElementB) override;
};

// 恋爱
class Amativeness : public Action {
public:
    string name = "恋爱";
    void GetManConclusion(Man *concreteElementA) override;
    void GetWomanConclusion(Woman *concreteElementB) override;
};

// 结婚
class Marriage : public Action {
public:
    string name = "结婚";
    void GetManConclusion(Man *concreteElementA) override;
    void GetWomanConclusion(Woman *concreteElementB) override;
};

class ObjectStructure {
private:
    list<Person *> elements;
public:
    // 增加
    void Attach(Person * element);
    // 移除
    void Detach(Person * element);
    // 查看显示
    void Display(Action * visitor);
};

#endif //MANWOMANVISITOR_H
