# -*- coding:utf-8 -*-
'''
@File    :   Adapter.py
@Time    :   2022/09/27 19:27:35
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# 球员
class Player(object):
    name = ""
    def __init__(self,name):
        self.name = name
    def attack(self):
        pass
    def defense(self):
        pass

# 前锋
class Forwards(Player):
    name = ""
    def __init__(self,name):
        self.name = name
    def attack(self):
        print(f"前锋 {self.name} 进攻")
    def defense(self):
        print(f"前锋 {self.name} 防守")

# 中锋
class Center(Player):
    name = ""
    def __init__(self,name):
        self.name = name
    def attack(self):
        print(f"中锋 {self.name} 进攻")
    def defense(self):
        print(f"中锋 {self.name} 防守")

# 后卫
class Guards(Player):
    name = ""
    def __init__(self,name):
        self.name = name
    def attack(self):
        print(f"后卫 {self.name} 进攻")
    def defense(self):
        print(f"后卫 {self.name} 防守")

# 外籍中锋
class ForeignCenter:
    __name = ""
    def __init__(self):
        pass
    def 进攻(self):
        print(f"外籍中锋 {self.name} 进攻")
    def 防守(self):
        print(f"外籍中锋 {self.name} 防守")

    def get_name(self):
        return self.__name
    def set_name(self,name):
        self.__name = name
    name = property(get_name,set_name)

# 翻译者
class Translator(Player):
    __wjzf = ForeignCenter()
    def __init__(self,name):
        self.__wjzf.name = name
    def attack(self):
        self.__wjzf.进攻()
    def defense(self):
        self.__wjzf.防守()

if __name__ == '__main__':
    b = Forwards("巴蒂尔")
    b.attack()
    m = Guards("麦克格雷迪")
    m.attack()

    ym = Translator("姚明")
    ym.attack()
    ym.defense()
