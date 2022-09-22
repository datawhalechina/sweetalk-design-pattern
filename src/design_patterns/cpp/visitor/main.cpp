//
// Created by HuRF on 2022/9/22.
//

#include "ManWomanVisitor.h"

int main() {
    ObjectStructure * o = new ObjectStructure();
    // 在对象结构中加入要对比的男人和女人
    o->Attach(new Man());
    o->Attach(new Woman());

    //成功时的反应
    Success * v1 = new Success();
    o->Display(v1);

    // 失败时的反应
    Failing * v2 = new Failing();
    o->Display(v2);

    // 恋爱时的反应
    Amativeness * v3 = new Amativeness();
    o->Display(v3);

    Marriage * v4 = new Marriage();
    o->Display(v4);

    return 0;
}