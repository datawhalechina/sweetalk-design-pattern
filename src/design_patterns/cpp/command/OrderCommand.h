//
// Created by HuRF on 2022/9/21.
//

#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

#include <list>
#include <string>

using namespace std;

// 烤肉串者
class Barbecuer {
public:
    // 烤羊肉
    void BakeMutton();
    // 烤鸡翅
    void BakeChickenWing();
};

// 抽象命令
class Command {
protected:
    Barbecuer * receiver;
public:
    string name;
    explicit Command(Barbecuer *receiver);
    // 执行命令
    virtual void ExecuteCommand() = 0;
};

// 烤羊肉串命令
class BakeMuttonCommand : public Command {
public:
    explicit BakeMuttonCommand(Barbecuer *receiver);
    void ExecuteCommand() override;
};

// 烤鸡翅命令
class BakeChickenWingCommand : public Command {
public:
    explicit BakeChickenWingCommand(Barbecuer *receiver);
    void ExecuteCommand() override;
};

// 服务员
class Waiter {
private:
    list<Command *> orders;
public:
    void SetOrder(Command *command);
    void CancelOrder(Command *command);
    void Notify();
};

#endif //ORDERCOMMAND_H
