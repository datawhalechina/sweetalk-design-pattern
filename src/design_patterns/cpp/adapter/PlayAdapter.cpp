//
// Created by HuRF on 2022/9/20.
//

#include "PlayAdapter.h"
#include <iostream>

Player::Player(string n) : name(std::move(n)) {}

Player::Player() = default;

Forwords::Forwords(const string &n) : Player(n) {
}

void Forwords::Attack() {
    std::cout << "前锋 " << name << " 进攻" << std::endl;
}

void Forwords::Defense() {
    std::cout << "前锋 " << name << " 防守" << std::endl;
}

Center::Center(const string &n) : Player(n) {
}

void Center::Attack() {
    std::cout << "中锋 " << name << " 进攻" << std::endl;
}

void Center::Defense() {
    std::cout << "中锋 " << name << " 防守" << std::endl;
}

Guards::Guards(const string &n) : Player(n) {
}

void Guards::Attack() {
    std::cout << "后卫 " << name << " 进攻" << std::endl;
}

void Guards::Defense() {
    std::cout << "后卫 " << name << " 防守" << std::endl;
}

void ForeignCenter::SetName(const string &v) {
    this->name = v;
}

string ForeignCenter::GetName() {
    return this->name;
}

void ForeignCenter::CN_Attack() {
    std::cout << "外籍中锋 " << name << " 进攻" << std::endl;
}

void ForeignCenter::CN_Defense() {
    std::cout << "外籍中锋 " << name << " 防守" << std::endl;
}

Translator::Translator(const string &n) : Player(n) {
    wjzf.SetName(n);
}

// 翻译者将“Attack”翻译为“进攻”告诉外籍中锋
void Translator::Attack() {
    wjzf.CN_Attack();
}

// 翻译者将“Defense”翻译为“防守”告诉外籍中锋
void Translator::Defense() {
    wjzf.CN_Defense();
}
