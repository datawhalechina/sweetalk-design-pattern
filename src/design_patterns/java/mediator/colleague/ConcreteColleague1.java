package com.casic.test;

/**
 * Created by syj on 2022/10/20.
 */
public class ConcreteColleague1 extends Colleague {
    public ConcreteColleague1(Mediator mediator) {
        super(mediator);
    }
    public void send(String message){
        this.mediator.send(message,this);
    }
    public void notify(String message){
        System.out.println("同事1得到信息:"+message);
    }
}
