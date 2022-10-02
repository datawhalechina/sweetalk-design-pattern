package design_patterns.java.builder;

import java.awt.*;

public abstract class PersonBuilder {
    protected Graphics2D g;
    protected Pen p;

    public PersonBuilder(Graphics2D g, Pen p) {
        g.setStroke(new BasicStroke(p.getLineWidth()));
        g.setColor(p.getColor());
        this.g = g;
        this.p = p;
    }

    public abstract void buildHead();
    public abstract void buildBody();
    public abstract void buildArmLeft();
    public abstract void buildArmRight();
    public abstract void buildLegLeft();
    public abstract void buildLegRight();
}
