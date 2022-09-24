package design_patterns.java.decorator;

public class ConcreteDecoratorB extends Decorator {
    @Override
    public void operation() {
        super.operation();
        addedBehavior();
        System.out.println("具体装饰对象B的操作");
    }

    public void addedBehavior() {
        System.out.print("B中的新增行为 ");
    }
}
