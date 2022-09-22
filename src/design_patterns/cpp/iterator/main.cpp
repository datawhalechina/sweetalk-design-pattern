//
// Created by HuRF on 2022/9/21.
//

#include "Iterator.h"
#include <iostream>

using namespace std;

int main() {
    auto * a = new ConcreateAggregate();
    a->Insert("大鸟");
    a->Insert("小菜");
    a->Insert("行李");
    a->Insert("老外");
    a->Insert("公交内部员工");
    a->Insert("小偷");

    Iterator *i = new ConcreateIterator(a);
    string item = i->First();
    while(!i->IsDone()) {
        std::cout << i->CurrentItem() << " 请买车票！" << std::endl;
        i->Next();
    }
}
