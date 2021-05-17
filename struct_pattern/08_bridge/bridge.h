/**
 * @file        - bridge.h
 * @author      - wdn (you@domain.com)
 * @brief       - 桥接模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <memory>

// 实现化角色：颜色
class Color
{
public:
    using Ptr = std::shared_ptr<Color>;

    virtual std::string get_color() = 0;
};

// 具体实现化角色：黄色
class Yellow : public Color
{
public:
    std::string get_color()
    {
        return "yellow ";
    }
};

// 具体实现化角色：红色
class Red : public Color
{
public:
    std::string get_color()
    {
        return "red ";
    }
};

// 抽象角色：包
class Bag
{
public:
    using Ptr = std::shared_ptr<Bag>;
    Color::Ptr m_color;

    virtual std::string get_name() = 0;

    void set_color(Color::Ptr color)
    {
        this->m_color = color;
    }
};

// 扩展抽象化角色：挎包
class HandBag : public Bag
{
public:
    std::string get_name()
    {
        return m_color->get_color() + "HandBag";
    }
};

// 扩展抽象化角色：钱包
class WallBag : public Bag
{
public:
    std::string get_name()
    {
        return m_color->get_color() + "WallBag";
    }
};
