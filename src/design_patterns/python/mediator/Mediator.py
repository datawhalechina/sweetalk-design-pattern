# -*- coding:utf-8 -*-
'''
@File    :   Mediator.py
@Time    :   2022/09/30 16:56:14
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# 联合国机构类
class UnitedNations(object):
    def declare(self,message,colleague):
        pass

# 国家类
class Country(object):
    def __init__(self,mediator:UnitedNations):
        self.mediator = mediator

# 美国类
class USA(Country):
    def __init__(self,mediator:UnitedNations):
        super().__init__(mediator)
    def declare(self,message):
        self.mediator.declare(message,self)
    def get_message(self,message):
        print("美国获得对方信息："+message)

# 伊拉克类
class Iraq(Country):
    def __init__(self,mediator:UnitedNations):
        super().__init__(mediator)
    def declare(self,message):
        self.mediator.declare(message,self)
    def get_message(self,message):
        print("伊拉克获得对方信息："+message)

# 联合国安理会
class UnitedNationSecurityCouncil(UnitedNations):
    __colleague1 = None
    __colleague2 = None
    def get_colleague1(self):
        return self.__colleague1
    def get_colleague2(self):
        return self.__colleague2
    def set_colleague1(self,value):
        self.__colleague1 = value
    def set_colleague2(self,value):
        self.__colleague2 = value
    colleague1 = property(get_colleague1,set_colleague1)
    colleague2 = property(get_colleague2,set_colleague2)
    def declare(self, message, colleague:Country):
        if colleague == self.colleague1:
            self.colleague2.get_message(message)
        else:
            self.colleague1.get_message(message)

if __name__ == '__main__':
    UNSC = UnitedNationSecurityCouncil()
    c1 = USA(UNSC)
    c2 = Iraq(UNSC)

    UNSC.colleague1 = c1
    UNSC.colleague2 = c2

    c1.declare("不准研制核武器，否则要发动战争！")
    c2.declare("我们没有核武器，也不怕侵略。")
