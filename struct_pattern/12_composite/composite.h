/**
 * @file        - composite.h
 * @author      - wdn (you@domain.com)
 * @brief       - 组合模式声明
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

// 抽象构建：物品
class Articles
{
public:
    using Ptr = std::shared_ptr<Articles>;
    virtual float calculation() = 0;    // 计算
    virtual void show() = 0;
};

class Goods : public Articles
{
public:
    Goods(std::string name, int quantity, float unit_price)
        : m_name(name), m_quantity(quantity), m_unit_price(unit_price) {}

    float calculation()
    {
        return m_quantity * m_unit_price;
    }

    void show()
    {
        std::cout << m_name 
                  << " (数量 " + std::to_string(m_quantity) + ", 单价: " + std::to_string(m_unit_price) + " RMB.)"
                  << std::endl;
    }
private:
    std::string m_name;         // 名字
    int m_quantity;             // 数量
    float m_unit_price;         // 单价
};

// 树枝构建：袋子
class Bags : public Articles
{
public:
    using Ptr = std::shared_ptr<Bags>;
    Bags(std::string name) : m_name(name) {}
    void add(Articles::Ptr c)
    {
        m_bags.push_back(c);
    }
    void remove(Articles::Ptr c)
    {
        std::cout << "待改进!" << std::endl;
        // for (std::vector<Articles::Ptr>::iterator itr; itr != m_bags.end(); itr++)
        // {
        //     if (*itr == c)
        //     {
        //         m_bags.erase(itr);
        //         std::cout << " 移除了: ";
        //         c->show();
        //         std::cout << std::endl;
        //     }
        //     else
        //     {
        //         std::cout << "NULL!!!" << std::endl;
        //     }
        // }
    }

    Articles::Ptr get_child(int i)
    {
        return m_bags.at(i);
    }

    float calculation()
    {
        float s = 0;
        for (Articles::Ptr obj : m_bags)
        {
            s += obj->calculation();
        }

        return s;
    }

    void show()
    {
        for (Articles::Ptr obj : m_bags)
        {
            obj->show();
        }
    }
private:
    std::string m_name;
    std::vector<Articles::Ptr> m_bags;
};