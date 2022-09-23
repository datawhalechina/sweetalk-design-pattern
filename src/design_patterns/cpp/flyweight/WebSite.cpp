//
// Created by HuRF on 2022/9/22.
//

#include "WebSite.h"

#include <iostream>

using namespace std;

User::User(string name) : name(std::move(name)) {}

string User::GetName() {
    return this->name;
}

ConcreteWebSite::ConcreteWebSite(string name):name(std::move(name)) {}

void ConcreteWebSite::Use(User *user) {
    std::cout << "网站分类：" << name << " 用户：" << user->GetName() << std::endl;
}


WebSite *WebSiteFactory::GetWebSiteCategory(const string &key) {
    if (!flyweights.count(key)) {
        flyweights[key] = new ConcreteWebSite(key);
    }
    return flyweights[key];
}

int WebSiteFactory::GetWebSiteCount() {
    return (int) flyweights.size();
}
