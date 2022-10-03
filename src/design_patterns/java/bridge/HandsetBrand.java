package design_patterns.java.bridge;

public abstract class HandsetBrand {
    protected HandsetSoft soft;

    public void SetHandsetSoft(HandsetSoft soft) {
        this.soft = soft;
    }

    public abstract void run();
}
