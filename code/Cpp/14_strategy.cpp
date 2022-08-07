/**
 * @file        - 14_strategy.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 策略模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 关于大闸蟹的做法有很多种，以清蒸大闸蟹和红烧大闸蟹两种方法为例，介绍策略模式的应用。

#include <iostream>
#include <string>
#include <memory>

// 抽象策略类：大闸蟹加工类
class StrategyCrabCooking
{
public:
    using Ptr = std::shared_ptr<StrategyCrabCooking>;

    virtual void cooking_method() = 0;
};

// 具体策略类:清蒸大螃蟹
class ConcreteStrategySteamedCrabs : public StrategyCrabCooking
{
public:
    void cooking_method() override
    {
        std::cout << "清蒸大螃蟹." << std::endl;
    }
};

// 具体策略类:红烧大螃蟹
class ConcreteStrategyBraisedCrabs : public StrategyCrabCooking
{
public:
    void cooking_method() override
    {
        std::cout << "红烧大螃蟹." << std::endl;
    }
};

// 环境类
class ContextKitchen : public StrategyCrabCooking
{
public:
    void set_strategy(StrategyCrabCooking::Ptr strategy)
    {
        m_strategy = strategy;
    }

    StrategyCrabCooking::Ptr get_strategy()
    {
        return m_strategy;
    }

    void cooking_method() override
    {
        if (m_strategy != 0)
            m_strategy->cooking_method();
        else
            std::cout << "未选择，重新选择!" <<std::endl;
    }
private:
    StrategyCrabCooking::Ptr m_strategy;
};

int main()
{
    ContextKitchen* kitken = new ContextKitchen();
    kitken->cooking_method();

    std::cout << "-----------------------------" << std::endl;
    
    kitken->set_strategy(std::make_shared<ConcreteStrategySteamedCrabs>());
    kitken->cooking_method();

    std::cout << "-----------------------------" << std::endl;

    kitken->set_strategy(std::make_shared<ConcreteStrategyBraisedCrabs>());
    kitken->cooking_method();

    delete kitken;
    return 0;
}


