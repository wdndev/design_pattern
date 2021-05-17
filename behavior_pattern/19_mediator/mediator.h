/**
 * @file        - mediator.h
 * @author      - wdn (you@domain.com)
 * @brief       - 中介者模式声明
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

class Customer;

// 抽象中介者：中介公司
class Media
{
public:
    virtual void registers(Customer* member) = 0;                // 客户注册
    virtual void relay(std::string from, std::string ad) = 0;   // 转发
};

// 具体中介者：房地产中介
class EstateMedia : public Media
{
public:
    void registers(Customer* member) override;
    void relay(std::string from, std::string ad) override;
private:
    std::list<Customer*> m_members;
};

// 抽象同事类：客户
class Customer
{
public:
    Customer(std::string name) : m_name(name) {}

    std::string get_name()
    {
        return m_name;
    }

    void set_media(Media* media)
    {
        m_media = media;
    }

    virtual void send(std::string ad) = 0;
    virtual void receive(std::string from, std::string ad) = 0;

    Media* m_media;
    std::string m_name;
};

// 具体同事类：卖方
class Seller : public Customer
{
public:
    Seller(std::string name) : Customer(name) {}

    void send(std::string ad) override;
    void receive(std::string from, std::string ad) override;
};

// 具体同事类：买方
class Buyer : public Customer
{
public:
    Buyer(std::string name) : Customer(name) {}

    void send(std::string ad) override;
    void receive(std::string from, std::string ad) override;
};
