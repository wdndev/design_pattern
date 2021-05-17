/**
 * @file        - abstract_factory.h
 * @author      - wdn (you@domain.com)
 * @brief       - 抽象工厂模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include "product.h"

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

// 抽象工厂类：制作Link、Tray、Page
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductLink* create_link(const std::string &caption, const std::string &url) = 0;
    virtual AbstractProductTray* create_tray(const std::string &caption) = 0;
    virtual AbstractProductPage* create_page(const std::string &title, const std::string &author) = 0;
};

namespace {
    
class FactoryHelper
{
public:
    static void register_factory(const std::string &name, std::function<AbstractFactory *()> create_callback)
    {
        m_creater_map.insert(std::make_pair(name, create_callback));
    }
    static AbstractFactory *get_factory(const std::string &name)
    {
        auto itor = m_creater_map.find(name);
        return itor->second();
    }

private:
    static std::unordered_map<std::string, std::function<AbstractFactory *()>> m_creater_map;
};

std::unordered_map<std::string, std::function<AbstractFactory *()>> FactoryHelper::m_creater_map;

}
// 具体工厂：实现了抽象产品角色所定义的接口，由具体工厂来创建，它同具体工厂之间是多对一的关系
class ConcreteFactory : public AbstractFactory
{
public:
    AbstractProductLink *create_link(const std::string &caption, const std::string &url) override
    {
        return new ConcreteProductLink(caption, url);
    }
    AbstractProductTray *create_tray(const std::string &caption) override
    {
        return new ConcreteProductTary(caption);
    }
    AbstractProductPage *create_page(const std::string &title, const std::string &author) override
    {
        return new ConcreteProductPage(title, author);
    }
};

static int ConcreteFactoryInit = []() -> int {
    std::cout << "1" << std::endl;
    FactoryHelper::register_factory("ConcreteFactory", []() { return new ConcreteFactory; });
    return 0;
}();


