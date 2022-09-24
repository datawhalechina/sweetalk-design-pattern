package design_patterns.java.decorator.example;

public class BigTrouser extends Finery{
    @Override
    public void show() {
        System.out.println("跨裤");
        super.show();
    }
}