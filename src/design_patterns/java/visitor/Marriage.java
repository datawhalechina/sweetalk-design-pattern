package design_patterns.java.visitor;

public class Marriage extends Action {
    private String name = "结婚";

    @Override
    public void getManConclusion(Man man) {
        System.out.println(man.name + this.name + "时，感慨到：恋爱游戏终结时，’有妻徒刑’遥无期。" );
    }

    @Override
    public void getWomanConclusion(Woman woman) {
        System.out.println(woman.name + this.name + "时，欣慰曰：爱情长跑路漫漫，婚姻保险保平安。");
    }
}
