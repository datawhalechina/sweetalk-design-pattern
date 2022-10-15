# 简单工厂模式

## 1 问题引入

### 1.1 问题描述

&emsp;&emsp;小菜参加面试，面试要求用C++、Java、python、C#任意一种面向对象语言实现一个计算器控制台程序，要求输入两个数和运算符号，得到结果。

### 1.2 问题分析

&emsp;&emsp;实现该目标的程序同时需满足
1. 面向对象。
2. 容易修改：若未来该程序要增添新的运算符号，则不需过多改动就可增加功能；如果可能，还应尽量降低修改后的重复编译量（松耦合）。
3. 降低业务逻辑和界面逻辑的耦合，易于复用（不是复制）：若未来该windows程序迁移到web版，业务部分（计算部分）不需要修改。

### 1.3 解决方案

&emsp;&emsp;此时可以考虑使用`简单工厂模式`来解决问题。
1. 首先定义一个抽象的运算类`Operation`，定义抽象类的同时定义其所有子类的公共接口，并定义一个方法`getResult(numberA,numberB)`用于得到结果；
2. 分别创造具体的加减乘除运算类，都为抽象运算类的子类，则具体运算类之中若有一者需要修改，不会影响其它的运算类。覆写具体运算类中`getResult(numberA,numberB)`方法实现运算操作；
3. 创建简单工厂类`OperationFactory`，根据输入参数，使用条件判断调用具体的运算类，实现业务逻辑和界面逻辑的分离。

### 1.4 代码实现

* C++语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/simple_factory/")
* Java语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/simple_factory/")
* python语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/simple_factory/SimpleFactory.py")
* C#语言实现见原书第二版。

## 2 模式介绍

### 2.1 定义

&emsp;&emsp;`简单工厂模式（Simple Factory Pattern）`是用一个单独的类来实现具体的实例化过程，避免客户端对具体实例化过程的显式指定。

### 2.2 结构

&emsp;&emsp;以上述问题为例，结构如下

![简单工厂模式UML](img/simple_factory/SimpleFactoryUML.png)

## 3 适用场景

&emsp;&emsp;将类类比为产品，则使用者可以在不清楚类生产的具体过程的情况下，使用不同的产品。
