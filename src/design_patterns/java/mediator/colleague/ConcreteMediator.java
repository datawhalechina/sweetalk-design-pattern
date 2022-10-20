package com.casic.test;

/**
 * Created by syj on 2022/10/20.
 */
public class ConcreteMediator extends Mediator{
    public ConcreteColleague1 concreteColleague1;
    public ConcreteColleague2 concreteColleague2;

    public void setColleague1(ConcreteColleague1 value){
        this.concreteColleague1 = value;
    }
    public void setColleague2(ConcreteColleague2 value){
        this.concreteColleague2 = value;
    }
    @Override
    public void send(String message, Colleague colleague) {
        if(colleague == concreteColleague1){
            concreteColleague2.notify(message);
        }else{
            concreteColleague1.notify(message);
        }
    }
}
