# -*- coding:utf-8 -*-
'''
@File    :   Strategy.py
@Time    :   2022/09/23 13:40:07
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
@License :

    (c) Copyright 2022 SheltonXiao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or(at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY;without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see < https: //www.gnu.org/licenses/>.
'''

class Strategy(object):
    def algorithm_interface(self):
        pass

class ConcreteStrategyA(Strategy):
    def algorithm_interface(self):
        print("算法A实现")

class ConcreteStrategyB(Strategy):
    def algorithm_interface(self):
        print("算法B实现")

class ConcreteStrategyC(Strategy):
    def algorithm_interface(self):
        print("算法C实现")

class Context(object):
    def __init__(self,strategy):
        self.strategy = strategy
    def context_interface(self):
        self.strategy.algorithm_interface()


if __name__ == '__main__':
    context = Context(ConcreteStrategyA())
    context.context_interface()
    context = Context(ConcreteStrategyB())
    context.context_interface()
    context = Context(ConcreteStrategyC())
    context.context_interface()
