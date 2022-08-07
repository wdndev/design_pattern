/**
 * @file        - 16_state.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 状态模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 红灯停，绿灯行，黄灯亮了等一等。

#include <iostream>
#include <string>
#include <memory>
#include <windows.h>

/**
 * 抽象状态：
*/
class AbstractState
{
public:
    virtual void handle() = 0;
};

// 前置环境类
class TrafficLightsContext;

// 具体状态类：红灯、绿灯、黄灯
/**
 * 红灯
*/
class RedLight : public AbstractState
{
public:
    RedLight(TrafficLightsContext* context) : m_context(context) {}

    void handle() override;

private:
    TrafficLightsContext* m_context;
};

/**
 * 绿灯
*/
class GreenLight  : public AbstractState
{
public:
    GreenLight (TrafficLightsContext* context) : m_context(context) {}

    void handle() override;

private:
    TrafficLightsContext* m_context;
};

/**
 * 黄灯
*/
class YellowLight  : public AbstractState
{
public:
    YellowLight (TrafficLightsContext* context) : m_context(context) {}

    void handle() override;
    
private:
    TrafficLightsContext* m_context;
};

/**
 * 环境类
*/
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


// 红灯
void RedLight::handle()
{
    std::cout << "Red Light" << std::endl;
    m_context->set_state(new GreenLight(m_context));
    delete this;
}

// 绿灯
void GreenLight::handle()
{
    std::cout << "Green Light" << std::endl;
    m_context->set_state(new YellowLight(m_context));
    delete this;
}

// 黄灯
void YellowLight::handle()
{
    std::cout << "Yellow Light" << std::endl;
    m_context->set_state(new RedLight(m_context));
    delete this;
}


int main()
{
    TrafficLightsContext tlc;

    enum state_eu {Red, Green, Yellow};

    state_eu state = Red;  // 初始状态为红灯
    int i = 0;  // 总次数
    int seconds;  // 秒数

    while (true) 
    {
        // 表示一个完整的状态流（红灯->绿灯->黄灯）已经完成
        if (i % 3 == 0)
            std::cout << "**********" << "Session " << ((i+1)/3)+1 << "**********" << std::endl;

        // 根据当前状态来设置持续时间，红灯（6秒）、绿灯（4秒）、黄灯（2秒）
        if (state == Red) {
            seconds = 6;
            state = Green;
        } else if (state == Green) {
            seconds = 4;
            state = Yellow;
        } else if (state == Yellow) {
            seconds = 2;
            state = Red;
        }

        // 休眠
        Sleep(seconds * 1000);

        tlc.request();
        i++;
    }


    return 0;
}
