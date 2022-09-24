package design_patterns.java.proxy;

public class Proxy implements Subject {
    Subject subject;

    public Proxy() {
        subject = new RealSubject();
    }

    @Override
    public void request() {
        subject.request();
    }
}
