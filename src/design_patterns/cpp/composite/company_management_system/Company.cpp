//
// Created by HuRF on 2022/9/21.
//

#include "Company.h"
#include <iostream>

using namespace std;

Company::Company(string name) : name(std::move(name)) {}


void ConcreteCompany::Add(Company *c) {
    this->children.push_back(c);
}

void ConcreteCompany::Remove(Company *c) {
    this->children.remove(c);
}

void ConcreteCompany::Display(int depth) {
    std::cout << string(depth, '-') << name << std::endl;

    for (auto component : children) {
        component->Display(depth + 2);
    }
}

void ConcreteCompany::LineOfDuty() {
    for (auto component : children) {
        component->LineOfDuty();
    }
}


void HRDepartment::Add(Company *c) {}

void HRDepartment::Remove(Company *c) {}

void HRDepartment::Display(int depth) {
    std::cout << string(depth, '-') << name << std::endl;
}

void HRDepartment::LineOfDuty() {
    std::cout << name << " 员工招聘培训管理" << std::endl;
}

void FinanceDepartment::Add(Company *c) {}

void FinanceDepartment::Remove(Company *c) {}

void FinanceDepartment::Display(int depth) {
    std::cout << string(depth, '-') << name << std::endl;
}

void FinanceDepartment::LineOfDuty() {
    std::cout << name << " 公司财务收支管理" << std::endl;
}
