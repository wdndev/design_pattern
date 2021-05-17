/**
 * @file        - state.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 状态模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "state.h"

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


