//
// Created by HuRF on 2022/9/22.
//

#ifndef WEBSITE_H
#define WEBSITE_H

#include <string>
#include <map>

using namespace std;

// 用户
class User {
private:
    string name;
public:
    explicit User(string name);
    string GetName();
};

// 网站抽象类
class WebSite {
public:
    virtual void Use(User * user) = 0;
};

// 具体网站类
class ConcreteWebSite : public WebSite {
private:
    string name;
public:
    explicit ConcreteWebSite(string name);
    void Use(User *user) override;

};

// 网站工厂
class WebSiteFactory {
private:
    map<string, WebSite*> flyweights{};
public:
    // 获得网站分类
    WebSite * GetWebSiteCategory(const string &key);
    // 获得网站分类总数
    int GetWebSiteCount();
};

#endif //WEBSITE_H
