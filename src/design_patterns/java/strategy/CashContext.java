package design_patterns.java.strategy;

public class CashContext {

    private CashSuper cs;

    public CashContext(String type) {
        switch(type){
            case "正常收费":
                this.cs = new CashNormal();
                break;
            case "满返":
                this.cs = new CashReturn("300", "100");
                break;
            case "打折":
                this.cs = new CashRebate("0.8");
                break;
        }
    }

    public double getResult(double money){
        return cs.acceptCash(money);
    }
}
