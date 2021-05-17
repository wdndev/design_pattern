/**
 * @file        - memento.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 备忘录模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "memento.h"

// 备忘录：美女
void Girl::set_name(std::string name)
{
    this->m_name = name;
}

std::string Girl::get_name()
{
    return this->m_name;
}

// 发起人：您
void You::set_wife(std::string name)
{
    m_wife_name = name;
}

std::string You::get_wife()
{
    return m_wife_name;
}

Girl::Ptr You::create_memento()
{
    return std::make_shared<Girl>(m_wife_name);
}

void You::restore_momento(Girl::Ptr p)
{
    set_wife(p->get_name());
}

// 管理者：美女栈
bool GirlStack::push(Girl::Ptr p)
{
    if(m_top >= 4)
    {
        std::cout << "你太花心了，变来变去的! " << std::endl;
        return false;
    }
    else
    {
        m_girl[++m_top] = p;
        return true;
    }
}

Girl::Ptr GirlStack::pop()
{
    if(m_top <= 0)
    {
        std::cout << "美女栈空了! " << std::endl;
        return m_girl[0];
    }
    else
    {
        return m_girl[m_top--];
    }
}