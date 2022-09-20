# 迭代器模式

## 1 概念

&emsp;&emsp;迭代器模式（Iterator）是提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。

## 2 知识点

### 2.1 使用场景

&emsp;&emsp;当需要访问一个聚集对象，而且不管这些对象是什么，需要遍历的时候，应该考虑用迭代器模式

### 2.1 迭代器模式的类组成

&emsp;&emsp;迭代器模式主要包括聚集抽象类（Aggregate）、迭代抽象类（Iterator）、具体聚集类（ConcreteAggregate）、具体迭代器类（ConcreteIterator）
- 迭代抽象类（Iterator）：用于定义各种行为的抽象方法，统一接口
- 具体迭代器类（ConcreteIterator）：继承 Iterator，实现具体行为的方法