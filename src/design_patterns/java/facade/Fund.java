package design_patterns.java.facade;

import design_patterns.java.facade.data.NationalDebt1;
import design_patterns.java.facade.data.Realty1;
import design_patterns.java.facade.data.Stock1;
import design_patterns.java.facade.data.Stock2;
import design_patterns.java.facade.data.Stock3;

public class Fund {
    private Stock1 gu1;
    private Stock2 gu2;
    private Stock3 gu3;
    private NationalDebt1 nd1;
    private Realty1 rt1;

    public Fund() {
        gu1 = new Stock1();
        gu2 = new Stock2();
        gu3 = new Stock3();
        nd1 = new NationalDebt1();
        rt1 = new Realty1();
    }

    public void buyFund() {
        gu1.buy();
        gu2.buy();
        gu3.buy();
        nd1.buy();
        rt1.buy();
    }

    public void sellFund() {
        gu1.sell();
        gu2.sell();
        gu3.sell();
        nd1.sell();
        rt1.sell();
    }
}
