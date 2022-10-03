package design_patterns.java.abstract_factory;

public interface Department {
    void Insert(Department department);

    Department getDepartment(int id);
}
