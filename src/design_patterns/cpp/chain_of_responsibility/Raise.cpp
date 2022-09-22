//
// Created by HuRF on 2022/9/22.
//

#include "Raise.h"
#include <iostream>
#include <utility>

string Request::getRequestType() {
    return requestType;
}

void Request::setRequestType(const string &value) {
    this->requestType = value;
}

string Request::getRequestContent() {
    return requestContent;
}

void Request::setRequestContent(const string &value) {
    this->requestContent = value;
}

int Request::getNumber() const {
    return this->number;
}

void Request::setNumber(const int &value) {
    this->number = value;
}

Manager::Manager(string name) : name(std::move(name)) {}

void Manager::SetSuperior(Manager *superior) {
    this->superior = superior;
}


CommonManager::CommonManager(const string &name) : Manager(name) {}

void CommonManager::RequestApplications(Request *request) {
    if (request->getRequestType() == "请假" && request->getNumber() <= 2) {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 被批准" << std::endl;
    } else {
        if (this->superior != nullptr) {
            this->superior->RequestApplications(request);
        }
    }
}

Majordomo::Majordomo(const string &name) : Manager(name) {}

void Majordomo::RequestApplications(Request *request) {
    if (request->getRequestType() == "请假" && request->getNumber() <= 5) {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 被批准" << std::endl;
    } else {
        if (this->superior != nullptr) {
            this->superior->RequestApplications(request);
        }
    }
}

GeneralManager::GeneralManager(const string &name) : Manager(name) {}

void GeneralManager::RequestApplications(Request *request) {
    if (request->getRequestType() == "请假") {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 被批准" << std::endl;
    } else if (request->getRequestType() == "加薪" && request->getNumber() <= 500) {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 被批准" << std::endl;
    } else if (request->getRequestType() == "加薪" && request->getNumber() > 500) {
        std::cout << name << "：" << request->getRequestContent();
        std::cout << " 数量" << request->getNumber() << " 再说吧" << std::endl;
    }
}
