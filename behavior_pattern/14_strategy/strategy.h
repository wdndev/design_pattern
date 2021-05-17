/**
 * @file        - strategy.h
 * @author      - wdn (you@domain.com)
 * @brief       - 策略模式声明
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

// 抽象策略类：大闸蟹加工类
class CrabCooking
{
public:
    using Ptr = std::shared_ptr<CrabCooking>;

    virtual void cooking_method() = 0;
};

// 具体策略类:清蒸大螃蟹
class SteamedCrabs : public CrabCooking
{
public:
    void cooking_method()
    {
        std::cout << "清蒸大螃蟹." << std::endl;
    }
};

// 具体策略类:红烧大螃蟹
class BraisedCrabs : public CrabCooking
{
public:
    void cooking_method()
    {
        std::cout << "红烧大螃蟹." << std::endl;
    }
};

// 环境类
class Kitchen
{
public:
    void set_strategy(CrabCooking::Ptr strategy)
    {
        m_strategy = strategy;
    }

    CrabCooking::Ptr get_strategy()
    {
        return m_strategy;
    }

    void cooking_method()
    {
        if (m_strategy != 0)
            m_strategy->cooking_method();
        else
            std::cout << "未选择，重新选择!" <<std::endl;
        
    }
private:
    CrabCooking::Ptr m_strategy;
};