package design_patterns.java.observer;

public class Main {
    public static void main(String[] args) {
        Boss huhansan = new Boss();

        Observer tongshi1 = new StockObserver("魏关姹", huhansan);
        Observer tongshi2 = new NBAObserver("易管查", huhansan);

        huhansan.attach(tongshi1);
        huhansan.attach(tongshi2);

        huhansan.detach(tongshi1);
        huhansan.setSubjectState("我胡汉三回来了！");
        huhansan.inform();
    }
}
