package design_patterns.java.template_method;

public class TestPaperB extends TestPaper {
    @Override
    protected String answer1() {
        return "c";
    }

    @Override
    protected String answer2() {
        return "a";
    }

    @Override
    protected String answer3() {
        return "a";
    }
}
