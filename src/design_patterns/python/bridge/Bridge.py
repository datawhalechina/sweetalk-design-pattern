# -*- coding:utf-8 -*-
'''
@File    :   Bridge.py
@Time    :   2022/09/29 20:34:34
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
# 手机软件抽象类
class HandsetSoft(object):
    def run(self):
        pass

# 手机软件具体类
class HandsetGame(HandsetSoft):
    def run(self):
        print("运行手机游戏")

class HandsetAddressList(HandsetSoft):
    def run(self):
        print("运行手机通讯录")

class HandsetMP3(HandsetSoft):
    def run(self):
        print("运行手机MP3播放")

# 手机品牌抽象类
class HandsetBrand(object):
    soft = None
    def set_handset_soft(self,soft):
        self.soft = soft
    def run(self):
        pass

# 手机品牌具体类
class HandsetBrandN(HandsetBrand):
    def run(self):
        self.soft.run()

class HandsetBrandM(HandsetBrand):
    def run(self):
        self.soft.run()

class HandsetBrandS(HandsetBrand):
    def run(self):
        self.soft.run()

if __name__ == '__main__':
    ab = HandsetBrandN()
    ab.set_handset_soft(HandsetGame())
    ab.run()

    ab.set_handset_soft(HandsetAddressList())
    ab.run()

    ab = HandsetBrandM()
    ab.set_handset_soft(HandsetGame())
    ab.run()

    ab.set_handset_soft(HandsetAddressList())
    ab.run()




