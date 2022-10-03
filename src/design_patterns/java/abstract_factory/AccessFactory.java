package design_patterns.java.abstract_factory;

public class AccessFactory implements Factory {
    @Override
    public User createUser() {
        return new AccessUser();
    }

    @Override
    public Department createDepartment() {
        return new AccessDepartment();
    }
}
