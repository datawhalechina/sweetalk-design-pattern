//
// Created by HuRF on 2022/9/21.
//

#include "Company.h"
#include <iostream>

int main() {
    ConcreteCompany root("北京总公司");
    HRDepartment hrDepartment("总公司人力资源部");
    root.Add(hrDepartment);
    FinanceDepartment financeDepartment("总公司财务部");
    root.Add(financeDepartment);

    ConcreteCompany comp("上海华东分公司");
    HRDepartment hrDepartment1("华东分公司人力资源部");
    comp.Add(hrDepartment1);
    FinanceDepartment financeDepartment1("华东分公司财务部");
    comp.Add(financeDepartment1);
    root.Add(comp);

    ConcreteCompany comp1("南京办事处");
    HRDepartment hrDepartment2("南京办事处人力资源部");
    comp1.Add(hrDepartment2);
    FinanceDepartment financeDepartment2("南京办事处财务部");
    comp1.Add(financeDepartment2);
    comp.Add(comp1);

    ConcreteCompany comp2("杭州办事处");
    HRDepartment hrDepartment3("杭州办事处人力资源部");
    comp2.Add(hrDepartment3);
    FinanceDepartment financeDepartment3("杭州办事处财务部");
    comp2.Add(financeDepartment3);
    comp.Add(comp2);

    std::cout << "\n结构图：" << std::endl;
    root.Display(1);

    std::cout << "\n职责：" << std::endl;
    root.LineOfDuty();

    return 0;
}