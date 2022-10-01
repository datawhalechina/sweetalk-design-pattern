# -*- coding:utf-8 -*-
'''
@File    :   Flyweight.py
@Time    :   2022/09/30 17:17:25
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
import collections

class WebSite(object):
    def use(self,user):
        pass

class ConcreteWebSite(WebSite):
    __name = ""
    def __init__(self,name):
        self.__name = name
    def use(self,user):
        print("网站分类："+self.__name+" 用户："+user.name)

# 网站工厂类
class WebSiteFactory(object):
    __flyweights = dict()
    def get_website_category(self,key):
        if key not in self.__flyweights:
            self.__flyweights[key] = ConcreteWebSite(key)
        return self.__flyweights[key]
    def get_website_count(self):
        return len(self.__flyweights)

# 用户
class User(object):
    __name = ""
    def __init__(self,name):
        self.__name = name
    def set_name(self,value):
        self.__name = value
    def get_name(self):
        return self.__name
    name = property(get_name,set_name)


if __name__ == '__main__':
    f = WebSiteFactory()
    fx = f.get_website_category("产品展示")
    fx.use(User("小菜"))
    fy = f.get_website_category("产品展示")
    fy.use(User("大鸟"))
    fz = f.get_website_category("产品展示")
    fz.use(User("娇娇"))
    fl = f.get_website_category("博客")
    fl.use(User("老顽童"))
    fm = f.get_website_category("博客")
    fm.use(User("桃谷六仙"))
    fn = f.get_website_category("博客")
    fn.use(User("南海鳄神"))

    print(f"得到网站分类总数为 {f.get_website_count()}")
