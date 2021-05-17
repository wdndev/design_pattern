# 软件设计模式

## 一、软件涉及模式的概念与意义

### 1、软件设计模式的概念

软件设计模式（Software Design Pattern），又称设计模式，是一套被反复使用、多数人知晓的、经过分类编目的、代码设计经验的总结。它描述了在软件设计过程中的一些不断重复发生的问题，以及该问题的解决方案。其目的是为了提高代码的可重用性、代码的可读性和代码的可靠性。

### 2、学习软件设计模式的意义

设计模式的本质是面向对象设计原则的实际运用，是对类的封装性、继承性和多态性以及类的关联关系和组合关系的充分理解。正确使用设计模式具有以下优点。

- 可以提高程序员的思维能力、编程能力和设计能力。
- 使程序设计更加标准化、代码编制更加工程化，使软件开发效率大大提高，从而缩短软件的开发周期。
- 使设计的代码可重用性高、可读性强、可靠性高、灵活性好、可维护性强。

当然，软件设计模式只是一个引导。在具体的软件幵发中，必须根据设计的应用系统的特点和要求来恰当选择。对于简单的程序开发，可能写一个简单的算法要比引入某种设计模式更加容易。但对大项目的开发或者框架设计，用设计模式来组织代码显然更好。

## 二、软件设计模式的基本要素

软件设计模式使人们可以更加简单方便地复用成功的设计和体系结构，它通常包含以下几个基本要素：模式名称、别名、动机、问题、解决方案、效果、结构、模式角色、合作关系、实现方法、适用性、已知应用、例程、模式扩展和相关模式等，其中最关键的元素包括以下 4 个主要部分。

### 1.模式名称

每一个模式都有自己的名字，通常用一两个词来描述，可以根据模式的问题、特点、解决方案、功能和效果来命名。模式名称（PatternName）有助于我们理解和记忆该模式，也方便我们来讨论自己的设计。

### 2.问题

问题（Problem）描述了该模式的应用环境，即何时使用该模式。它解释了设计问题和问题存在的前因后果，以及必须满足的一系列先决条件。

### 3.解决方案

模式问题的解决方案（Solution）包括设计的组成成分、它们之间的相互关系及各自的职责和协作方式。因为模式就像一个模板，可应用于多种不同场合，所以解决方案并不描述一个特定而具体的设计或实现，而是提供设计问题的抽象描述和怎样用一个具有一般意义的元素组合（类或对象的 组合）来解决这个问题。

## 4.效果

描述了模式的应用效果以及使用该模式应该权衡的问题，即模式的优缺点。主要是对时间和空间的衡量，以及该模式对系统的灵活性、扩充性、可移植性的影响，也考虑其实现问题。显式地列出这些效果（Consequence）对理解和评价这些模式有很大的帮助。

## 三、面向对象设计原则

| 编号 | 类型  | 原则 | 简称 |
| :--: | :--: | :--: | :--: |
|  1   | 设计原则 |    [开闭原则](design_principle/OCP.md)     | `OCP` |
|  2   | 设计原则 |  [里氏替换原则](design_principle/LSP.md)   | `LSP` |
|  3   | 设计原则 |  [依赖倒置原则](design_principle/DIP.md)   | `DIP` |
|  4   | 设计原则 |    [单一原则](design_principle/SRP.md)     | `SRP` |
|  5   | 设计原则 |  [接口隔离原则](design_principle/ISP.md)   | `ISP` |
|  6   | 设计原则 |   [迪米特原则](design_principle/LOD.md)    | `LOD` |
|  7   | 设计原则 | [合成复用原则原则](design_principle/CRP.md) | `CRP` |

这 7 种设计原则是软件设计模式必须尽量遵循的原则，各种原则要求的侧重点不同。

- 开闭原则是总纲，它告诉我们要对扩展开放，对修改关闭；
- 里氏替换原则告诉我们不要破坏继承体系；
- 依赖倒置原则告诉我们要面向接口编程；
- 单一职责原则告诉我们实现类要职责单一；
- 接口隔离原则告诉我们在设计接口的时候要精简单一；
- 迪米特法则告诉我们要降低耦合度；
- 合成复用原则告诉我们要优先使用组合或者聚合关系复用，少用继承关系复用。

## 四、C++ 23种设计模式

| 编号 |   类型 | 模式 | 说明 |
| :--: | :--: | :--: | :--: |
| 1    | [创建型](create_pattern/README.md) | 单例模式 | [单例模式](create_pattern/01_singleton/README.md) |
| 2 | [创建型](create_pattern/README.md) | 原型模式 | [原型模式](create_pattern/02_prototype/README.md) |
| 3 | [创建型](create_pattern/README.md) | 工厂模式 | [工厂模式](create_pattern/03_factory/README.md) |
| 4 | [创建型](create_pattern/README.md) | 抽象工厂模式 | [抽象工厂模式](create_pattern/04_abstract_factory/README.md) |
| 5 | [创建型](create_pattern/README.md) | 建造者模式 | [建造者模式](create_pattern/05_builder/README.md) |
| 6 | [结构型](struct_pattern/README.md) | 代理模式 | [代理模式](struct_pattern/06_proxy/README.md) |
| 7 | [结构型](struct_pattern/README.md) | 适配器模式 | [适配器模式](struct_pattern/07_adapter/README.md) |
| 8 | [结构型](struct_pattern/README.md) | 桥接模式 | [桥接模式](struct_pattern/08_bridge/README.md) |
| 9 | [结构型](struct_pattern/README.md) | 装饰模式 | [装饰模式](struct_pattern/09_decorator/README.md) |
| 10 | [结构型](struct_pattern/README.md) | 外观模式 | [外观模式](struct_pattern/10_facade/README.md) |
| 11 | [结构型](struct_pattern/README.md) | 享元模式 | [享元模式](struct_pattern/11_fly_weight/README.md) |
| 12 | [结构型](struct_pattern/README.md) | 组合模式 | [组合模式](struct_pattern/12_composite/README.md) |
| 13 | [行为型](behavior_pattern/README.md) | 模板方法模式 | [模板方法模式](behavior_pattern/13_template/README.md) |
| 14 | [行为型](behavior_pattern/README.md) | 策略模式 | [策略模式](behavior_pattern/14_strategy/README.md) |
| 15 | [行为型](behavior_pattern/README.md) | 命令模式 | [命令模式](behavior_pattern/15_command/README.md) |
| 16 | [行为型](behavior_pattern/README.md) | 责任链模式 | [责任链模式](behavior_pattern/16_chain_of_responsibility/README.md) |
| 17 | [行为型](behavior_pattern/README.md) | 状态模式 | [状态模式](behavior_pattern/17_state/README.md) |
| 18 | [行为型](behavior_pattern/README.md) | 观察者模式 | [观察者模式](behavior_pattern/18_observer/README.md) |
| 19 | [行为型](behavior_pattern/README.md) | 中介者模式 | [中介者模式](behavior_pattern/19_mediator/README.md) |
| 20 | [行为型](behavior_pattern/README.md) | 迭代器模式 | [迭代器模式](behavior_pattern/20_iterator/README.md) |
| 21 | [行为型](behavior_pattern/README.md) | 访问者模式 | [访问者模式](behavior_pattern/21_visitor/README.md) |
| 22 | [行为型](behavior_pattern/README.md) | 备忘录模式 | [备忘录模式](behavior_pattern/22_memento/README.md) |
| 23 | [行为型](behavior_pattern/README.md) | 解释器模式 | [解释器模式](behavior_pattern/23_interpreter/README.md) |
