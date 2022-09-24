package design_patterns.java.prototype;

public class PrototypeClient {
    public static void main(String[] args){
        ConcreatePrototype1 p1 = new ConcreatePrototype1("I");
        ConcreatePrototype1 c1 = (ConcreatePrototype1) p1.Clone();
        System.out.println("Cloned: " + c1.getId());
    }
}
