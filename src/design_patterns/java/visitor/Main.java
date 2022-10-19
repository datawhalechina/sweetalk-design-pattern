package design_patterns.java.visitor;

public class Main {
    public static void main(String[] args) {
        ObjectStructure o = new ObjectStructure();

        o.attach(new Man());
        o.attach(new Woman());

        Success v1 = new Success();
        o.display(v1);

        Failing v2 = new Failing();
        o.display(v2);

        Amativeness v3 = new Amativeness();
        o.display(v3);

        Marriage v4 = new Marriage();
        o.display(v4);
    }
}
