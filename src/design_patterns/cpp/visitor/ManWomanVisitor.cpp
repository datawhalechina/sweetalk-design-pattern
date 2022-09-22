//
// Created by HuRF on 2022/9/22.
//

#include "ManWomanVisitor.h"

#include <iostream>

using namespace std;

void Success::GetManConclusion(Man *concreteElementA) {
    std::cout << concreteElementA->name << this->name << "时，背后多半有一个伟大的女人。" << std::endl;
}

void Success::GetWomanConclusion(Woman *concreteElementB) {
    std::cout << concreteElementB->name << this->name << "时，背后大多有一个不成功的男人。" << std::endl;
}

void Failing::GetManConclusion(Man *concreteElementA) {
    std::cout << concreteElementA->name << this->name << "时，闷头喝酒，谁也不用劝。" << std::endl;
}

void Failing::GetWomanConclusion(Woman *concreteElementB) {
    std::cout << concreteElementB->name << this->name << "时，眼泪汪汪，谁也劝不了。" << std::endl;
}

void Amativeness::GetManConclusion(Man *concreteElementA) {
    std::cout << concreteElementA->name << this->name << "时，凡事不懂也要装懂。" << std::endl;
}

void Amativeness::GetWomanConclusion(Woman *concreteElementB) {
    std::cout << concreteElementB->name << this->name << "时，遇事懂也装作不懂。" << std::endl;
}

void Marriage::GetManConclusion(Man *concreteElementA) {
    std::cout << concreteElementA->name << this->name << "时，感慨到：恋爱游戏终结时，‘有妻徒刑’遥无期。" << std::endl;
}

void Marriage::GetWomanConclusion(Woman *concreteElementB) {
    std::cout << concreteElementB->name << this->name << "时，欣慰曰：爱情长跑路漫漫，婚姻保险保平安。" << std::endl;
}

void Man::Accept(Action *visitor) {
    visitor->GetManConclusion(this);
}

void Woman::Accept(Action *visitor) {
    visitor->GetWomanConclusion(this);
}

void ObjectStructure::Attach(Person *element) {
    elements.push_back(element);
}

void ObjectStructure::Detach(Person *element) {
    elements.remove(element);
}

void ObjectStructure::Display(Action *visitor) {
    for (Person *e : elements) {
        e->Accept(visitor);
    }
}
