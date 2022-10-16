# -*- coding:utf-8 -*-
'''
@File    :   SimplePursuit.py
@Time    :   2022/09/23 18:50:04
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

class Pursuit(object):
    __mm = None
    def __init__(self,mm:SchoolGirl):
        self.__mm = mm
    def give_dolls(self):
        print(self.__mm.name + " 送你洋娃娃")
    def give_flowers(self):
        print(self.__mm.name + " 送你鲜花")
    def give_chocolate(self):
        print(self.__mm.name + " 送你巧克力")

if __name__ == '__main__':
    jiaojiao = SchoolGirl()
    jiaojiao.name = "李娇娇"

    zhuojiayi = Pursuit(jiaojiao)
    zhuojiayi.give_dolls()
    zhuojiayi.give_flowers()
    zhuojiayi.give_chocolate()
