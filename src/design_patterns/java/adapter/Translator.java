package design_patterns.java.adapter;

public class Translator extends Player {
    private ForeignCenter wjzf = new ForeignCenter();

    public Translator(String name) {
        super(name);
        wjzf.setName(name);
    }

    @Override
    public void attack() {
        wjzf.attack();
    }

    @Override
    public void defense() {
        wjzf.defense();
    }
}