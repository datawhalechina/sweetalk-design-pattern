package design_patterns.java.composite;

import java.util.ArrayList;
import java.util.List;

public class ConcreteCompany extends Company {

    private List<Company> children = new ArrayList<>();

    public ConcreteCompany(String name) {
        super(name);
    }

    @Override
    public void add(Company c) {
        children.add(c);
    }

    @Override
    public void remove(Company c) {
        children.remove(c);
    }

    @Override
    public void display(int depth) {
        for(int i = 0; i < depth; i++) {
            System.out.print("-");
        }
        System.out.println(this.name);

        for(Company component : children) {
            component.display(depth + 2);
        }
    }

    @Override
    public void lineOfDuty() {
        for(Company component : children) {
            component.lineOfDuty();
        }
    }
}
