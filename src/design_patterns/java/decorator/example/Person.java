package design_patterns.java.decorator.example;

public class Person {
    public Person() {}

    private String name;
    public Person(String name) {
        this.name = name;
    }

    public void show() {
        System.out.println("装扮的" + this.name);
    }
}