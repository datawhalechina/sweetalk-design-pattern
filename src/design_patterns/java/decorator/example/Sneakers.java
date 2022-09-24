package design_patterns.java.decorator.example;

public class Sneakers extends Finery{
    @Override
    public void show() {
        System.out.println("运动鞋");
        super.show();
    }
}