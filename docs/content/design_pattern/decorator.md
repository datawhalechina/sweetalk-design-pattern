# 装饰模式

## 1 问题引入

### 1.1 问题描述

&emsp;&emsp;小菜要去约会，和大鸟聊到穿衣问题。大鸟由穿衣问题引申，要求用C++、Java、python、C#任意一种面向对象语言实现一个可以给人搭配嘻哈服或白领装的系统。控制台输出效果如下：

<img src = img/decorator/example.png width = 70%>

&emsp;&emsp;进一步地，对系统实现超人装扮的添加。控制台输出效果如下：

<img src = img/decorator/example2.png width = 70%>

### 1.2 问题分析

&emsp;&emsp;实现该目标的程序同时需满足
1. 面向对象。
2. 装扮过程应该在内部实现（因为衣服不能在众目睽睽之下穿），服饰的装扮先后顺序及装扮组合有多种，**需要把所需的功能按正确顺序串联起来进行控制**。

### 1.3 解决方案

&emsp;&emsp;此时可以考虑使用`装饰模式`来解决问题。
1. 创建抽象的接口类`Component`，定义给对象动态添加职责的公共接口（在此例中，由于具体的接口只有一个，所以该步也可省略）；
2. 创建具体的接口`Person`(Concrete Component)，继承于抽象接口类`Component`，定义方法`Show()`用于显示装扮结果；
3. 创建抽象的装饰类`Finery`（Decorator），继承于接口类`Person`（一般来说继承于抽象接口类`Component`，由于此例只有一个接口，故继承于具体接口类），定义方法`Decorate(component)`用于进行装扮过程，覆写`Show()`具体装扮结果的显示；
4. 创建系列具体的服饰类（Concrete Decorator），如`Tshirts`，`BigTrouser`等，继承于抽象装饰类`Finery`，实现具体的装饰对象，覆写`Show()`具体装扮结果的显示。

### 1.4 代码实现

* C++语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/decorator/")
* Java语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/decorator/")
* python语言实现：[链接]("https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/decorator/DecoratorFinery.py")
* C#语言实现见原书第二版。

## 2 模式介绍

### 2.1 定义

&emsp;&emsp;装饰模式（Decorator Pattern）是指创建一个装饰类，来包装原有的类，从而实现向一个现有的对象添加一些额外的职责，同时不改变其原有的结构。

### 2.2 结构

&emsp;&emsp;结构示意图如下

![装饰模式UML](img/decorator/DecoratorUML.png)

&emsp;&emsp;以上述问题为例，结构如下

![案例UML](img/decorator/FineryUML.png)

## 3 适用场景

&emsp;&emsp;可以在不生成很多子类的情况下扩展类，适用于扩展类需求较多，而又不想引起子类膨胀的场景。

&emsp;&emsp;例如：
* 通知信息有多种渠道，如通过短信、微信、QQ、邮件等。不同的信息会采用不同的多种渠道组合进行通知，此时若对每一个组合都建立子类，会造成子类数量爆炸，可以考虑装饰器模式。

## 4 评价

### 4.1 优点

* 把类中的装饰功能从类中搬移去除，很好地简化了原有的类；
* 有效地把类的核心职责和装饰功能区分开了，可以去除相关类中重复的装饰逻辑；
* 装饰类和被装饰类可以独立发展，不会相互耦合；
* 无需创建新子类即可实现对类功能的动态扩展；
* 支持运行时添加或删除对象的功能；
* 满足“单一职责原则”，可将实现许多不同行为的类拆分为多个较小的类。

### 4.2 缺点

* 在封装器栈中删除特定封装器比较困难；
* 较难实现行为不受到先后顺序影响的装饰；
* 各装饰层的代码相对冗余。

# 参考资料
1. 《深入设计模式》