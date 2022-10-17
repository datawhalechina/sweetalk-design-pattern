# 迭代器模式

## 设计动机

**问题引入**

实际生活中，我们经常遇到需要遍历一系列聚合对象的情况，比如排队买票，音乐播放列表等。当我们遍历这些对象时，由于它们本来是一个对象，导致我们不得不直接访问其内部列表。而且，如果我们要遍历另一个的对象时，同样的遍历方法又得重写一遍。

**模式引入**

像这种想要别人访问它的元素，但又不想暴露内部结构的情况，就可以使用迭代器模式，将对列表的访问和遍历放到一个迭代器对象，迭代器定义了访问元素的接口。此时，同样的遍历逻辑只需要实现一次。事实上，由于迭代器模式使用太普遍，大部分高级语言都已经对它进行了封装。

## 模式介绍

**模式定义**

迭代器模式（Iterator）是提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。

**模式结构**

![](img/iterator/iterator.jpg)

迭代器模式主要包括聚集抽象类（Aggregate）、迭代抽象类（Iterator）、具体聚集类（ConcreteAggregate）、具体迭代器类（ConcreteIterator）。

- 迭代抽象类（Iterator）：用于定义各种行为的抽象方法，统一接口
- 具体迭代器类（ConcreteIterator）：继承 Iterator，实现具体行为的方法

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/cpp/iterator)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/java/iterator)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/python/iterator)

## 使用场景

**适合场景**

- 当需要遍历访问一个聚合对象，而且不管这些对象是什么。
- 内部结构复杂，只提供精简的访问方式。
- 对聚合对象支持多种方式遍历。

**实际应用**

- 列表、队列等容器。
- 字符串序列。

## 模式评价

**模式优点**

- 减少重复遍历代码。
- 存储与遍历分离。
- 简化数据访问方式。

**不足之处**

- 过于简单的集合会增加复杂性。
- 增加新的聚合类时可能需要新的迭代器。