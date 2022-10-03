package design_patterns.java.observer;

import java.util.ArrayList;
import java.util.List;

public class Boss implements Subject {
    private List<Observer> observers = new ArrayList<>();
    private String action;

    @Override
    public void attach(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void detach(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void inform() {
        for(Observer o : observers){
            o.update();
        }
    }

    @Override
    public String getSubjectState() {
        return action;
    }

    @Override
    public void setSubjectState(String action) {
        this.action = action;
    }
}
