# -*- coding:utf-8 -*-
'''
@File    :   Composite.py
@Time    :   2022/09/28 18:34:26
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
class Company(object):
    _name = ""
    def __init__(self,name):
        self._name = name
    def add(self,c):
        pass
    def remove(self,c):
        pass
    def display(self,depth):
        pass
    def line_of_duty(self):
        pass

# 具体公司类 实现接口 树枝节点
class ConcreteCompany(Company):
    def __init__(self,name):
        self.__name = name
        self.__children = []
    def add(self,c):
        self.__children.append(c)
    def remove(self,c):
        self.__children.remove(c)
    def display(self,depth):
        print("-"*depth+self.__name)
        for each in self.__children:
            each.display(depth+2)
    def line_of_duty(self):
        for each in self.__children:
            each.line_of_duty()

# 人力资源部
class HRDepartment(Company):
    def __init__(self,name):
        self.__name = name
    def add(self,c):
        pass
    def remove(self,c):
        pass
    def display(self,depth):
        print("-"*depth+self.__name)
    def line_of_duty(self):
        print(f"{self.__name} 员工招聘培训管理")

# 财务部
class FinanceDepartment(Company):
    def __init__(self,name):
        self.__name = name
    def add(self,c):
        pass
    def remove(self,c):
        pass
    def display(self,depth):
        print("-"*depth+self.__name)
    def line_of_duty(self):
        print(f"{self.__name} 公司财务收支管理")


if __name__ == '__main__':
    root = ConcreteCompany("北京总公司")
    root.add(HRDepartment("总公司人力资源部"))
    root.add(FinanceDepartment("总公司财务部"))

    comp = ConcreteCompany("上海华东分公司")
    comp.add(HRDepartment("华东分公司人力资源部"))
    comp.add(FinanceDepartment("华东分公司财务部"))
    root.add(comp)

    comp1 = ConcreteCompany("南京办事处")
    comp1.add(HRDepartment("南京办事处人力资源部"))
    comp1.add(FinanceDepartment("南京办事处财务部"))
    root.add(comp1)

    comp2 = ConcreteCompany("杭州办事处")
    comp2.add(HRDepartment("杭州办事处人力资源部"))
    comp2.add(FinanceDepartment("杭州办事处财务部"))
    root.add(comp2)

    print("\n 结构图：")
    root.display(1)

    print("\n 职责：")
    root.line_of_duty()
