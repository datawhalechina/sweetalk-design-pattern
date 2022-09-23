//
// Created by HuRF on 2022/9/20.
//

#include "GameRoleMemento.h"
#include <iostream>

using namespace std;

void GameRoleMemento::SetVitality(const int &v) {
    this->vit = v;
}

int GameRoleMemento::GetVitality() const {
    return this->vit;
}

void GameRoleMemento::SetAtk(const int &v) {
    this->atk = v;
}

int GameRoleMemento::GetAtk() const {
    return this->atk;
}

void GameRoleMemento::SetDefense(const int &v) {
    this->def = v;
}

int GameRoleMemento::GetDenfense() const {
    return this->def;
}

void GameRoleMemento::StateDisplay() const {
    std::cout << "角色当前状态：\n";
    std::cout << "体力：" << this->vit << std::endl;
    std::cout << "攻击力：" << this->atk << std::endl;
    std::cout << "防御力：" << this->def << std::endl;
    std::cout << std::endl;
}

void GameRoleMemento::GetInitState() {
    this->vit = 100;
    this->atk = 100;
    this->def = 100;
}

void GameRoleMemento::Fight() {
    this->vit = 0;
    this->atk = 0;
    this->def = 0;
}

RoleStateMemento * GameRoleMemento::SaveState() {
    return new RoleStateMemento{vit, atk, def};
}

void GameRoleMemento::RecoveryState(RoleStateMemento *memento) {
    this->vit = memento->GetVitality();
    this->atk = memento->GetAtk();
    this->def = memento->GetDenfense();
}


RoleStateMemento::RoleStateMemento(int vit, int atk, int def) {
    this->vit = vit;
    this->atk = atk;
    this->def = def;
}

void RoleStateMemento::SetVitality(const int &v) {
    this->vit = v;
}

int RoleStateMemento::GetVitality() const {
    return this->vit;
}

void RoleStateMemento::SetAtk(const int &v) {
    this->atk = v;
}

int RoleStateMemento::GetAtk() const {
    return this->atk;
}

void RoleStateMemento::SetDefense(const int &v) {
    this->def = v;
}

int RoleStateMemento::GetDenfense() const {
    return this->def;
}


void RoleStateCaretaker::SetRoleStateMemento(RoleStateMemento *roleStateMemento) {
    this->memento = roleStateMemento;
}

RoleStateMemento * RoleStateCaretaker::GetRoleStateMemento(){
    return this->memento;
}

RoleStateCaretaker::RoleStateCaretaker() = default;



