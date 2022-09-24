package design_patterns.java.strategy;

public class CashRebate extends CashSuper {
    private double moneyRebate;

    public CashRebate(String moneyRebate) {
        this.moneyRebate = Double.parseDouble(moneyRebate);
    }

    @Override
    public double acceptCash(double money) {
        return money * moneyRebate;
    }

    public double getMoneyRebate() {
        return moneyRebate;
    }
  
    public void setMoneyRebate(double moneyRebate) {
        this.moneyRebate = moneyRebate;
    }
}
