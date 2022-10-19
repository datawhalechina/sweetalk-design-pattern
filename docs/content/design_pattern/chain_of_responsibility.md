# 职责链模式

## 问题引入

### 问题描述

加薪、请假申请等需要层层审批的场景。

### 问题分析

接受请求的类如果具有太多责任会违背单一职责原则，如果因为需求修改这个类会违背开放封闭原则

### 解决方案

使得多个对象可以处理客户端发出的请求，使得请求的发送者和接收者解耦，可以让各服务模块更加清晰。处理者负责处理请求，客户只需要将请求发送到职责链，无需关心具体的处理细节。

## 模式介绍

### **定义**

职责链模式核心是解决服务中先后执行处理关系，从而降低请求发送者和接受者之间的耦合关系。类似于击鼓传花。

### **结构**

![image-20221017164911912](img/chain_of_responsibility/chain_of_responsibility.jpg)

### 实现

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/chain_of_responsibility)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/chain_of_responsibility)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/chain_of_responsibility)

## 使用场景

**适合场景**

一个请求有多个对象可以处理，但每个对象的处理条件或权限不同。

**实际应用**

1.netty中Pipeline与ChannelHandler通过责任链来组织代码逻辑。

2.tomcat中servlet过滤器使用了责任链模式。

3.spring中切面编程和安全机制都使用了责任链模式。

## 模式评价

**模式优点**

1.能够简化对象的相互连接，接收者和发送者都没有对方的明确信息，且链中的对象也不知道链的结构。

2.避免了请求的发送者和接受者之间的耦合关系。

3.能够随时修改请求的结构，增强了给对象指派职责的灵活性

**不足之处**

1.请求可能到了链的末端都得不到处理，或者因为没有正确配置得不到处理。

2.较长的责任链可能会影响到系统的性能。



