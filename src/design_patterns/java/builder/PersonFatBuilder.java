package design_patterns.java.builder;

import java.awt.*;

public class PersonFatBuilder extends PersonBuilder {
    public PersonFatBuilder(Graphics2D g, Pen p) {
        super(g, p);
    }

    @Override
    public void buildHead() {
        g.drawOval(200, 70, 30, 30);
    }

    @Override
    public void buildBody() {
        g.drawRect(185, 100, 60, 30);
    }

    @Override
    public void buildArmLeft() {
        g.drawLine(205, 100, 175, 110);
    }

    @Override
    public void buildArmRight() {
        g.drawLine(225, 100, 250, 110);
    }

    @Override
    public void buildLegLeft() {
        g.drawLine(205, 130, 175, 150);
    }

    @Override
    public void buildLegRight() {
        g.drawLine(225, 130, 250, 150);
    }
}
