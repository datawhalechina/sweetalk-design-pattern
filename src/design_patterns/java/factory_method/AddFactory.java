package design_patterns.java.factory_method;

import design_patterns.java.simple_factory.Operation;
import design_patterns.java.simple_factory.OperationAdd;

public class AddFactory implements IFactory{
    @Override
    public Operation createOperation() {
        return new OperationAdd();
    }
}
