# -*- coding:utf-8 -*-
'''
@File    :   Prototype.py
@Time    :   2022/09/26 16:01:37
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
import copy

class Prototype(object):
    def __init__(self):
        self._objects = {}
    def register(self,name,obj):
        self._objects[name] = obj
    def unregister(self,name):
        if name in self._objects:
            del self._objects[name]
    def clone(self,name,**kwags):
        prototypeObj = self._objects.get(name)
        if not prototypeObj:
            raise ValueError("Incorrect object name")
        obj = copy.deepcopy(prototypeObj)
        obj.__dict__.update(kwags)
        return obj

class WorkExperience(object):
    __workDate = 0
    __company = 0
    def get_workDate(self):
        return self.__workDate
    def set_workDate(self,workDate):
        self.__workDate = workDate
    def get_company(self):
        return self.__company
    def set_company(self,company):
        self.__company = company
    workDate = property(get_workDate,set_workDate)
    company = property(get_company,set_company)

class Resume(object):
    def __init__(self,name):
        self.name = name
        self.work = WorkExperience()
    def setPersonalInfo(self,sex,age):
        self.sex = sex
        self.age = age
    def setWorkExperience(self,timeArea,company):
        self.work.workDate = timeArea
        self.work.company = company
    def display(self):
        print(" ".join([self.name,self.sex,self.age]))
        print(" ".join(["工作经历：",self.work.workDate,self.work.company]))

if __name__ == '__main__':
    prototype = Prototype()
    a = Resume("大鸟")
    a.setPersonalInfo("男","29")
    a.setWorkExperience("1998-2000","XX公司")
    prototype.register("a",a)

    b = prototype.clone("a")
    b.setWorkExperience("1998-2006","YY企业")

    c = prototype.clone("a")
    c.setPersonalInfo("男","24")
    c.setWorkExperience("1998-2003","ZZ企业")

    a.display()
    b.display()
    c.display()
