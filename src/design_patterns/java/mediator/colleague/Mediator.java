package com.casic.test;

/**
 * Created by syj on 2022/10/20.
 */
abstract class Mediator {
    //定义一个抽象的发送消息方法，得到同事对象和发送消息
    public abstract void send(String message,Colleague colleague);
}
