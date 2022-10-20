package com.casic.test;

/**
 * Created by syj on 2022/10/20.
 */
public class Colleague {
    protected Mediator mediator;
    //构建方法，得到中介者对象
    public Colleague(Mediator mediator){
        this.mediator = mediator;
    }
}
