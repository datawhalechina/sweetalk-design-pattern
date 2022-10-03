package design_patterns.java.builder;

import java.awt.*;

public class Pen {
    private int lineWidth;
    private Color color;

    public Pen(int lineWidth, Color color) {
        this.lineWidth = lineWidth;
        this.color = color;
    }

    public int getLineWidth(){
        return lineWidth;
    }

    public Color getColor(){
        return color;
    }
}
