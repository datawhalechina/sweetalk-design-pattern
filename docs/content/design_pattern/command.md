# 命令模式

## 问题引入

### 问题描述

对于烧烤摊场景，通过服务员解耦客户与烤肉师傅之间的关系。

### 问题分析

在系统中行为请求请求者和行为实现者通常是紧耦合的，对于请求排队或记录请求日志，以及支持可撤销的操作等行为，这种紧耦合不合适。

### 解决方案

将调用操作的请求对象与实现操作的接受对象解耦，顺序为调用者->命令->接受者。

抽象命令类，用来声明执行操作的接口。

命令实现类，命令的具体实现，将接收者对象与动作绑定，从而调用接收者相应的操作完成命令。

调用者，调用命令实现某个请求。

接收者，实施与执行与请求相关的操作。

## 模式介绍

### **定义**

将请求封装为命令对象，通过数据驱动的方式将命令对象用构造函数的方式传递给调用者，调用者再根据具体的实现执行相应的命令。顺序：调用者→命令→接受者。

### **结构**

![image-20221017164911912](img/command/command.jpg)

### 实现

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/command)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/command)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/command)

## 使用场景

**适合场景**

所有能当作命令的场景下都可以使用命令模式

**实际应用**

1.Spring 框架的 JdbcTemplate 

2.JDK中的Runnable接口的运用

## 模式评价

**模式优点**

通过分离调用者和请求者降低系统的耦合度，可扩展性强。

**不足之处**

导致出现过多的命令类。

