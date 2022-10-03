package design_patterns.java.chain_of_responsibility;

public class Main {
    public static void main(String[] args) {
        CommonManager jinli = new CommonManager("金利");
        MajorDemo zongjian = new MajorDemo("宗剑");
        GeneralManager zhongjingli = new GeneralManager("钟精励");
        jinli.SetSuperior(zongjian);
        zongjian.SetSuperior(zhongjingli);

        Request request = new Request();
        request.setRequestType("请假");
        request.setRequestContent("小菜请假");
        request.setNumber(1);
        jinli.requestApplications(request);

        Request request2 = new Request();
        request2.setRequestType("请假");
        request2.setRequestContent("小菜请假");
        request2.setNumber(4);
        jinli.requestApplications(request2);

        Request request3 = new Request();
        request3.setRequestType("加薪");
        request3.setRequestContent("小菜请求加薪");
        request3.setNumber(500);
        jinli.requestApplications(request3);

        Request request4 = new Request();
        request4.setRequestType("加薪");
        request4.setRequestContent("小菜请求加薪");
        request4.setNumber(1000);
        jinli.requestApplications(request4);
    }
}
