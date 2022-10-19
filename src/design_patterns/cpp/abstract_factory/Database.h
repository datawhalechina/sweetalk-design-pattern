using namespace std;

class User
{
private:
    string m_name;
    string m_id;
};

class Department
{
private:
    string m_name;
    string m_id;
};


class IUser
{
public:
    virtual void insert(User * user) = 0;
    virtual User * getUser(int id) = 0;
};

class SqlserverUser: public IUser
{
public:
    void insert(User * user) override;
    User * getUser(int id) override;
};

class AccessUser: public IUser
{
public:
    void insert(User * user) override;
    User * getUser(int id) override;
};

class IDepartment
{
public:
    virtual void insert(Department * dept) = 0;
    virtual Department * getDepartment(int id) = 0;
};

class SqlserverDepartment: public IDepartment
{
public:
    void insert(Department * dept) override;
    Department * getDepartment(int id) override;
};

class AccessDepartment: public IDepartment
{
public:
    void insert(Department * dept) override;
    Department * getDepartment(int id) override;
};


class IFactory
{
public:
    virtual IUser * createUser() = 0;
    virtual IDepartment * createDepartment() = 0;
};

class SqlserverFactory: public IFactory
{
    SqlserverUser * createUser() override;
    SqlserverDepartment * createDepartment() override;
};

class AccessFactory: public IFactory
{
    AccessUser * createUser() override;
    AccessDepartment * createDepartment() override;
};
