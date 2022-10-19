package design_patterns.java.abstract_factory;

public class SqlserverDepartment implements Department{
    @Override
    public void Insert(Department department) {
        System.out.println("在SQL Server中给Department表增加一条记录");
    }

    @Override
    public Department getDepartment(int id) {
        System.out.println("在SQL Server中根据ID得到Department表一条记录");
        return null;
    }
}
