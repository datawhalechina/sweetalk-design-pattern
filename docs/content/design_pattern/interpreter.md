# 解释器模式

## 问题引入

### 问题描述

音乐解释器程序，根据自定义规则将音乐解释成简谱。

### 问题分析

一种特定类型的问题发生的频率足够高，就值得将该问题的各个实例表述为一个简单语言中的句子。就可以考虑构建解释器解释这些句子。

### 解决方案

采用解释器模式，通过构建语法树，定义终结符与非终结符。

其中抽象表达式用于声明一个抽象的解释操作。终结符表达式实现与文法的终结符相关联的解释操作。非终结符表达式，为文法中的非终结符实现解释操作。上下文包含解释器之外的全局信息。

## 模式介绍

### **定义**

解释器模式，给定一个语言，定义它的文法的一种表示，并定义一个解释器，解释器使用该表示来解释语言中的句子。

### **结构**

![image-20221017164911912](img/interpreter/interpreter.jpg)

### 实现

**代码实现**

- C++ 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/cpp/interpreter)
- Java 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/java/interpreter)
- Python 实现：[链接](https://github.com/datawhalechina/sweetalk-design-pattern/src/design_patterns/python/interpreter)

## 使用场景

**适合场景**

重复出现的操作可以考虑使用简单的语言进行表达。

**实际应用**

Spring 框架中 SpelExpressionParser 就使用解释器模式

## 模式评价

**模式优点**

解释器模式可以容易地改变和扩展文法。

**不足之处**

解释器模式为文法中的每条规则至少定义了一个类，导致包含许多规则的文法可能难以管理和维护。