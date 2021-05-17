/**
 * @file        - memento.h
 * @author      - wdn (you@domain.com)
 * @brief       - 备忘录模式声明
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
#include <vector>
#include <list>

// 备忘录：美女
class Girl
{
public:
    using Ptr = std::shared_ptr<Girl>;
    Girl(std::string name) : m_name(name) {}

    void set_name(std::string name);

    std::string get_name();
private:
    std::string m_name;
};

// 发起人：您
class You
{
public:
    void set_wife(std::string name);

    std::string get_wife();

    Girl::Ptr create_memento();

    void restore_momento(Girl::Ptr p);

private:
    std::string m_wife_name;
};

// 管理者：美女栈
class GirlStack
{
public:
    GirlStack()
    {
        m_top = -1;
    }

    bool push(Girl::Ptr p);

    Girl::Ptr pop();

private:
    int m_top;
    Girl::Ptr m_girl[5];
};