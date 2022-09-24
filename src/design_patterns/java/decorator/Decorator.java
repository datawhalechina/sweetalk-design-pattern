package design_patterns.java.decorator;

public abstract class Decorator extends Component {
    protected Component component;

    public void setComponent(Component component) {
        this.component = component;
    }
    public Component getComponent() {
        return component;
    }

    @Override
    public void operation() {
        if (component != null) {
            component.operation();
        }
    }
}