# -*- coding:utf-8 -*-
'''
@File    :   DecoratorSelectClothes.py
@Time    :   2022/09/23 15:10:06
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
    def __init__(self,name = ""):
        self.name = name
    def show(self):
        print("装扮的"+self.name)

# 服饰类（Decorator）
class Finery(Person):
    component = None
    def decorate(self,component:Person):
        self.component = component
    def show(self):
        if self.component != None:
            self.component.show()

# 具体服饰类（Concrete Decorator）
class TShirts(Finery):
    def show(self):
        print("大T恤 ",end = "")
        super().show()

class BigTrouser(Finery):
    def show(self):
        print("垮裤 ",end = "")
        super().show()

class Sneakers(Finery):
    def show(self):
        print("破球鞋 ",end = "")
        super().show()

class Suit(Finery):
    def show(self):
        print("西装 ",end = "")
        super().show()

class Tie(Finery):
    def show(self):
        print("领带 ",end = "")
        super().show()

class LeatherShoes(Finery):
    def show(self):
        print("皮鞋 ",end = "")
        super().show()

if __name__ == '__main__':
    xc = Person("小菜")
    print("第一种装扮：")
    dtx = TShirts()
    kk = BigTrouser()
    pqx = Sneakers()

    pqx.decorate(xc)
    kk.decorate(pqx)
    dtx.decorate(kk)
    dtx.show()

    print("第二种装扮：")
    xz = Suit()
    ld = Tie()
    px = LeatherShoes()

    px.decorate(xc)
    ld.decorate(px)
    xz.decorate(ld)
    xz.show()

    print("第三种装扮：")
    pqx2 = Sneakers()
    px2 = LeatherShoes()
    kk2 = BigTrouser()
    ld2 = Tie()

    pqx2.decorate(xc)
    px2.decorate(pqx2)
    kk2.decorate(px2)
    ld2.decorate(kk2)
    ld2.show()
