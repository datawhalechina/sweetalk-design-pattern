//
// Created by HuRF on 2022/9/21.
//

#include "HandsetBridge.h"
#include <iostream>
#include <utility>

using namespace std;

void HandsetGame::Run() {
    std::cout << "运行手机游戏" << std::endl;
}

void HandsetAddressList::Run() {
    std::cout << "运行手机通讯录" << std::endl;
}

void HandsetBrand::SetHandsetSoft(HandsetSoft *s) {
    this->soft = s;
}

HandsetBrand::HandsetBrand(string name) : name(std::move(name)) {}

void HandsetBrandN::Run() {
    std::cout << name << " ";
    soft->Run();
}

HandsetBrandN::HandsetBrandN(const string &name) : HandsetBrand(name) {}

HandsetBrandM::HandsetBrandM(const string &name) : HandsetBrand(name) {}

void HandsetBrandM::Run() {
    std::cout << name << " ";
    soft->Run();
}
