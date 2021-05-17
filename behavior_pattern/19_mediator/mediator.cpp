/**
 * @file        - mediator.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 中介者模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "mediator.h"

// 具体中介者：房地产中介
void EstateMedia::registers(Customer* member)
{
    auto result = std::find(std::begin(m_members), std::end(m_members), member);
    if (m_members.empty() || (result == std::end(m_members)) )
    {
        m_members.push_back(member);
        member->set_media(this);
    }
}

void EstateMedia::relay(std::string from, std::string ad)
{
    for (auto ob : m_members)
    {
        std::string m_name = ob->get_name();
        if (m_name != from)
        {
            ob->receive(from, ad);
        }
    }
}

// 具体同事类：卖方
void Seller::send(std::string ad)
{
    std::cout << "send: " << "我(卖方)说: " + ad << std::endl;
    m_media->relay(m_name, ad);
}

void Seller::receive(std::string from, std::string ad)
{
    std::cout << "receive: " << from << "说: " + ad << std::endl;
}

// 具体同事类：买方
void Buyer::send(std::string ad)
{
    std::cout << "send: " << "我(买方)说: " + ad << std::endl;
    m_media->relay(m_name, ad);
}

void Buyer::receive(std::string from, std::string ad)
{
    std::cout << "receive: "<< from << "说: " + ad << std::endl;
}