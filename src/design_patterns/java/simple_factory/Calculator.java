package design_patterns.java.simple_factory;

public class Calculator {
    public static void main(String[] args) {
        Operation operation;
        char operator;
    
        operator = '+';
        operation = OperationFactory.createOperation(operator);
        operation.numberA = 1;
        operation.numberB = 2;
    
        System.out.println(operation.getResult());
    }
}
