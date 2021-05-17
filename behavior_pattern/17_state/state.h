/**
 * @file        - state.h
 * @author      - wdn (you@domain.com)
 * @brief       - 状态模式声明
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

// 抽象状态：
class AbstractState
{
public:
    virtual void handle() = 0;
};

// 前置环境类
class TrafficLightsContext;

// 具体状态类：红灯、绿灯、黄灯
// 红灯
class RedLight : public AbstractState
{
public:
    RedLight(TrafficLightsContext* context) : m_context(context) {}

    virtual void handle() override;

private:
    TrafficLightsContext* m_context;
};

// 绿灯
class GreenLight : public AbstractState
{
public:
    GreenLight(TrafficLightsContext* context) : m_context(context) {}

    virtual void handle() override;

private:
    TrafficLightsContext* m_context;
};

// 黄灯
class YellowLight : public AbstractState
{
public:
    YellowLight(TrafficLightsContext* context) : m_context(context) {}

    virtual void handle() override;

private:
    TrafficLightsContext* m_context;
};

// 环境类
class TrafficLightsContext
{
public:
    TrafficLightsContext() 
    { 
        m_state = new RedLight(this); 
    }
    void set_state(AbstractState* state) 
    { 
        m_state = state; 
    }

    void request() 
    { 
        m_state->handle(); 
    }

private:
    AbstractState* m_state;
};