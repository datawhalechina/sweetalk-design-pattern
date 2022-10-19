package design_patterns.java.visitor;

public class Failing extends Action {
    private String name = "失败";

    @Override
    public void getManConclusion(Man man) {
        System.out.println(man.name + this.name + "时，闷头喝酒，谁也不用劝。");
    }

    @Override
    public void getWomanConclusion(Woman woman) {
        System.out.println(woman.name + this.name + "时，眼泪汪汪，谁也劝不了。");
    }
}
