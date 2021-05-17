/**
 * @file        - factory.h
 * @author      - wdn (you@domain.com)
 * @brief       - 工厂模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <vector>

// 抽象产品：定义产品的规范，描述产品的功能
class AbstractProduct
{
public:
    virtual ~AbstractProduct() {}

    virtual void use() = 0;
};

// 具体产品1：实现抽象产品所定义的接口，与具体工厂之间一一对于
class ConcreteProductCard : public AbstractProduct
{
public:
    ConcreteProductCard(const std::string& owner) : m_owner(owner) {}
    void use() override
    {
        std::cout << "use IDCard with owner " << m_owner << std::endl;
    }
private:
    std::string m_owner;
};

// 具体产品2：实现抽象产品所定义的接口，与具体工厂之间一一对于
class ConcreteProductPhone : public AbstractProduct
{
public:
    ConcreteProductPhone(const std::string& owner) : m_owner(owner) {}
    void use() override
    {
        std::cout << "use Phone with owner " << m_owner << std::endl;
    }
private:
    std::string m_owner;
};

// 抽象工厂：提供创建产品的接口，调用者通过它访问具体工厂的工厂方法 newProduct() 来创建产品。
class AbstractFactory
{
public:
    virtual ~AbstractFactory() {}
    virtual void register_product(AbstractProduct*) = 0;
    virtual AbstractProduct* create_product(const std::string& owner) = 0;
    virtual AbstractProduct* create(const std::string& owner)
    {
        AbstractProduct* pro = create_product(owner);
        register_product(pro);
        return pro;
    }
};

// 具体工厂1：主要实现抽象工厂中的抽象方法，完成具体产品的创建
class ConcreteFactoryCard : public AbstractFactory
{
public:
    AbstractProduct* create_product(const std::string& owner)
    {
        return new ConcreteProductCard(owner);
    }
    void register_product(AbstractProduct* pro)
    {
        m_product_list.push_back(pro);
    }
private:
    std::vector<AbstractProduct*> m_product_list;
};

// 具体工厂2：主要实现抽象工厂中的抽象方法，完成具体产品的创建
class ConcreteFactoryPhone : public AbstractFactory
{
public:
    AbstractProduct* create_product(const std::string& owner)
    {
        return new ConcreteProductPhone(owner);
    }
    void register_product(AbstractProduct* pro)
    {
        m_product_list.push_back(pro);
    }
private:
    std::vector<AbstractProduct*> m_product_list;
};