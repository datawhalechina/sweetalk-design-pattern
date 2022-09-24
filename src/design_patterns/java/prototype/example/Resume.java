package design_patterns.java.prototype.example;

public class Resume implements Cloneable {
    private String name;
    private String sex;
    private String age;
    private WorkExperience work;

    public Resume(String name) {
        this.name = name;
        this.work = new WorkExperience();
    }

    private Resume(WorkExperience work) {
        this.work = (WorkExperience)work.Clone();
    }

    public void setPersonalInfo(String sex, String age) {
        this.sex = sex;
        this.age = age;
    }

    public void SetWorkExperience(String workDate, String company) {
        work.setWorkDate(workDate);
        work.setWorkCompany(company);
    }

    public void display() {
        System.out.println(this.getName() + " " + this.getSex() + " " + this.getAge());
        System.out.println("Work experience: " + work.getWorkDate() + " " + work.getWorkCompany());
    }

    public Object Clone() {
        Resume obj = new Resume(this.work);
        obj.name = this.name;
        obj.sex = this.sex;
        obj.age = this.age;
        return obj;
    }

    public String getName() {
        return this.name;
    }
    public String getSex() {
        return this.sex;
    }
    public String getAge() {
        return this.age;
    }
}
