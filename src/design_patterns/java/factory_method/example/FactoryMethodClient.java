package design_patterns.java.factory_method.example;

public class FactoryMethodClient {
    public static void main(String[] args) {
        IFactory factory = new UndergraduateFactory();
        LeiFeng student = factory.createLeiFeng();
        student.buyRice();
        student.sweep();
        student.wash();

        LeiFeng volunteer = new VolunteerFactory().createLeiFeng();
        volunteer.buyRice();
        volunteer.sweep();
        volunteer.wash();
      }
}
