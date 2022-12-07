# 桥接模式

## 模式引入

### 问题描述

对于不同品牌的手机，软件基本无法兼容。因此如果手机需要增加软件，就需要针对不同品牌的手机分别实现软件功能。

### 模式定义

桥接模式是将抽象部分与其实现部分分离，使它们都可以独立地变化。

### 问题分析

实现该问题的程序通常会采用继承方式设计，那么父类和子类之间会具有非常紧密的依赖关系，父类中的任何变化都会影响子类，子类继承的实现如果无法解决新需求就必须重写或替换父类。如此设计会导致类爆炸问题，并且扩展不灵活。

## 模式实现

### 解决方案

核心思想使用合成/聚合原则代替类继承思想设计程序，从而降低耦合度、减少代码量。

首先确定分类的角度，然后把这些实现独立出来，让它们互不干扰相互独立，从而减少耦合。需要注意的是能否找到合适的桥接点，如果没有就不必要非要使用桥接模式。

包括以下四个角色：

- Abstraction（抽象类）：用于定义抽象类的接口，其中定义了一个具有关联关系的Implementor 的对象。
- RefinedAbstraction（扩充抽象类）：继承并实现抽象类中的接口，并在其中调用Implementor 对象的相关业务方法。
- Implementor（实现类）：用于定义实现类的接口，提供基本的业务方法供抽象类调用，以完成复杂的操作。
- ConcreteImplementor（具体实现类）：继承并实现 Implementor 的接口，在不同的具体实现类中提供不同的操作方法，通过向上转型的方式完成方法的调用。

### 代码实现

`HandsetSoft` 实现类：

```java
public abstract class HandsetSoft {
    public abstract void run();
}
```

`HandsetSoft` 具体实现类：

```java
public class HandsetGame extends HandsetSoft {
    @Override
    public void run() {
        System.out.println("运行手机游戏");
    }
}

public class HandsetAddressList extends HandsetSoft {
    @Override
    public void run() {
        System.out.println("运行手机通讯录");
    }
}
```

`HandsetBrand` 抽象类：

```java
public abstract class HandsetBrand {
    protected HandsetSoft soft;

    public void SetHandsetSoft(HandsetSoft soft) {
        this.soft = soft;
    }

    public abstract void run();
}
```

`HandsetBrand` 扩展抽象类：

```java
public class HandsetBrandM extends HandsetBrand {
    @Override
    public void run() {
        soft.run();
    }
}

public class HandsetBrandN extends HandsetBrand {
    @Override
    public void run() {
        soft.run();
    }
}
```

`Main` 方法：

```java
public class Main {
    public static void main(String[] args) {
        HandsetBrand ab;
        ab = new HandsetBrandN();

        ab.SetHandsetSoft(new HandsetGame());
        ab.run();

        ab.SetHandsetSoft(new HandsetAddressList());
        ab.run();

        ab = new HandsetBrandM();

        ab.SetHandsetSoft(new HandsetGame());
        ab.run();

        ab.SetHandsetSoft(new HandsetAddressList());
        ab.run();
    }
}
```

执行结果：

```bash
运行手机游戏
运行手机通讯录
运行手机游戏
运行手机通讯录
```

### 结构组成

![image-20221017164911912](img/bridge/bridge.JPG)

## 模式评价

### 适合场景

- 对于使用较多类继承问题而导致紧耦合、扩展性差的系统。
- 对于存在多个独立变化并需要灵活扩展维度的需求。

### 实际应用

- JDBC 规范和不同数据库厂商驱动的实现。
- Spring 中可以根据客户的需求能够动态切换不同的数据源。
- Nginx 的模块架构就应用了桥接模式，使用了`nginx_module_t` 定义模块，结构体里有若干函数指针和扩展字段，然后桥接实现了丰富多彩的 core、conf、event、stream、http 等功能模块，搭建起整个 Nginx 框架。

### 优点缺点

模式优点：

- 避免了继承导致的类爆炸问题。
- 具备灵活的可扩展性。

模式缺点：

- 将抽象和实现分离会增加设计的难度。

