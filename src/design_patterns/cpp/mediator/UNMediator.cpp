//
// Created by HuRF on 2022/9/22.
//

#include "UNMediator.h"
#include <iostream>

using namespace std;

Country::Country(UnitedNations *mediator):mediator(mediator) {
}


USA::USA(UnitedNations *mediator) : Country(mediator) {
}

void USA::Declare(const string &message) {
    mediator->Declare(message, this);
}

void USA::GetMessage(const string &message) {
    std::cout << "美国获得对方消息：" << message << std::endl;
}


Iraq::Iraq(UnitedNations *mediator) : Country(mediator) {
}

void Iraq::Declare(const string &message) {
    mediator->Declare(message, this);
}

void Iraq::GetMessage(const string &message) {
    std::cout << "伊拉克获得对方消息：" << message << std::endl;
}


void UnitedNationsSecurityCouncil::setColleague1(USA *value) {
    colleague1 = value;
}

void UnitedNationsSecurityCouncil::setColleague2(Iraq *value) {
    colleague2 = value;
}

void UnitedNationsSecurityCouncil::Declare(const string &message, const Country *colleague) {
    if (colleague == colleague1) {
        colleague2->GetMessage(message);
    } else {
        colleague1->GetMessage(message);
    }
}



