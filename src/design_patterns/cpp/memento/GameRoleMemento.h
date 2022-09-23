//
// Created by HuRF on 2022/9/20.
//

#ifndef GAMEROLE_MEMENTO_H
#define GAMEROLE_MEMENTO_H

class RoleStateMemento;

// 游戏角色类
class GameRoleMemento {
private:
    // 生命力
    int vit;
    // 攻击力
    int atk;
    // 防御力
    int def;
public:
    void SetVitality(const int &v);
    int GetVitality() const;
    void SetAtk(const int &v);
    int GetAtk() const;
    void SetDefense(const int &v);
    int GetDenfense() const;

    // 状态显示
    void StateDisplay() const;
    // 获得初始状态
    void GetInitState();
    // 战斗
    void Fight();

    // 保存角色状态
    RoleStateMemento * SaveState();
    // 恢复角色状态
    void RecoveryState(RoleStateMemento *memento);
};

// 角色状态存储箱类
class RoleStateMemento {
private:
    int vit;
    int atk;
    int def;
public:
    RoleStateMemento(int vit, int atk, int def);
    void SetVitality(const int &v);
    int GetVitality() const;
    void SetAtk(const int &v);
    int GetAtk() const;
    void SetDefense(const int &v);
    int GetDenfense() const;
};

// 角色状态管理者类
class RoleStateCaretaker{
private:
    RoleStateMemento * memento;
public:
    void SetRoleStateMemento(RoleStateMemento * roleStateMemento);
    RoleStateMemento * GetRoleStateMemento();

    RoleStateCaretaker();
    ~RoleStateCaretaker() = default;
};

#endif //GAMEROLE_MEMENTO_H
