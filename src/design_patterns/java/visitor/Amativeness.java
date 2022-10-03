package design_patterns.java.visitor;

public class Amativeness extends Action {
    private String name = "恋爱";

    @Override
    public void getManConclusion(Man man) {
        System.out.println(man.name + this.name + "时，凡事不懂也要装懂。");
    }

    @Override
    public void getWomanConclusion(Woman woman) {
        System.out.println(woman.name + this.name + "时，遇事懂也装作不懂。");
    }
}
