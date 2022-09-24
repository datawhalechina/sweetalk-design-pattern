package design_patterns.java.proxy.example;

public class ProxyClient {
    public static void main(String[] args) {
        SchoolGirl jiaojiao = new SchoolGirl();
        jiaojiao.setName("JiaoJiao Li");

        Proxy proxy = new Proxy(jiaojiao);

        proxy.giveDolls();
        proxy.giveFlowers();
        proxy.giveChocolate();
    }
}
