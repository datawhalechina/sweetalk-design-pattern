package design_patterns.java.prototype.example;

public class ResumeClient {
    public static void main(String[] args) {
        Resume a = new Resume("Big bird");
        a.setPersonalInfo("Female", "29");
        a.SetWorkExperience("1998-2000", "Datawhale");
        a.display();
    } 
}
