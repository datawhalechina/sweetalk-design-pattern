package design_patterns.java.simple_factory;

public class OperationSub extends Operation {
    @Override
    public double getResult() {
        return numberA - numberB;
    }
}