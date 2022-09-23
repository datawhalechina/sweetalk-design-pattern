# -*- coding:utf-8 -*-
'''
@File    :   SimpleSelectClothes.py
@Time    :   2022/09/23 14:28:22
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
    def wear_Tshirts(self):
        print("大T恤 ",end = "")
    def wear_big_trouser(self):
        print("垮裤 ",end = "")
    def wear_sneakers(self):
        print("破球鞋 ",end = "")
    def wear_suit(self):
        print("西装 ",end = "")
    def wear_tie(self):
        print("领带 ",end = "")
    def wear_leather_shoes(self):
        print("皮鞋 ",end = "")
    def show(self):
        print("装扮的"+self.name)

if __name__ == '__main__':
    xc = Person("小菜")
    print("第一种装扮：")
    xc.wear_Tshirts()
    xc.wear_big_trouser()
    xc.wear_sneakers()
    xc.show()

    print("第二种装扮：")
    xc.wear_suit()
    xc.wear_tie()
    xc.wear_leather_shoes()
    xc.show()
