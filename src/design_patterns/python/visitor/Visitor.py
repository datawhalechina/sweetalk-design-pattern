# -*- coding:utf-8 -*-
'''
@File    :   Visitor.py
@Time    :   2022/10/05 14:50:35
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# 状态抽象类
class Action(object):
    def get_man_conclusion(self,concreteElementA):
        pass
    def get_woman_conclusion(self,concreteElementB):
        pass

# 人抽象类
class Person(object):
    def accept(self,visitor:Action):
        pass

# 具体状态类
# 成功
class Success(Action):
    __name = "成功"
    def get_man_conclusion(self,concreteElementA):
        print(f"{concreteElementA.__class__.__name__}{self.__name}时，背后多半有一个伟大的女人。")
    def get_woman_conclusion(self,concreteElementB):
        print(f"{concreteElementB.__class__.__name__}{self.__name}时，背后大多有一个不成功的男人。")

# 失败
class Failing(Action):
    __name = "失败"
    def get_man_conclusion(self,concreteElementA):
        print(f"{concreteElementA.__class__.__name__}{self.__name}时，闷头喝酒，谁也不用劝。")
    def get_woman_conclusion(self,concreteElementB):
        print(f"{concreteElementB.__class__.__name__}{self.__name}时，眼泪汪汪，谁也劝不了。")

# 恋爱
class Amativeness(Action):
    __name = "恋爱"
    def get_man_conclusion(self,concreteElementA):
        print(f"{concreteElementA.__class__.__name__}{self.__name}时，凡事不懂也要装懂。")
    def get_woman_conclusion(self,concreteElementB):
        print(f"{concreteElementB.__class__.__name__}{self.__name}时，遇事懂也装作不懂。")

# 结婚
class Marriage(Action):
    __name = "结婚"
    def get_man_conclusion(self,concreteElementA):
        print(f"{concreteElementA.__class__.__name__}{self.__name}时，感慨道：恋爱游戏终结时，‘有妻徒刑’遥无期。")
    def get_woman_conclusion(self,concreteElementB):
        print(f"{concreteElementB.__class__.__name__}{self.__name}时，欣慰曰：爱情长跑路漫漫，婚姻保险保平安。")

# 男人和女人类
# 男人
class Man(Person):
    def accept(self,visitor:Action):
        visitor.get_man_conclusion(self)

# 女人
class Woman(Person):
    def accept(self,visitor:Action):
        visitor.get_woman_conclusion(self)


# 对象结构类
class ObjectStructure(object):
    def __init__(self):
        self.__elements = []
    def attach(self,element:Person):
        self.__elements.append(element)
    def detach(self,element:Person):
        self.__elements.remove(element)
    def display(self,vistor:Action):
        for each in self.__elements:
            each.accept(vistor)


if __name__ == '__main__':
    o = ObjectStructure()
    o.attach(Man())
    o.attach(Woman())

    # 成功时的反应
    v1 = Success()
    o.display(v1)

    # 失败时的反应
    v2 = Failing()
    o.display(v2)

    # 恋爱时的反应
    v3 = Amativeness()
    o.display(v3)

    # 结婚时的反应
    v4 = Marriage()
    o.display(v4)
