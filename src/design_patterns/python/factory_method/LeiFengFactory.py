# -*- coding:utf-8 -*-
'''
@File    :   LeiFengFactory.py
@Time    :   2022/09/23 19:23:57
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

from re import S


class LeiFeng(object):
    def sweep(self):
        print("扫地")
    def wash(self):
        print("洗衣")
    def buy_rice(self):
        print("买米")

class Undergraduate(LeiFeng):
    pass

class Volunteer(LeiFeng):
    pass

class SimpleFactory(object):
    def create_LeiFeng(self,typ:str) -> LeiFeng:
        self.result = None
        if typ == "学雷锋的大学生":
            self.result = Undergraduate()
        elif typ == "社区志愿者":
            self.result = Volunteer()
        return self.result

class IFactory(object):
    def create_LeiFeng(self):
        pass

class UndergraduateFactory(IFactory):
    def create_LeiFeng(self):
        return Undergraduate()

class VolunteerFactory(IFactory):
    def create_LeiFeng(self):
        return Volunteer()


if __name__ == '__main__':
    # 简单工厂模式
    studentA = SimpleFactory().create_LeiFeng("学雷锋的大学生")
    studentA.buy_rice()
    studentB = SimpleFactory().create_LeiFeng("学雷锋的大学生")
    studentB.sweep()
    studentC = SimpleFactory().create_LeiFeng("学雷锋的大学生")
    studentC.wash()

    # 工厂方法模式
    factory = UndergraduateFactory()
    student = factory.create_LeiFeng()

    student.buy_rice()
    student.sweep()
    student.wash()

    factory = VolunteerFactory()
    student = factory.create_LeiFeng()

    student.buy_rice()
    student.sweep()
    student.wash()
