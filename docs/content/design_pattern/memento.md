# 备忘录模式

## 设计动机

**问题引入**

如果我们玩过 RPG 游戏，就知道在关键时点需要进行存档，否则一不小心就可能给出「大侠，请重新来过」的提示，这就需要有一个存档功能。考虑最简单的实现，直接用一个队列或字典将对应时点的状态存起来就行了，当需要恢复某个历史状态时，将对应的状态取出，更新到当前状态。但是这个「保存」和「恢复」在写程序时会有一些问题，大部分的面向对象语言都不允许对私有成员进行外部访问，这有益于程序的健壮。

**模式引入**

像刚刚这种情况，当公共接口无法从外部获取一个对象的内部状态，但我们又需要访问和处理它的内部状态，此时可以使用备忘录模式。备忘录就是用来存储另一个对象在某个时间点的内部状态，当保存状态时，管理者发起一个备忘对象当前时间点的备忘到备忘录；恢复状态时，将该时间点的备忘录恢复到备忘对象。

## 模式介绍

**模式定义**

备忘录模式（Memento）是在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样以后就可以将该对象恢复到原先保存的状态。

**模式结构**

![](img/memento/memento.jpg)

备忘录模式主要包括三个对象，分别是Originator（发起人）、Memento（备忘录）和 Caretaker（管理者）
- Originator（发起人）：负责创建一个备忘录 Memento，用以记录当前时刻它的内部状态，并可使用备忘录恢复内部状态。Originator 可根据需要决定 Memento 存储 Originator 的哪些内部状态。
- Memento（备忘录）：负责存储 Originator 对象的内部状态，并可防止 Originator 以外的其他对象访问备忘录 Memento。备忘录有两个接口，Caretaker 只能看到备忘录的窄接口，它只能将备忘录传递给其他对象。Originator 能够看到一个宽接口，允许它访问返回到先前状态所需的所有数据。
- Caretaker（管理者）：负责保存好备忘录 Memento，不能对备忘录的内容进行操作或检查。

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/cpp/memento)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/java/memento)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/tree/main/src/design_patterns/python/memento)

## 使用场景

**适合场景**

- 必须保存某一时刻的状态以便需要时恢复时。
- 需要回滚、撤销等功能时。

**实际应用**

- 游戏副本存储。
- 编辑器的撤销操作。
- 数据库回滚、操作系统恢复等。

## 模式评价

**模式优点**

- 可以恢复到任意历史状态。
- 保持封装边界。

**不足之处**

- 状态数据很大时可能非常消耗资源。