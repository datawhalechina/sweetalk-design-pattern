package design_patterns.java.state;

public class Main {
    public static void main(String[] args) {
        Work emergencyProjects = new Work();
        emergencyProjects.setHour(9);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(10);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(12);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(13);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(14);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(17);
        emergencyProjects.writeProgram();

        emergencyProjects.setFinish(false);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(19);
        emergencyProjects.writeProgram();

        emergencyProjects.setHour(22);
        emergencyProjects.writeProgram();
    }
}
