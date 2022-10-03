package design_patterns.java.command;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Waiter {
    private List<Command> orders = new ArrayList<>();

    public void setOrder(Command command) {
        if (command.getClass().toString().equals("class design_patterns.java.command.BakeChickenWingCommand")) {
            System.out.println("服务员：鸡翅没有了，请点别的烧烤。");
        }else {
            orders.add(command);
            System.out.print("增加订单：" + command.getClass().toString());
            System.out.println(" 时间：" + new Date());
        }
    }

    public void cancelOrder(Command command) {
        orders.remove(command);
        System.out.print("取消订单：" + command.getClass().toString());
        System.out.println(" 时间：" + new Date());
    }

    public void excute() {
        for(Command cmd : orders){
            cmd.excuteCommand();
        }
    }
}
