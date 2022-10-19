# 外观模式

## 1 问题引入

### 1.1 问题描述

&emsp;&emsp;股民炒股投资：股票种类有股票、国债、房产等，操作包含买和卖。

### 1.2 问题分析

1. 用户与众多股票的联系太多，不利于操作，耦合性过高；
2. 设置基金类，用户只需跟基金打交道，关心基金的涨跌即可。

### 1.3 解决方案
1. 创建基金类，涵盖所有股票的方法或属性，进行组合，方便外界调用；
2. 客户端调用，只需调用基金。

### 1.4 代码实现

* C++语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/facade/")
* Java语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/facade/")
* python语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/facade/Facade.py")
* C#语言实现见原书第二版。

## 2 模式介绍

### 2.1 定义
&emsp;&emsp;`外观模式（Facade）`，为子系统中的一组接口提供了一个一致的界面，此模式定义了一个高层接口，使得子系统更容易使用。外观模式属于结构型模式。

- 在客户端和复杂系统间加了一层，这一层将调用顺序、依赖关系等处理好；

- 隐藏了系统的复杂性，向客户端提供了一个可访问系统的接口。

### 2.2 结构

外观类，需要了解所有子系统的方法或属性，进行组合，以便外界调用。

![外观模式UML](img/facade/FacadeUML.png)

以上述问题为例，结构如下

![问题实例的UML](img/facade/FundUML.png)

## 3 适用场景

客户端不需要知道系统内部的复杂联系，整个系统只需提供一个"接待员"即可。
- 在设计初期，在层与层直接建立外观模式；
- 在开发阶段，子系统经常因为不断的重构变得更复杂。外观模式可以提供加简单的接口，方便外部调用；
- 在维护遗留的大系统时，为新系统开发一个外观模式，让新系统与Facade对象交互，Facade与遗留代码交互。

**应用实例**
- 医院看病，挂号、门诊、划价、取药，让患者觉得很复杂。设有接待人员，就很方便；
- 三层开发模式。

## 4 评价
### 4.1 优点
- 减少系统相互依赖
- 提高了灵活性
- 提高了安全性

### 4.2 缺点
&emsp;&emsp;不符合开闭原则，如果要改东西很麻烦，继承重写都不合适。

## 5 参考资料
&emsp;&emsp;[外观模式 - 菜鸟教程](https://www.runoob.com/design-pattern/facade-pattern.htmll)