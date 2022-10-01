# -*- coding:utf-8 -*-
'''
@File    :   Command.py
@Time    :   2022/09/29 20:47:54
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
import datetime
# 烤肉串者
class Barbecuer(object):
    def bake_mutton(self):
        print("烤羊肉串！")
    def bake_chicken_wing(self):
        print("烤鸡翅！")

# 抽象命令
class Command(object):
    receiver = None
    def __init__(self,receiver:Barbecuer):
        self.receiver = receiver
    def excute_command(self):
        pass

# 具体命令
class BakeMuttonCommand(Command):
    def __init__(self,receiver:Barbecuer):
        super().__init__(receiver)
    def excute_command(self):
        self.receiver.bake_mutton()

class BakeChickenWingCommand(Command):
    def __init__(self,receiver:Barbecuer):
        super().__init__(receiver)
    def excute_command(self):
        self.receiver.bake_chicken_wing()

# 服务员
class Waiter(object):
    def __init__(self):
        self.__orders = []
    def set_order(self,command:Command):
        if type(command) == BakeChickenWingCommand:
            print("服务员：鸡翅没有了，请点别的烧烤。")
        else:
            self.__orders.append(command)
            print("增加订单："+command.__class__.__name__)
            print("时间："+str(datetime.datetime.now()))
    def cancel_order(self,command):
        self.__orders.remove(command)
        print("取消订单："+command.__class__.__name__)
        print("时间："+str(datetime.datetime.now()))
    def notify(self):
        for each in self.__orders:
            each.excute_command()


if __name__ == '__main__':
    # 开店前的准备
    boy = Barbecuer()
    bakeMuttonCommand1 = BakeMuttonCommand(boy)
    bakeMuttonCommand2 = BakeMuttonCommand(boy)
    bakeChickenWingCommand1 = BakeChickenWingCommand(boy)

    girl = Waiter()

    # 开门营业 顾客点菜
    girl.set_order(bakeMuttonCommand1)
    girl.set_order(bakeMuttonCommand2)
    girl.set_order(bakeChickenWingCommand1)

    girl.notify()
