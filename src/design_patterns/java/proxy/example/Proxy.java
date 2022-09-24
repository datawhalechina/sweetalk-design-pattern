package design_patterns.java.proxy.example;

public class Proxy implements GiveGift {
    Pursuit gg;

    public Proxy(SchoolGirl mm) {
        this.gg = new Pursuit(mm);
    }

    public void giveDolls() {
        gg.giveDolls();
    }

    public void giveFlowers() {
        gg.giveFlowers();
    }

    public void giveChocolate() {
        gg.giveChocolate();
    }
}
