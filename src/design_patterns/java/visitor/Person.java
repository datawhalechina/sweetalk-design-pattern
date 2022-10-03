package design_patterns.java.visitor;

public abstract class Person {
    public abstract void accept(Action visitor);
}
