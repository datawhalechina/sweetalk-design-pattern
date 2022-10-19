# -*- coding:utf-8 -*-
'''
@File    :   Facade.py
@Time    :   2022/09/26 18:35:55
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

class Stock1(object):
    def sell(self):
        print(" 股票1卖出")
    def buy(self):
        print(" 股票1买入")

class Stock2(object):
    def sell(self):
        print(" 股票2卖出")
    def buy(self):
        print(" 股票2买入")

class Stock3(object):
    def sell(self):
        print(" 股票3卖出")
    def buy(self):
        print(" 股票3买入")

class NationalDebt1(object):
    def sell(self):
        print(" 国债1卖出")
    def buy(self):
        print(" 国债1买入")

class Realty1(object):
    def sell(self):
        print(" 股票1卖出")
    def buy(self):
        print(" 股票1买入")

class Fund(object):
    def __init__(self):
        self.gu1 = Stock1()
        self.gu2 = Stock2()
        self.gu3 = Stock3()
        self.nd1 = NationalDebt1()
        self.rt1 = Realty1()

    def buy_fund(self):
        self.gu1.buy()
        self.gu2.buy()
        self.gu3.buy()
        self.nd1.buy()
        self.rt1.buy()

    def sell_fund(self):
        self.gu1.sell()
        self.gu2.sell()
        self.gu3.sell()
        self.nd1.sell()
        self.rt1.sell()

if __name__ == '__main__':
    jijin = Fund()
    jijin.buy_fund()
    jijin.sell_fund()
