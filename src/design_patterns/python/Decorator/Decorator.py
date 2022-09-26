# -*- coding:utf-8 -*-
'''
@File    :   Decorator.py
@Time    :   2022/09/23 14:54:07
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

class Component(object):
    def operation(self):
        pass

class ConcreteComponent(Component):
    def operation(self):
        print("具体对象的操作")

class Decorator(Component):
    __component = None
    def set_component(self,component):
        self.__component = component
    def operation(self):
        if self.__component != None:
            self.__component.operation()

class ConcreteDecoratorA(Decorator):
    __addedState = None
    def operation(self):
        super().operation()
        self.__addedState = "New State"
        print("具体装饰对象A的操作")

class ConcreteDecoratorB(Decorator):
    def operation(self):
        super().operation()
        self.added_behavior()
        print("具体装饰对象B的操作")
    def added_behavior(self):
        pass

if __name__ == '__main__':
    c = ConcreteComponent()
    d1 = ConcreteDecoratorA()
    d2 = ConcreteDecoratorB()

    d1.set_component(c)
    d2.set_component(d1)
    d2.operation()
