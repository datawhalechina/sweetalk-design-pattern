package design_patterns.java.chain_of_responsibility;

public abstract class Manager {
    protected String name;
    protected Manager superior;

    protected Manager(String name) {
        this.name = name;
    }

    public void SetSuperior(Manager superior) {
        this.superior = superior;
    }

    public abstract void requestApplications(Request request);
}
