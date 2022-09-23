//
// Created by HuRF on 2022/9/21.
//

#ifndef HANDSETBRIDGE_H
#define HANDSETBRIDGE_H

#include <string>

using namespace std;

// 手机软件
class HandsetSoft {
public:
    virtual void Run() = 0;
};

// 手机游戏
class HandsetGame : public HandsetSoft {
public:
    void Run() override;
};

// 手机通讯录
class HandsetAddressList : public HandsetSoft {
public:
    void Run() override;
};

// 手机品牌
class HandsetBrand {
protected:
    string name;
    HandsetSoft * soft{};
public:
    explicit HandsetBrand(string name);
    // 品牌需要关注软件，可在机器中安装软件（设置手机软件），以备运行
    void SetHandsetSoft(HandsetSoft * s);
    virtual void Run() = 0;
};

// 手机品牌N
class HandsetBrandN : public HandsetBrand {
public:
    explicit HandsetBrandN(const string & name);
    void Run() override;
};

// 手机品牌M
class HandsetBrandM : public HandsetBrand {
public:
    explicit HandsetBrandM(const string & name);
    void Run() override;
};

#endif //HANDSETBRIDGE_H
