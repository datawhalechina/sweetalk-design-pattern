package design_patterns.java.iterator;

public class Main {
    public static void main(String[] args) {
        ConcreteAggregate a = new ConcreteAggregate();
        a.set(0, "大鸟");
        a.set(1,"小菜");
        a.set(2,"行李");
        a.set(3,"老外");
        a.set(4,"公交内部员工");
        a.set(5,"小偷");

        Iterator i = new ConcreteIterator(a);

        while (!i.isDone()){
            System.out.println(i.currentItem() + " 请买车票");
            i.next();
        }
    }
}
