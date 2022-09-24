# -*- coding:utf-8 -*-
'''
@File    :   PursuitWithProxy.py
@Time    :   2022/09/23 19:00:23
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

class SchoolGirl(object):
    __name = None
    def get_name(self):
        return self.__name
    def set_name(self,name):
        self.__name = name
    name = property(get_name,set_name)

class IGiveGift(object):
    def give_dolls(self):
        pass
    def give_flowers(self):
        pass
    def give_chocolate(self):
        pass

class Pursuit(IGiveGift):
    __mm = None
    def __init__(self,mm:SchoolGirl):
        self.__mm = mm
    def give_dolls(self):
        print(self.__mm.name + " 送你洋娃娃")
    def give_flowers(self):
        print(self.__mm.name + " 送你鲜花")
    def give_chocolate(self):
        print(self.__mm.name + " 送你巧克力")

class Proxy(IGiveGift):
    def __init__(self,mm:SchoolGirl):
        self.gg = Pursuit(mm)
    def give_dolls(self):
        self.gg.give_dolls()
    def give_flowers(self):
        self.gg.give_flowers()
    def give_chocolate(self):
        self.gg.give_chocolate()

if __name__ == '__main__':
    jiaojiao = SchoolGirl()
    jiaojiao.name = "李娇娇"

    daili = Proxy(jiaojiao)
    daili.give_dolls()
    daili.give_flowers()
    daili.give_chocolate()
