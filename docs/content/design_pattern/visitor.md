# 访问者模式

## 问题引入

### 问题描述

关于男人和女人的区别讨论。

### 问题分析

需要对类的不同对象执行不同操作，但是又不希望增加操作的时候改变这些类。

### 解决方案

访问者模式可以把处理从数据结构中分离出来，从而降低数据结构和作用于结构上的操作之间的耦合，使得操作集合可以相对自由变化。

## 模式介绍

### **定义**

访问者模式：表示一个作用于某对象结构中的各元素操作。可以再不改变元素的类的前提下定义于这些元素的新操作。

### **结构**

![image-20221017164911912](img/visitor/visitor.JPG)

### 实现

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/visitor)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/visitor)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/visitor)

## 使用场景

**适合场景**

系统中对象对应的类很少改变，但是经常会定义新的操作。

**实际应用**

1.Spring在beans配置中实现了访问者设计模式

2.JSP的解析器,Jasper框架利用的访问模式来解析HTML和XML格式

3.ShardingSphere在SQL解析中使用了大量的访问者模式

## 模式评价

**模式优点**

增加新的操作很容易。访问者模式将有关的行为集中到一个访问者对象中。

**不足之处**

增加新的数据结构变得困难。