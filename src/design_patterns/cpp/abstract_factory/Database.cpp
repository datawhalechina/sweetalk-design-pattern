#include <iostream>

#include "Database.h"

using namespace std;

void SqlserverUser::insert(User * user)
{
    cout << "在SQL Server中给User表增加一条记录" << endl;
}

User * SqlserverUser::getUser(int id)
{
    cout << "在SQL Server中根据ID得到User表一条记录" << endl;
    return NULL;
} 

void AccessUser::insert(User * user)
{
    cout << "在Access中给User表增加一条记录" << endl;
}

User * AccessUser::getUser(int id)
{
    cout << "在Access中根据ID得到User表一条记录" << endl;
    return NULL;
}

void SqlserverDepartment::insert(Department * dept)
{
    cout << "在SQL Server中给Department表增加一条记录" << endl;
}

Department * SqlserverDepartment::getDepartment(int id)
{
    cout << "在SQL Server中根据ID得到Department表一条记录" << endl;
    return NULL;
} 

void AccessDepartment::insert(Department * dept)
{
    cout << "在Access中给Department表增加一条记录" << endl;
}

Department * AccessDepartment::getDepartment(int id)
{
    cout << "在Access中根据ID得到Department表一条记录" << endl;
    return NULL;
} 


SqlserverUser * SqlserverFactory::createUser()
{
    return new SqlserverUser();
}

AccessUser * AccessFactory::createUser()
{
    return new AccessUser();
}

SqlserverDepartment * SqlserverFactory::createDepartment()
{
    return new SqlserverDepartment();
}

AccessDepartment * AccessFactory::createDepartment()
{
    return new AccessDepartment();
}


int main()
{
    User * user = new User();
    Department * dept = new Department();

    IFactory * factory = new AccessFactory();
    // IFactory * factory = new SqlserverFactory();

    IUser * iu = factory->createUser();
    iu->insert(user);
    iu->getUser(1);

    IDepartment * id = factory->createDepartment();
    id->insert(dept);
    id->getDepartment(1);

    return 0;
}