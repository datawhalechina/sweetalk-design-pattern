# 中介者模式

## 问题引入

### 问题描述

刚进公司的新人需求其他部门同事帮忙是有困难的，但是通过主管协调就会简单许多。

### 问题分析

将系统分割成许多对象通常可以增加其复用性，但是对象之间大量的连接又使得对象之间的耦合性更强，导致对系统的行为进行较大的改动就比较困难。

### 解决方案

通过中介者对象，可以将系统的网状结构变成以中介者为中心的星型结构，使得对象之间的耦合度变低、扩展性增强，系统的结构不会因为新对象的引入造成大量的修改工作。

## 模式介绍

### **定义**

用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们的交互。

### **结构**

![image-20221017164911912](img/mediator/mediator.JPG)

### 实现

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/mediator)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/mediator)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/mediator)

## 使用场景

**适合场景**

中介者模式一般应用于一组对象以定义良好但是复杂的方式进行通信的场合。以及想定制一个分布在多个类中的行为，而又不想生成太多的子类的场合。

**实际应用**

nginx_http_upstream_module里定义的upstream框架就是中介者模式（同时也应用了模板模式），它协调load-balance模块和upstream模块共同工作，获取上游服务器的地址，然后转发下游的请求和上游的响应数据。

## 模式评价

**模式优点**

中介者减少了各个业务类的耦合，使得可以独立的改变和复用各个业务类和中介者类。

中介者的实现类控制了集中化，把对象群交互的复杂性变为中介者的复杂性。

当系统出现多对多交互复杂的对象群，可以考虑使用中介这模式。

**不足之处**

中介者对象会较为复杂