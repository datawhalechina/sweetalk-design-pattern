package design_patterns.java.mediator;

public class UnitedNationsSecurityCouncil extends UnitedNations {
    private USA colleague1;
    private Iraq colleague2;

    public void setColleague1(USA usa) {
        this.colleague1 = usa;
    }
    public void setColleague2(Iraq iraq) {
        this.colleague2 = iraq;
    }

    @Override
    public void declare(String message, Country colleague) {
        if(colleague instanceof USA) {
            colleague2.getMessage(message);
        }else {
            colleague1.getMessage(message);
        }
    }
}
