# -*- coding:utf-8 -*-
'''
@File    :   Observer.py
@Time    :   2022/09/27 15:55:25
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''


class Observer(object):
    def __init__(self,name,sub):
        self.name = name
        self.sub = sub
    def update(self):
        pass

class Subject(object):
    subjectState = ""
    def attach(self,observer:Observer):
        pass
    def detach(self,observer:Observer):
        pass
    def notify(self):
        pass

class StockObserver(Observer):
    def __init__(self,name,sub:Subject):
        super().__init__(name,sub)
    def update(self):
        print(" ".join([self.sub.subjectState,self.name,"关闭股票行情，继续工作！"]))

class NBAObserver(Observer):
    def __init__(self,name,sub:Subject):
        super().__init__(name,sub)
    def update(self):
        print(" ".join([self.sub.subjectState,self.name,"关闭NBA直播，继续工作！"]))


class Boss(Subject):
    __observers = []
    __action = ""
    def attach(self,observer):
        self.__observers.append(observer)
    def detach(self,observer):
        self.__observers.remove(observer)
    def notify(self):
        for each in self.__observers:
            each.update()
    def get_action(self):
        return self.__action
    def set_action(self,action):
        self.__action = action
    subjectState = property(get_action,set_action)

class Secretary(Subject):
    __observers = []
    __action = ""
    def attach(self,observer):
        self.__observers.append(observer)
    def detach(self,observer):
        self.__observers.remove(observer)
    def notify(self):
        for each in self.__observers:
            each.update()
    def get_action(self):
        return self.__action
    def set_action(self,action):
        self.__action = action
    subjectState = property(get_action,set_action)


if __name__ == '__main__':
    # 老板胡汉三
    huhansan = Boss()

    # 看股票的同事
    tongshi1 = StockObserver("魏关姹",huhansan)
    # 看NBA的同事
    tongshi2 = NBAObserver("易管查",huhansan)

    huhansan.attach(tongshi1)
    huhansan.attach(tongshi2)

    huhansan.detach(tongshi1)

    # 老板回来
    huhansan.subjectState = "我胡汉三回来了！"
    # 发出通知
    huhansan.notify()
