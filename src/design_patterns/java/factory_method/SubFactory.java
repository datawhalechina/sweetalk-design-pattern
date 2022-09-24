package design_patterns.java.factory_method;

import design_patterns.java.simple_factory.Operation;
import design_patterns.java.simple_factory.OperationSub;

public class SubFactory implements IFactory{
    @Override
    public Operation createOperation() {
        return new OperationSub();
    }
}
