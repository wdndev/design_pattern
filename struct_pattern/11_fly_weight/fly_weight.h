/**
 * @file        - fly_weight.h
 * @author      - wdn (you@domain.com)
 * @brief       - 享元模式声明
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
#include <map>

// 非享元角色
class UnsharedConcreteFlyweight
{
public:
    UnsharedConcreteFlyweight(std::string info) : m_info(info) {}

    std::string get_info()
    {
        return m_info;
    }

    void set_info(std::string info)
    {
        this->m_info = info;
    }
private:
    std::string m_info;
};

// 抽象享元角色
class FlyWeight
{
public:
    using Ptr = std::shared_ptr<FlyWeight>;
    virtual void operation(UnsharedConcreteFlyweight* state) = 0;
};

// 具体享元角色
class ConcreteFlyweight : public FlyWeight
{
public:
    ConcreteFlyweight(std::string key)
    {
        m_key = key;
        std::cout << "具体享元 " + m_key + " 被创建！" << std::endl;
    }

    void operation(UnsharedConcreteFlyweight* out_state)
    {
        std::cout << "具体享元 " + m_key + " 被调用！" ;
        std::cout << "非享元信息是  " + out_state->get_info() << std::endl;
    }
private:
    std::string m_key;
};

// 享元工厂模式
class FlyweightFactory
{
public:
    FlyWeight::Ptr get_flyweight(std::string key)
    {
        FlyWeight::Ptr flyweight = fly_weights[key];
        if (flyweight != nullptr)
        {
            std::cout << "具体享元 " + key + " 已经存在，被成功获取!" << std::endl;
        }
        else
        {
            flyweight = std::make_shared<ConcreteFlyweight>(key);
            fly_weights[key] = flyweight;
        }
        return flyweight;
    }
private:
    std::map<std::string, FlyWeight::Ptr> fly_weights;
};