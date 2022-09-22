//
// Created by HuRF on 2022/9/21.
//

#include "OrderCommand.h"
#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

string get_current_time();

class BakeMap {
protected:
    map<string, string> bakeMap = {};
public:
    BakeMap() {
        bakeMap[typeid(BakeMuttonCommand).name()] = "烤羊肉串";
        bakeMap[typeid(BakeChickenWingCommand).name()] = "烤鸡翅";
    };

    string get_command_cn_name(const string& command_name) {
        for (const auto &bake : bakeMap) {
            if (command_name.find(bake.first) != -1) {
                return bake.second;
            }
        }
        return "未知烤串";
    }
};

void Barbecuer::BakeMutton() {
    std::cout << "烤羊肉串！" << std::endl;
}

void Barbecuer::BakeChickenWing() {
    std::cout << "烤鸡翅！" << std::endl;
}

Command::Command(Barbecuer &receiver) {
    this->receiver = &receiver;
}


BakeMuttonCommand::BakeMuttonCommand(Barbecuer &receiver) : Command(receiver) {
}

void BakeMuttonCommand::ExecuteCommand() {
    receiver->BakeMutton();
}

BakeChickenWingCommand::BakeChickenWingCommand(Barbecuer &receiver) : Command(receiver) {
}

void BakeChickenWingCommand::ExecuteCommand() {
    receiver->BakeChickenWing();
}


void Waiter::SetOrder(Command &command) {
    auto * bake = new BakeMap();
    if (static_cast<string>(typeid(command).name()).find("BakeChickenWingCommand") != -1) {
        std::cout << "服务员：鸡翅没有了，请点别的烧烤。" << std::endl;
    } else {
        orders.push_back(&command);
        std::cout << "增加订单：" << bake->get_command_cn_name((string) typeid(command).name());
        std::cout << " 时间：" << get_current_time() << std::endl;
    }
}

void Waiter::CancelOrder(Command &command) {
    orders.remove(&command);
    std::cout << "取消订单：" << typeid(command).name();
    std::cout << " 时间：" << get_current_time() << std::endl;
}

void Waiter::Notify() {
    for (Command *cmd : orders) {
        cmd->ExecuteCommand();
    }
}

string get_current_time() {
    time_t now = time(nullptr);
    tm * curr_time = localtime(&now);
    char time[80] = {0};
    strftime(time, 80, "%Y-%m-%d %H:%M:%S", curr_time);
    return time;
}