//
// Created by HuRF on 2022/9/20.
//
#include "PlayAdapter.h"

using namespace std;

int main() {
    Player * b = new Forwords("巴蒂尔");
    b->Attack();
    Player *m = new Guards("麦克格雷迪");
    m->Attack();

    // 翻译者告诉姚明，教练要求你既要“进攻”又要“防守”
    Player * ym = new Translator("姚明");
    ym->Attack();
    ym->Defense();

    return 0;
}