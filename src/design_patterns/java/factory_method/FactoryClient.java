package design_patterns.java.factory_method;

import design_patterns.java.simple_factory.Operation;

public class FactoryClient {
    public static void main(String[] args) {
        IFactory operFactory = new AddFactory();
        Operation operation = operFactory.createOperation();

        operation.numberA = 1;
        operation.numberB = 2;
        System.out.println(operation.getResult());
    }
}