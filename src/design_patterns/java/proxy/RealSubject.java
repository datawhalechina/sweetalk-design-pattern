package design_patterns.java.proxy;

public class RealSubject implements Subject {
    @Override
    public void request() {
        System.out.println("真实的请求");
    }
}
