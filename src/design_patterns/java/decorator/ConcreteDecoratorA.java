package design_patterns.java.decorator;

public class ConcreteDecoratorA extends Decorator {
    private String addedState;

    @Override
    public void operation() {
        super.operation();
        addedState = "New State";
        System.out.println(addedState + "具体装饰对象A的操作");
    }
}
