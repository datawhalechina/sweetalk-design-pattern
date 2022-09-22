//
// Created by HuRF on 2022/9/22.
//

#ifndef RAISE_H
#define RAISE_H

#include <string>
using namespace std;

class Manager;

// 申请
class Request {
private:
    // 申请类别
    string requestType;
    // 申请内容
    string requestContent;
    // 数量
    int number;
public:
    string getRequestType();
    void setRequestType(const string &value);

    string getRequestContent();
    void setRequestContent(const string &value);

    int getNumber() const;
    void setNumber(const int &value);
};

// 管理者
class Manager {
protected:
    string name;
    // 管理者的上级
    Manager * superior{};
public:
    explicit Manager(string name);
    void SetSuperior(Manager * superior);
    virtual void RequestApplications(Request *request) = 0;
};

// 经理
class CommonManager : public Manager {
public:
    explicit CommonManager(const string &name);
    void RequestApplications(Request *request) override;
};

// 总监
class Majordomo : public Manager {
public:
    explicit Majordomo(const string &name);
    void RequestApplications(Request *request) override;
};

// 总经理
class GeneralManager : public Manager {
public:
    explicit GeneralManager(const string &name);
    void RequestApplications(Request *request) override;
};

#endif //RAISE_H
