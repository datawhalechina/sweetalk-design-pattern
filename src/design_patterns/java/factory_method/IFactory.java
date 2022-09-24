package design_patterns.java.factory_method;

import design_patterns.java.simple_factory.Operation;

public interface IFactory {
    public Operation createOperation();
}
