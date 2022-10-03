package design_patterns.java.observer;

public class NBAObserver extends Observer {
    public NBAObserver(String name, Subject sub) {
        super(name, sub);
    }

    @Override
    public void update() {
        System.out.println(sub.getSubjectState() + " " + name + " 关闭NBA直播，继续工作！");
    }
}
