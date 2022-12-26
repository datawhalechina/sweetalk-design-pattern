# 中介者模式

## 模式引入

### 问题描述

刚进公司的新人需求其他部门同事帮忙是有困难的，但是通过主管协调就会简单许多。

### **模式定义**

用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们的交互。

### 问题分析

将系统分割成许多对象通常可以增加其复用性，但是对象之间大量的连接又使得对象之间的耦合性更强，导致对系统的行为进行较大的改动就比较困难。

## 模式实现

### 解决方案

通过中介者对象，可以将系统的网状结构变成以中介者为中心的星型结构，使得对象之间的耦合度变低、扩展性增强，系统的结构不会因为新对象的引入造成大量的修改工作。

Mediator（抽象中介者类）：定义了同事对象到中介者对象的接口。

ConcreteMediator（具体中介者对象）：实现抽象类的方法，知道所有具体同事类，并从具体同事接受消息，向其他具体同事发送命令。

Colleague（抽象同事类）：用于定义抽象的同事对象，

ConcreteColleague（具体同事类）：每个具体同事只知道自己的行为，而不了解其他同事类的情况，但是他们认识终结者对象。

### 代码实现

`Mediator` 类：

```java
abstract class Mediator {
    //定义一个抽象的发送消息方法，得到同事对象和发送消息
    public abstract void send(String message,Colleague colleague);
}
```

`ConcreteMediator` 类：

```java
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
```

`Colleague` 类：

```java
public class Colleague {
    protected Mediator mediator;
    // 构建方法，得到中介者对象
    public Colleague(Mediator mediator){
        this.mediator = mediator;
    }
}
```

`ConcreteColleague` 类：

```java
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

public class ConcreteColleague2 extends Colleague {
    public ConcreteColleague2(Mediator mediator)
    {
        super(mediator);
    }
    public void send(String message)
    {
        this.mediator.send(message,this);
    }
    public void notify(String message)
    {
        System.out.println("同事2得到信息:"+message);
    }
}
```

`Main` 方法：

```java
public class main {
    public static void main(String[] args){
        ConcreteMediator m =new ConcreteMediator();
        ConcreteColleague1 c1 = new ConcreteColleague1(m);
        ConcreteColleague2 c2 = new ConcreteColleague2(m);
        m.setColleague1(c1);
        m.setColleague2(c2);
        c1.send("吃过饭了吗？");
        c2.send("没有呢，你打算请客？");
    }
}
```

执行结果：

```bash
同事2得到信息:吃过饭了吗？
同事1得到信息:没有呢，你打算请客？
```

### 结构组成

![image-20221017164911912](img/mediator/mediator.JPG)

## 模式评价

### 适合场景

中介者模式一般应用于一组对象以定义良好但是复杂的方式进行通信的场合。以及想定制一个分布在多个类中的行为，而又不想生成太多的子类的场合。

### 实际应用

nginx_http_upstream_module里定义的upstream框架就是中介者模式（同时也应用了模板模式），它协调load-balance模块和upstream模块共同工作，获取上游服务器的地址，然后转发下游的请求和上游的响应数据。

### 优点缺点

模式优点：

- 中介者减少了各个业务类的耦合，使得可以独立的改变和复用各个业务类和中介者类。
- 中介者的实现类控制了集中化，把对象群交互的复杂性变为中介者的复杂性。
- 当系统出现多对多交互复杂的对象群，可以考虑使用中介这模式。

模式缺点：

- 中介者对象会较为复杂。