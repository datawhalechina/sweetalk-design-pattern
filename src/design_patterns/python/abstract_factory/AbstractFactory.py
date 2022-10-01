# -*- coding:utf-8 -*-
'''
@File    :   AbstractFactory.py
@Time    :   2022/09/27 16:36:19
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
# 表
class User(object):
    __int_id = None
    __name = ""
    def get_id(self):
        return self.__int_id
    def set_id(self,id):
        self.__int_id = id
    def get_name(self):
        return self.__name
    def set_name(self,name):
        self.__name = name
    ID = property(get_id,set_id)
    name = property(get_name,set_name)

class Department(object):
    __int_id = None
    __deptName = ""
    def get_id(self):
        return self.__int_id
    def set_id(self,id):
        self.__int_id = id
    def get_deptName(self):
        return self.__deptName
    def set_deptName(self,deptName):
        self.__deptName = deptName
    ID = property(get_id,set_id)
    deptName = property(get_deptName,set_deptName)

# 操作表
class IUser(object):
    def insert(self,user):
        pass
    def get_user(self,id):
        pass

class SqlserverUser(IUser):
    def insert(self,user):
        print("在SQL Server中给User表增加一条记录")
    def get_user(self,id):
        print("在SQL Server中根据ID得到User表一条记录")
        return None

class AccessUser(IUser):
    def insert(self,user):
        print("在Access中给User表增加一条记录")
    def get_user(self,id):
        print("在Access中根据ID得到User表一条记录")
        return None

class IDepartment(object):
    def insert(self,department):
        pass
    def get_department(self,id):
        pass

class SqlserverDepartment(IDepartment):
    def insert(self,department):
        print("在SQL Server中给Department表增加一条记录")
    def get_department(self, id):
        print("在SQL Server中根据ID得到Department表一条记录")
        return None

class AccessDepartment(IDepartment):
    def insert(self,department):
        print("在Access中给Department表增加一条记录")
    def get_department(self, id):
        print("在Access中根据ID得到Department表一条记录")
        return None

# 抽象工厂
class IFactory(object):
    def create_user(self):
        pass
    def create_department(self):
        pass

class SqlServerFactory(IFactory):
    def create_user(self):
        return SqlserverUser()
    def create_department(self):
        return SqlserverDepartment()

class AccessFactory(IFactory):
    def create_user(self):
        return AccessUser()
    def create_department(self):
        return AccessDepartment()

# 用简单工厂改进抽象工厂
class DataAccess(object):
    __db = "Sqlserver"
    #__db = "Access"
    def create_user(self):
        result = None
        if self.__db == "Sqlserver":
            result = SqlserverUser()
        elif self.__db == "Access":
            result = AccessUser()
        return result
    def create_department(self):
        result = None
        if self.__db == "Sqlserver":
            result = SqlserverDepartment()
        elif self.__db == "Access":
            result = AccessDepartment()
        return result

if __name__ == '__main__':
    # 抽象工厂
    user = User()
    dept = Department()

    #factory = SqlServerFactory()
    factory = AccessFactory()

    iu1 = factory.create_user()
    iu1.insert(user)
    iu1.get_user(1)

    id1 = factory.create_department()
    id1.insert(dept)
    id1.get_department(1)

    # 用简单工厂改进抽象工厂
    iu2 = DataAccess().create_user()
    iu2.insert(user)
    iu2.get_user(1)

    id2 = DataAccess().create_department()
    id2.insert(dept)
    id2.get_department(1)
