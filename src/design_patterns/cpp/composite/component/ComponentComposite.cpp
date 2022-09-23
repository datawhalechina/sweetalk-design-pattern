//
// Created by HuRF on 2022/9/20.
//

#include "ComponentComposite.h"
#include <iostream>

using namespace std;

Component::Component(string n) : name(std::move(n)) {}

bool Component::operator==(Component *c) {
    return this->name == c->name;
}


void Leaf::Add(Component *c) {
    std::cout << "Cannot add to a leaf" << std::endl;
}

void Leaf::Remove(Component *c) {
    std::cout << "Cannot remove from a leaf" << std::endl;
}

void Leaf::Display(int depth) {
    // 叶节点的具体方法，显示其名称和级别
    std::cout << string(depth, '-') << name << std::endl;
}

void Composite::Add(Component *c) {
    this->children.push_back(c);
}

void Composite::Remove(Component *c) {
    this->children.remove(c);
}

void Composite::Display(int depth) {
    // 显示其枝节点名称
    std::cout << string(depth, '-') << name << std::endl;

    // 对其下级进行遍历
    for (auto component : children) {
        component->Display(depth + 2);
    }
}

