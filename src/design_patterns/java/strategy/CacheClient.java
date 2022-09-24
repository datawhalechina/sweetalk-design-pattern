package design_patterns.java.strategy;

public class CacheClient {
    public static void main(String[] args) {
        double num = 10;
        double price = 100;

        CashContext csuper1 = new CashContext("正常收费");
        CashContext csuper2 = new CashContext("满返");
        CashContext csuper3 = new CashContext("打折");
        System.out.println(csuper1.getResult(price * num));
        System.out.println(csuper2.getResult(price * num));
        System.out.println(csuper3.getResult(price * num));
    }
}
