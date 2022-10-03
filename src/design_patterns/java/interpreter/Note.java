package design_patterns.java.interpreter;

public class Note extends Expression {
  @Override
    public void excute(String key, double value) {
      String note = "";
      switch (key){
          case "C":
              note = "1";
              break;
          case "D":
              note = "2";
              break;
          case "E":
              note = "3";
              break;
          case "F":
              note = "4";
              break;
          case "G":
              note = "5";
              break;
          case "A":
              note = "6";
              break;
          case "B":
              note = "7";
              break;
      }
      System.out.print(note + " ");
    }
}
