# 代理模式

##  问题引入

### 问题描述

隔壁班的卓贾易想追求娇娇，但是他自己不好意思，就委托和娇娇同班的戴励帮助他。卓贾易给娇娇先后买了芭比娃娃、花、巧克力，饼委托戴励送给娇娇，却没想给娇娇和戴励创造了相处的机会。娇娇和戴励通过接触互生情愫，最后在一起了。卓贾易自然是很生气，一番追求却为他人做了嫁衣。但细细想来，虽说一直是卓贾易给娇娇买的礼物，但娇娇自始至终都是从戴励手里拿到的礼物，她并未接触过送礼之人——卓贾易。

现在我们想用程序来描述这一个故事，关键之处在于准确描述卓贾易、戴励及娇娇三者之间的行动关系。如果我们只描述了追求者卓贾易，和被追求者娇娇，则与实际情况不符，因为娇娇并不认识卓贾易；而若我们只描述了代理戴励，和被追求者娇娇，亦与实际情况不符，因为礼物是卓贾易买的，戴励并没有礼物直接送给娇娇。为了准确描述他们三人的关系，我们可以考虑使用`代理模式`。

### 模式定义

`代理模式（Proxy Pattern）`是指实现一个类代表另一个类的功能，为其他对象提供一种代理以控制对这个对象的访问。

### 问题分析

`代理模式（Proxy Pattern）`可以应用到这一问题中。

这一问题中有三个类型的角色，追求者（卓贾易），代理（戴励）和被追求者（娇娇）。他们三者间的关系满足，追求者（卓贾易）委托代理（戴励），通过代理（戴励）给被追求者（娇娇）送礼物，而被追求者（娇娇）只与代理（戴励）有接触。

若使用代理模式描述，即代理（戴励）代表了追求者（卓贾易）的追求（赠送礼物）的功能，被追求者（娇娇）仅与代理（戴励）接触便收到了礼物。这样就实现了他们三人关系的准确描述。

## 模式实现

### 解决方案

使用`代理模式`来解决这一问题。
1. 创建送礼物的抽象类`IGiveGift`，定义追求者和代理的共用接口：    
    * 送玩具方法`GiveDolls()`;
    * 送花方法`GiveFlowers()`;
    * 送巧克力方法`GiveChocolate()`。
2. 创建追求者`Pursuit`，定义需要代理的真正实体，继承于抽象类`IGiveGift`:    
    * 覆写类初始化方法，记录被追求者姓名；
    * 覆写送玩具、送花、送巧克力方法，具体送礼操作。
3. 创建代理`Proxy`，保存追求者实体的一个引用，使得代理可以访问实体，继承于抽象类`IGiveGift`，实现对实体的替代：    
    * 覆写类初始化方法，初始化的同时初始化一个追求者`Pursuit`对象；
    * 覆写送玩具、送花、送巧克力方法，在每一个送礼方法下调用追求者`Pursuit`的具体送礼操作

### 代码实现

*此处我们使用Java语言来实现这一方案，C#语言实现可见原书原版，本项目的所有语言实现可见本项目Github仓库，其中包括：[C++](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/cpp/proxy/)，[Java](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/java/proxy/example)，[python](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/python/proxy/Proxy.py)，读者可按需参阅。*

首先定义一个被追求者类，是为了使故事可以完整描述，无需实现特别的功能。

```Java
public class SchoolGirl {
    private String name;

    public SchoolGirl() {}

    public SchoolGirl(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

定义送礼物的抽象类`IGiveGift`。

```java
public interface GiveGift {
    public void giveDolls();
    public void giveFlowers();
    public void giveChocolate();
}
```

追求者类增加了实现送礼物的接口的改动。

```Java
public class Pursuit implements GiveGift{
    SchoolGirl mm ;

    public Pursuit(SchoolGirl mm) {
        this.mm = mm;
    }

    public void giveDolls() {
        System.out.println(mm.getName() + " give you a doll");
    }

    public void giveFlowers() {
        System.out.println(mm.getName() + " give you a Flower");
    }

    public void giveChocolate() {
        System.out.println(mm.getName() + " give you a chocolate");
    }
}
```

代理类，是唯一即认识追求者，又认识被追求者的类。初始化时与追求者及被追求者建立关联，实现送礼物方法时调用追求者的同名方法。

```Java
public class Proxy implements GiveGift {
    Pursuit gg;

    public Proxy(SchoolGirl mm) {
        this.gg = new Pursuit(mm);
    }

    public void giveDolls() {
        gg.giveDolls();
    }

    public void giveFlowers() {
        gg.giveFlowers();
    }

    public void giveChocolate() {
        gg.giveChocolate();
    }
}
```

客户端如下。

```java
public class ProxyClient {
    public static void main(String[] args) {
        SchoolGirl jiaojiao = new SchoolGirl();
        jiaojiao.setName("JiaoJiao Li");

        Proxy proxy = new Proxy(jiaojiao);

        proxy.giveDolls();
        proxy.giveFlowers();
        proxy.giveChocolate();
    }
}
```

运行结果如下。
```
JiaoJiao Li give you a doll
JiaoJiao Li give you a Flower
JiaoJiao Li give you a chocolate
```

### 结构组成

代理模式由三个主要角色组成：
 1. 访问接口：在这个例子中具体为送礼物的行为；
 2. 实体类：在这个例子中具体为追求者；
 3. 替代实体的代理类：在这个例子中具体为代理。

结构图如下：

![案例UML](img/proxy/exampleUML.png)

代理模式的通用结构示意图如下

![代理模式UML](img/proxy/proxyUML.png)

## 模式评价

### 适用场景

不方便直接访问对象时，为不宜直接访问的对象提供一个访问层。    

使用代理模式的方式分为以下几种：    
* 本地执行远程服务（远程代理）：适用于服务对象位于远程服务器上的情形，可以为一个对象在不同的地址空间提供局部代表。
* 延迟初始化（虚拟代理）：如果你有一个偶尔使用的重量级服务对象，一直保持该对象运行会消耗系统资源时，可使用代理模式。
* 访问控制（保护代理/安全代理）：如果只希望特定客户端使用服务对象，对象可以是操作系统中的重要部分，而客户端则是各种已启动程序，可使用代理模式。
* 记录日志请求（日志记录代理）：适用于需要保存对于服务对象的请求历史记录时。
* 缓存请求结果（缓存代理）：适用于需要缓存客户请求结果并对缓存生命周期进行管理时，特别是返回结果体积非常大时。
* 智能指引：调用真实对象时，代理处理另外一些事，可在没有客户端使用某个重量级对象时，立刻销毁该对象。

### 实际应用

* 信用卡是银行账户的代理，而银行账户则是一大捆现金的代理。它们都可以实现相同的支付功能。
* windows里的快捷方式。
* 客户端对数据库的查询有时要消耗大量系统资源，常在有需要时才创建（延迟初始化），这会带来代码的大量重复。可以创建代理，让代理伪装成数据库对象，在客户端或实际数据库对象不知情的情况下处理延迟初始化和缓存查询结果的工作。

### 优点缺点

模式优点包括：

* 引入代理后，职责清晰；
* 引入代理后，可扩展多种用途，如：    
    * 远程代理可以隐藏一个对象存在于不同地址空间的事实。
    * 虚拟代理可以存放实例化时间很长的真实对象。
* 符合“开放封闭原则”，无需对服务器或客户端进行修改就创建新的代理。

模式缺点包括：

* 代码可能变得复杂，因为需要新建许多类；
* 服务响应可能会延迟。


## 参考资料
1. 《深入设计模式》
