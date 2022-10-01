# -*- coding:utf-8 -*-
'''
@File    :   iterator.py
@Time    :   2022/09/28 20:04:39
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''


class Iterator(object):
    def first(self):
        pass
    def next(self):
        pass
    def is_done(self):
        pass
    def current_item(self):
        pass

class Aggregate(object):
    def create_iterator(self):
        pass

class ConcreteAggregate(Aggregate):
    def __init__(self):
        self.__items = []
    def __call__(self,index,value=None):
        if value != None:
            self.__items.insert(index,value)
        else:
            return self.__items[index]
    def create_iterator(self):
        return ConcreteIterator(self)
    def get_count(self):
        return len(self.__items) 
    count = property(get_count)

class ConcreteIterator(Iterator):
    __aggregate = None
    __current = 0
    def __init__(self,aggregate:ConcreteAggregate):
        self.__aggregate = aggregate
    def first(self):
        return self.__aggregate(0)
    def next(self):
        ret = None
        self.__current = self.__current + 1
        if self.__current < self.__aggregate.count:
            ret = self.__aggregate(self.__current)
        return ret
    def is_done(self):
        return self.__current >= self.__aggregate.count
    def current_item(self):
        return self.__aggregate(self.__current)

# 从后往前的迭代器
class ConcreteIteratorDesc(Iterator):
    __aggregate = None
    __current = 0
    def __init__(self,aggregate:ConcreteAggregate):
        self.__aggregate = aggregate
        self.__current = aggregate.count - 1
    def first(self):
        return self.__aggregate(self.__aggregate.count - 1)
    def next(self):
        ret = None
        self.__current = self.__current - 1
        if self.__current > 0:
            ret = self.__aggregate(self.__current)
        return ret
    def is_done(self):
        return self.__current < 0
    def current_item(self):
        return self.__aggregate(self.__current)


if __name__ == '__main__':
    a = ConcreteAggregate()
    a(0,"大鸟")
    a(1,"小菜")
    a(2,"行李")
    a(3,"老外")
    a(4,"公交内部员工")
    a(5,"小偷")

    #i = ConcreteIterator(a)
    i = ConcreteIteratorDesc(a)

    item = i.first()
    while not i.is_done():
        print(f"{i.current_item()} 请买车票！")
        i.next()
