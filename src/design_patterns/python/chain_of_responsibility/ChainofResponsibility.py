# -*- coding:utf-8 -*-
'''
@File    :   ChainofResponsibility.py
@Time    :   2022/09/30 15:14:59
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
class Request(object):
    __requestType = None
    __requestContent = None
    __number = None
    def get_requestType(self):
        return self.__requestType
    def set_requestType(self,value):
        self.__requestType = value
    def get_requestContent(self):
        return self.__requestContent
    def set_requestContent(self,value):
        self.__requestContent = value
    def get_number(self):
        return self.__number
    def set_number(self,value):
        self.__number = value
    requestType = property(get_requestType,set_requestType)
    requestContent = property(get_requestContent,set_requestContent)
    number = property(get_number,set_number)

# 管理者
class Manager(object):
    superior = None
    def __init__(self,name):
        self.name = name
    def set_superior(self,superior):
        self.superior = superior
    def request_applications(self,request:Request):
        pass

# 经理类
class CommonManager(Manager):
    def __init__(self,name):
        super().__init__(name)
    def request_applications(self,request:Request):
        if (request.requestType == "请假") and (request.number <= 2):
            print(f"{self.name}:{request.requestContent} 数量{request.number} 被批准")
        else:
            if self.superior != None:
                self.superior.request_applications(request)

# 总监
class Majordomo(Manager):
    def __init__(self,name):
        super().__init__(name)
    def request_applications(self,request:Request):
        if (request.requestType == "请假") and (request.number <= 5):
            print(f"{self.name}:{request.requestContent} 数量{request.number} 被批准")
        else:
            if self.superior != None:
                self.superior.request_applications(request)

# 总经理
class GeneralManager(Manager):
    def __init__(self,name):
        super().__init__(name)
    def request_applications(self,request:Request):
        if (request.requestType == "请假"):
            print(f"{self.name}:{request.requestContent} 数量{request.number} 被批准")
        elif (request.requestType == "加薪") and (request.number <= 500):
            print(f"{self.name}:{request.requestContent} 数量{request.number} 被批准")
        elif (request.requestType == "加薪") and (request.number > 500):
            print(f"{self.name}:{request.requestContent} 数量{request.number} 再说吧")

if __name__ == '__main__':
    jinli = CommonManager("金利")
    zongjian = Majordomo("宗剑")
    zhongjingli = GeneralManager("钟精励")
    jinli.set_superior(zongjian)
    zongjian.set_superior(zhongjingli)

    request = Request()
    request.requestType = "请假"
    request.requestContent = "小菜请假"
    request.number = 1
    jinli.request_applications(request)

    request2 = Request()
    request2.requestType = "请假"
    request2.requestContent = "小菜请假"
    request2.number = 4
    jinli.request_applications(request2)

    request3 = Request()
    request3.requestType = "加薪"
    request3.requestContent = "小菜请求加薪"
    request3.number = 500
    jinli.request_applications(request3)

    request4 = Request()
    request4.requestType = "加薪"
    request4.requestContent = "小菜请求加薪"
    request4.number = 1000
    jinli.request_applications(request4)