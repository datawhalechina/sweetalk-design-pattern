# -*- coding:utf-8 -*-
'''
@File    :   Proxy.py
@Time    :   2022/09/23 19:06:10
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# here put the import lib


class Subject(object):
    def request(self):
        pass


class RealSubject(Subject):
    def request(self):
        print("真实的请求")


class Proxy(Subject):
    realSubject = None

    def request(self):
        if self.realSubject is None:
            self.realSubject = RealSubject()
        self.realSubject.request()


if __name__ == '__main__':
    proxy = Proxy()
    proxy.request()
