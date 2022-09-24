package design_patterns.java.prototype;

public class ConcreatePrototype1 extends Prototype implements Cloneable {
    public ConcreatePrototype1(String id) {
        super(id);
    }

    @Override
    public Prototype Clone() {
        try{
            return (Prototype)clone();
        }catch (CloneNotSupportedException ex){
            ex.printStackTrace();
        }
        return null;
    }
}
