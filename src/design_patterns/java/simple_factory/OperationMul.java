package design_patterns.java.simple_factory;

public class OperationMul extends Operation {
    @Override
    public double getResult() {
        return numberA * numberB;
    }
}