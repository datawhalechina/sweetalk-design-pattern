# -*- coding:utf-8 -*-
'''
@File    :   FactoryMethod.py
@Time    :   2022/09/23 19:13:48
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

class Operation(object):
    __numberA = 0
    __numberB = 0
    def get_numberA(self):
        return self.__numberA
    def set_numberA(self,numberA):
        self.__numberA = numberA
    def get_numberB(self):
        return self.__numberB
    def set_numberB(self,numberB):
        self.__numberB = numberB
    def get_result():
        result = 0
        return result
    numberA = property(get_numberA,set_numberA)
    numberB = property(get_numberB,set_numberB)

class OperationAdd(Operation):
    def get_result(self):
        result = self.numberA + self.numberB
        return result

class OperationSub(Operation):
    def get_result(self):
        result = self.numberA - self.numberB
        return result

class OperationMul(Operation):
    def get_result(self):
        result = self.numberA * self.numberB
        return result

class OperationDiv(Operation):
    def get_result(self):
        if self.numberB == 0:
            raise Exception("除数不能为0")
        result = self.numberA / self.numberB
        return result

# 工厂类
class IFactory(object):
    def create_operation(self) -> Operation:
        pass

class AddFactory(IFactory):
    def create_operation(self) -> Operation:
        return OperationAdd()

class SubFactory(IFactory):
    def create_operation(self) -> Operation:
        return OperationSub()

class MulFactory(IFactory):
    def create_operation(self) -> Operation:
        return OperationMul()

class DivFactory(IFactory):
    def create_operation(self) -> Operation:
        return OperationDiv()

if __name__ == '__main__':
    operFactory = AddFactory()
    oper = operFactory.create_operation()
    oper.numberA = 1
    oper.numberB = 2
    result = oper.get_result()
    print(result)
