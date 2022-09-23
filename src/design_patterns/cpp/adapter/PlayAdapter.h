//
// Created by HuRF on 2022/9/20.
//

#ifndef PLAYADAPTER_H
#define PLAYADAPTER_H

#include <string>

using namespace std;

// 球员
class Player {
protected:
    string name;
public:
    Player();

    explicit Player(string n);

    // 进攻
    virtual void Attack() = 0 ;

    // 防守
    virtual void Defense() = 0;
};

// 前锋
class Forwords : public Player {
public:
    explicit Forwords(const string &n);

    void Attack() override;

    void Defense() override;
};

// 中锋
class Center : public Player {
public:
    explicit Center(const string &n);

    void Attack() override;

    void Defense() override;
};

// 后卫
class Guards : public Player {
public:
    explicit Guards(const string &n);

    void Attack() override;

    void Defense() override;
};

// 外籍中锋
class ForeignCenter {
private:
    string name;
public:
    void SetName(const string &v);

    string GetName();

    // 表明“外籍中锋”只懂得中文“进攻”
    void CN_Attack();

    // 表明“外籍中锋”只懂得中文“防守”
    void CN_Defense();
};

// 翻译者
class Translator : public Player {
private:
    // 实例化一个内部“外籍中锋”对象，表明翻译者与外籍球员有关联
    ForeignCenter wjzf;
public:
    explicit Translator(const string &n);

    void Attack() override;

    void Defense() override;
};

#endif // PLAYADAPTER_H
