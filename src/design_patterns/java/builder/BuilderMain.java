package design_patterns.java.builder;

import javax.swing.*;
import java.awt.*;

public class BuilderMain {
    public static void main(String[] args) {
        JFrame jFrame = new JFrame();

        JPanel jpanel = new JPanel() {
            @Override
            public void paint(Graphics graphics) {
                super.paint(graphics);
                PersonBuilder ptb = new PersonThinBuilder((Graphics2D) graphics, new Pen(2, Color.BLUE));
                PersonDirector pd = new PersonDirector(ptb);
                pd.createPerson();
                PersonBuilder pfb = new PersonFatBuilder((Graphics2D) graphics, new Pen(3, Color.YELLOW));
                pd = new PersonDirector(pfb);
                pd.createPerson();
            }
        };

        jFrame.add(jpanel);
        jFrame.setSize(300, 300);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
