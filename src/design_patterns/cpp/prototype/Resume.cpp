#include<iostream>

#include "Resume.h"

using namespace std;


class WorkExperience: public ICloneable
{
public:
    void setWorkDate(string workDate)
    {
        m_workDate = workDate;
    }

    void setCompany(string company)
    {
        m_company = company;
    }

    string getWorkDate()
    {
        return m_workDate;
    }

    string getCompany()
    {
        return m_company;
    }

    WorkExperience * clone() const override
    {
        return new WorkExperience(*this);
    }

private:
    string m_workDate;
    string m_company;
};


class Resume: public ICloneable
{
public:
    Resume(string name)
    {
        m_name = name;
        m_work = new WorkExperience();
    }

    Resume(WorkExperience * work)
    {
        m_work = work->clone();
    }

    void setPersonalInfo(string sex, string age)
    {
        m_sex = sex;
        m_age = age;
    }

    void setWorkExperience(string workDate, string company)
    {
        m_work->setWorkDate(workDate);
        m_work->setCompany(company);
    }

    void display()
    {
        cout << m_name << " " << m_sex << " " << m_age << endl;
        cout << "工作经历：" << m_work->getWorkDate() << " " << m_work->getCompany() << endl;
    }

    Resume *clone() const override
    {
        Resume *obj = new Resume(m_work);
        obj->m_name = m_name;
        obj->m_sex = m_sex;
        obj->m_age = m_age;
        return obj;
    }

private:
    string m_name;
    string m_sex;
    string m_age;
    WorkExperience * m_work;
};


int main() {

    Resume * a = new Resume("大鸟");
    a->setPersonalInfo("男", "29");
    a->setWorkExperience("1998-2000", "XX公司");

    Resume * b = a->clone();
    b->setWorkExperience("1998-2006", "YY企业");

    Resume * c = a->clone();
    c->setPersonalInfo("男", "24");
    c->setWorkExperience("1998-2003", "ZZ企业");

    a->display();
    b->display();
    c->display();

    return 0;
}