//
// Created by HuRF on 2022/9/22.
//

#ifndef UNMEDIATOR_H
#define UNMEDIATOR_H

#include <string>

using namespace std;

class Country;

// 联合国机构
class UnitedNations {
public:
    // 声明
    virtual void Declare(const string &message, const Country *colleague) = 0;
};

// 国家
class Country {
protected:
    UnitedNations *mediator;
public:
    explicit Country(UnitedNations * mediator);
};

// 美国
class USA : public Country {
public:
    explicit USA(UnitedNations * mediator);
    // 声明
    void Declare(const string &message);
    // 获得消息
    void GetMessage(const string &message);
};

// 伊拉克
class Iraq : public Country {
public:
    explicit Iraq(UnitedNations * mediator);
    // 声明
    void Declare(const string &message);
    // 获得消息
    void GetMessage(const string &message);
};

class UnitedNationsSecurityCouncil : public UnitedNations {
private:
    USA * colleague1;
    Iraq * colleague2;
public:
    void setColleague1(USA * value);
    void setColleague2(Iraq * value);
    void Declare(const string &message, const Country *colleague) override;
};

#endif //UNMEDIATOR_H
