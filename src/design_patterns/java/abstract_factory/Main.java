package design_patterns.java.abstract_factory;


public class Main {
    public static void main(String[] args) {
        User user = new AccessUser();
        Department dept = new AccessDepartment();

        Factory factory = new AccessFactory();
        User iu = factory.createUser();

        iu.insert(user);
        iu.getUser(1);

        Department department = factory.createDepartment();
        department.Insert(dept);
        department.getDepartment(1);
    }
}
