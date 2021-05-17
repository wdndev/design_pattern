/**
 * @file        - prototype.h
 * @author      - wdn (you@domain.com)
 * @brief       - 原型模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once 

#include <iostream>
#include <string>
#include <unordered_map>

// 抽象原型类：规定了具体抽象类对象必须实现的接口
class AbstractPrototype
{
public:
    virtual ~AbstractPrototype() {}
    virtual AbstractPrototype *clone() = 0;
    virtual void use(const std::string &str) = 0;
};

// 具体实现类：实现抽象原型类 clone（） 的方法，是可以被复制的
class ConcretePrototype : public AbstractPrototype
{
public:
    ConcretePrototype(const std::string &str) : m_name(str) {}

    AbstractPrototype *clone() override
    {
        return new ConcretePrototype(m_name);
    }

    void use(const std::string &str)
    {
        std::cout << "Message box " << m_name << " " << str << std::endl;
    }

private:
    std::string m_name;
};

//访问类：使用具体原型类中的 clone() 方法来复制新的对象。
class VisitPrototype
{
public:
    void registers(const std::string& name, AbstractPrototype* pro)
    {
        m_map.insert({name, pro});
    }

    AbstractPrototype* create(const std::string& name)
    {
        auto it = m_map.find(name);
        if (it != m_map.end())
        {
            return it->second->clone();
        }
        else
        {
            return nullptr;
        }
    }
private:
    std::unordered_map<std::string, AbstractPrototype*> m_map;
};
