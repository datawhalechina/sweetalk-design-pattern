package design_patterns.java.decorator.example;

public class DecoratorClient {
    public static void main(String[] args) {
        Person person = new Person("小菜");
        System.out.println("第一种装扮:");

        Sneakers sneaker = new Sneakers();
        BigTrouser trouser = new BigTrouser();
        TShirts tshirt = new TShirts();
        
        sneaker.decorate(person);
        trouser.decorate(sneaker);
        tshirt.decorate(trouser);
        tshirt.show();
    }
}