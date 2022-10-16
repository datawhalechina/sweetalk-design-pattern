# -*- coding:utf-8 -*-
'''
@File    :   Observer2.py
@Time    :   2022/09/27 16:18:23
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# 抽象的观察者模式

class Subject(object):
    __observers = []
    def attach(self,observer):
        self.__observers.append(observer)
    def detach(self,observer):
        self.__observers.remove(observer)
    def notify(self):
        for each in self.__observers:
            each.update()

class Observer(object):
    def update(self):
        pass

class ConcreteSubject(Subject):
    __subjectState = ""
    def get_action(self):
        return self.__subjectState
    def set_action(self,action):
        self.__subjectState = action
    subjectState = property(get_action,set_action)

class ConcreteObserver(Observer):
    __name = ""
    __observerState = ""
    __subject = None
    def __init__(self,subject,name):
        self.__name = name
        self.__subject = subject
    def update(self):
        self.__observerState = self.__subject.subjectState
        print("观察者"+self.__name+"的新状态是"+self.__observerState)
    def get_subject(self):
        return self.__subject
    def set_subject(self,subject):
        self.__subject = subject
    subject = property(get_subject,set_subject)


if __name__ == '__main__':
    s = ConcreteSubject()

    s.attach(ConcreteObserver(s,"X"))
    s.attach(ConcreteObserver(s,"Y"))
    s.attach(ConcreteObserver(s,"Z"))

    s.subjectState = "ABC"
    s.notify()