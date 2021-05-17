# 依赖倒置原则

## 一、依赖倒置原则的定义

依赖倒置原则（Dependence Inversion Principle，DIP）是 Object Mentor 公司总裁罗伯特·马丁（Robert C.Martin）于 1996 年在 C++ Report 上发表的文章。

依赖倒置原则的原始定义为：**高层模块不应该依赖低层模块，两者都应该依赖其抽象；抽象不应该依赖细节，细节应该依赖抽象**（High level modules shouldnot depend upon low level modules.Both should depend upon abstractions.Abstractions should not depend upon details. Details should depend upon abstractions）。其核心思想是：**要面向接口编程，不要面向实现编程**。

依赖倒置原则是实现开闭原则的重要途径之一，它**降低了客户与实现模块之间的耦合**。

由于在软件设计中，细节具有多变性，而抽象层则相对稳定，因此以抽象为基础搭建起来的架构要比以细节为基础搭建起来的架构要稳定得多。这里的抽象指的是接口或者抽象类，而细节是指具体的实现类。

**使用接口或者抽象类的目的是制定好规范和契约，而不去涉及任何具体的操作，把展现细节的任务交给它们的实现类去完成。**

## 二、依赖、倒置原则的作用

* 依赖倒置原则可以**降低类间的耦合性**。
* 依赖倒置原则可以**提高系统的稳定性**。
* 依赖倒置原则可以**减少并行开发引起的风险**。
* 依赖倒置原则可以**提高代码的可读性和可维护性**。

## 三、依赖倒置原则的实现方法

**依赖倒置原则的目的是通过要面向接口的编程来降低类间的耦合性**，所以我们在实际编程中只要遵循以下4点，就能在项目中满足这个规则。

* 每个类尽量提供接口或抽象类，或者两者都具备。
* 变量的声明类型尽量是接口或者是抽象类。
* 任何类都不应该从具体类派生。
* 使用继承时尽量遵循里氏替换原则。

下面以“顾客购物程序”为例来说明依赖倒置原则的应用。

【例】依赖倒置原则在“顾客购物程序”中的应用。

本程序反映了 “顾客类”与“商店类”的关系。商店类中有 sell() 方法，顾客类通过该方法购物以下代码定义了顾客类通过网店Shop_A 购物：

```c++
class Customer
{
public:
		void shopping(Shop_A shop)
        {
            // 购物
            shop.sell();
        }
};
```

但是，这种设计存在缺点，如果该顾客想从另外一家商店（如Shop_B）购物，就要将该顾客的代码修改如下：

```c++
class Customer
{
public:
		void shopping(Shop_B shop)
        {
            // 购物
            shop.sell();
        }
};
```

顾客每更换一家商店，都要修改一次代码，这明显违背了开闭原则。存在以上缺点的原因是：顾客类设计时同具体的商店类绑定了，这违背了依赖倒置原则。解决方法是：定义“Shop_A”和“Shop_B”的共同接口 Shop，顾客类面向该接口编程，其代码修改如下：

```c++
class IShop
{
public:
	virtual std::string sell() = 0; 
};

class Shop_A : public IShop
{
public:
  	std::string sell() override
    {
        return "A";
    }
};

class Shop_B : public IShop
{
public:
  	std::string sell() override
    {
        return "B";
    }
};

class Customer
{
public:
		void shopping(IShop shop)
        {
            // 购物
            shop.sell();
        }
};
```

