# -*- coding:utf-8 -*-
'''
@File    :   Singleton.py
@Time    :   2022/09/29 15:28:32
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
import time
import threading

class Singleton(object):
    # 线程锁
    lock = threading.Lock()
    def __new__(cls,*args,**kwargs):
        # 双重锁定
        if not hasattr(cls,'_instance'):
            with cls.lock:
                if not hasattr(cls,'_instance'):
                    time.sleep(0.5)
                    orig = super(Singleton,cls)
                    cls._instance = orig.__new__(cls,*args,**kwargs)
        return cls._instance

def func():
        obj = Singleton()
        print(id(obj))

if __name__ == '__main__':
    a = Singleton()
    b = Singleton()
    if a == b:
        print("两个对象是相同的实例。")

    # 多线程测试
    for i in range(10):
        thread = threading.Thread(target=func)
        thread.start()
    