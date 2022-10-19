package design_patterns.java.bridge;

public class Main {
    public static void main(String[] args) {
        HandsetBrand ab;
        ab = new HandsetBrandN();

        ab.SetHandsetSoft(new HandsetGame());
        ab.run();

        ab.SetHandsetSoft(new HandsetAddressList());
        ab.run();

        ab = new HandsetBrandM();

        ab.SetHandsetSoft(new HandsetGame());
        ab.run();

        ab.SetHandsetSoft(new HandsetAddressList());
        ab.run();
    }
}
