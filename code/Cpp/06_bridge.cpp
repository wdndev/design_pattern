/**
 * @file        - 06_bridge.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 桥接模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 女士皮包有很多种，按用途分可选钱包（Wallet）和挎包（HandBag），
// 按颜色分可选黄色（Yellow）和红色（Red）。可以按两个维度定义为颜色类和包类

#include <iostream>
#include <string>
#include <memory>

/**
 * 实现化角色：颜色
*/
class ImplementorColor
{
public:
    using Ptr = std::shared_ptr<ImplementorColor>;

    virtual std::string get_color() = 0;
};

/**
 * 具体实现化角色：黄色
*/
class ConcreteImplYellow : public ImplementorColor
{
public:
    std::string get_color() override
    {
        return "Yellow ";
    }
};

/**
 * 具体实现化角色：红色
*/
class ConcreteImplRed : public ImplementorColor
{
public:
    std::string get_color() override
    {
        return "Red ";
    }
};

/**
 * 抽象角色：包
*/
class Bag
{
public:
    using Ptr = std::shared_ptr<Bag>;

    virtual std::string get_name() = 0;

    void set_color(ImplementorColor::Ptr color)
    {
        this->m_color = color;
    }

protected:
    ImplementorColor::Ptr m_color;
};

/**
 * 扩展抽象化角色：挎包
*/
class HandBag : public Bag
{
public:
    std::string get_name()
    {
        return m_color->get_color() + "HandBag";
    }
};

/**
 * 扩展抽象化角色：钱包
*/
class WallBag : public Bag
{
public:
    std::string get_name()
    {
        return m_color->get_color() + "WallBag";
    }
};

int main()
{
    ImplementorColor::Ptr color = std::make_shared<ConcreteImplRed>();
    Bag::Ptr bag = std::make_shared<WallBag>();
    bag->set_color(color);
    std::cout << bag->get_name() << std::endl;

    return 0;
}
