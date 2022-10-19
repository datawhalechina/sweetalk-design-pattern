# -*- coding:utf-8 -*-
'''
@File    :   Decorator.py
@Time    :   2022/09/23 14:54:07
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''


class Component(object):
    def operation(self):
        pass


class ConcreteComponent(Component):
    def operation(self):
        print("具体对象的操作")


class Decorator(Component):
    __component = None

    def set_component(self, component):
        self.__component = component

    def operation(self):
        if self.__component is not None:
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
