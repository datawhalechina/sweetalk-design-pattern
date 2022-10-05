# 装饰模式

## 1 概念

&emsp;&emsp;装饰模式（Decorator Pattern）是指创建一个装饰类，来包装原有的类，从而实现向一个现有的对象添加一些额外的职责，同时不改变其原有的结构。

## 2 知识点

### 2.1 适用场景

&emsp;&emsp;可以在不生成很多子类的情况下扩展类，适用于扩展类需求较多，而又不想引起子类膨胀的场景。

### 2.2 使用步骤

1. 创建抽象的接口类（Component），定义给对象动态添加职责的公共接口；
2. 创建具体的接口（Concrete Component），扩展Component的具体功能，继承于抽象接口类；
3. 创建抽象的装饰类（Decorator），扩展Component类的功能，继承于抽象接口类；
4. 创建具体的装饰类（Concrete Decorator），实现具体的装饰对象，给Component增添职责，继承于抽象的装饰类.

在客户端中使用时：

1. 实例化待装饰对象：接口Component或Concrete Component；
2. 实例化装饰类Concrete Decorator，传入待装饰对象（即接口Component或Concrete Component），进行装饰。