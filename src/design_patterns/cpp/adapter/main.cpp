//
// Created by HRF on 2022/9/20.
//
#include "PlayAdapter.h"

using namespace std;

int main() {
    Player * b = new Forwords("巴蒂尔");
    b->Attack();
    Player *m = new Guards("麦克格雷迪");
    m->Attack();

    Player * ym = new Translator("姚明");
    ym->Attack();
    ym->Defense();

    return 0;
}