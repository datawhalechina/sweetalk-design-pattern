# 设计原则

本部分介绍设计原则，书中一共提到以下几个原则：

- 单一职责原则（Single Responsibility Principle，SRP）：修改一个类的原因只有一个。
- 开闭原则（Open-Closed Principle，OCP）：对于扩展类应该开放，对于修改类应该封闭。
- 迪米特法则（Law of Demeter，LoD）：也叫最少知识原则，类应尽量降低成员的访问权限，即耦合尽可能弱。
- 依赖倒置原则（Dependency Inversion Principle，DIP）：高层次的类不应依赖低层次的类，都应依赖于抽象接口。
- 里氏替换原则（Liskov Substituion Principle，LSP）：扩展一个类时，能够（不修改代码）将子类的对象作为父类对象进行传递。和依赖倒置原则意思接近。

此外，还有下面常见的设计原则：

- 接口隔离原则（Interface Segregation Principle，ISP）：尽量缩小接口范围，让客户端不必实现不用的方法。和迪米特法则接近。
- 合成/聚合复用原则（Composite/Aggragate Reuse Principle，CARP）：尽量通过合成/聚合而不是继承达到复用目的。

## 参考

- [设计模式概念和七大原则 - 腾讯云开发者社区 - 腾讯云](https://cloud.tencent.com/developer/article/1650116)