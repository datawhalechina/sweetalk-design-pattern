package design_patterns.java.visitor;

public class Success extends Action {
    private String name = "成功";

    @Override
    public void getManConclusion(Man man) {
        System.out.println(man.name + this.name + "时，背后多半有一个伟大的女人。");
    }

    @Override
    public void getWomanConclusion(Woman woman) {
        System.out.println(woman.name + this.name + "时，背后大多有一个不成功的男人。");
    }
}
