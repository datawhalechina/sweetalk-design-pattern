package design_patterns.java.observer;

public interface Subject {
    void attach(Observer observer);
    void detach(Observer observer);
    void notity();

    String getSubjectState();
    void setSubjectState(String action);
}
