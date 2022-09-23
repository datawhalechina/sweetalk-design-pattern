# -*- coding:utf-8 -*-
'''
@File    :   OCPSelectClothes.py
@Time    :   2022/09/23 14:43:43
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
@License :

    (c) Copyright 2022 SheltonXiao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or(at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY;without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see < https: //www.gnu.org/licenses/>.
'''

class Person(object):
    def __init__(self,name):
        self.name = name
    def show(self):
        print("装扮的"+self.name)

class Finery(object):
    def show(self):
        pass

class TShirts(Finery):
    def show(self):
        print("大T恤 ",end = "")

class BigTrouser(Finery):
    def show(self):
        print("垮裤 ",end = "")

class Sneakers(Finery):
    def show(self):
        print("破球鞋 ",end = "")

class Suit(Finery):
    def show(self):
        print("西装 ",end = "")

class Tie(Finery):
    def show(self):
        print("领带 ",end = "")

class LeatherShoes(Finery):
    def show(self):
        print("皮鞋 ",end = "")

if __name__ == '__main__':
    xc = Person("小菜")
    print("第一种装扮：")
    dtx = TShirts()
    kk = BigTrouser()
    pqx = Sneakers()

    dtx.show()
    kk.show()
    pqx.show()
    xc.show()

    print("第二种装扮：")
    xz = Suit()
    ld = Tie()
    px = LeatherShoes()

    xz.show()
    ld.show()
    px.show()
    xc.show()