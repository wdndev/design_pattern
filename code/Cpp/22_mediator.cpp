/**
 * @file        - 22_mediator.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 中介模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 房地产交流平台是“房地产中介公司”提供给“卖方客户”与“买方客户”进行信息交流的平台

#include <iostream>
#include <string>
#include <list>

class Customer;

/**
 * 抽象中介者：中介公司
*/
class Medium
{
public:
    // 客户注册
    virtual void registers(Customer* member) = 0;
    // 转发
    virtual void relay(std::string from, std::string addr) = 0;
};

/**
 * 具体中介者：房地产中介
*/
class EstateMedium : public Medium
{
public:
    void registers(Customer* member) override;
    void relay(std::string from, std::string addr) override;
private:
    std::list<Customer*> m_members;
};

/**
 * 抽象同事类：客户
*/
class Customer
{
public:
    Customer(const std::string& name) : m_name(name) {}

    std::string get_name()
    {
        return m_name;
    }

    void set_medium(Medium* medium)
    {
        m_medium = medium;
    }

    virtual void send(std::string ad) = 0;
    virtual void receive(std::string from, std::string addr) = 0;

protected:
    Medium* m_medium;
    std::string m_name;
};

/**
 * 具体同事类：卖方
*/
class Seller : public Customer
{
public:
    Seller(const std::string& name) : Customer(name) {}

    void send(std::string addr) override;
    void receive(std::string from, std::string addr) override;
};

/**
 * 具体同事类：买方
*/
class Buyer : public Customer
{
public:
    Buyer(const std::string& name) : Customer(name) {}

    void send(std::string addr) override;
    void receive(std::string from, std::string addr) override;
};

// 具体中介者：房地产中介
void EstateMedium::registers(Customer* member)
{
    auto result = std::find(std::begin(m_members), std::end(m_members), member);
    if (m_members.empty() || (result == std::end(m_members)) )
    {
        m_members.push_back(member);
        member->set_medium(this);
    }
}

void EstateMedium::relay(std::string from, std::string addr)
{
    for(auto ob : m_members)
    {
        std::string name = ob->get_name();
        if (name != from)
        {
            ob->receive(from, addr);
        }
    }
}

// 具体同事类：卖方
void Seller::send(std::string addr)
{
    std::cout << "send: " << "我(卖方)说: " + addr << std::endl;
    m_medium->relay(m_name, addr);
}

void Seller::receive(std::string from, std::string addr)
{
    std::cout << "receive: " << from << "说: " + addr << std::endl;
}

// 具体同事类：买方
void Buyer::send(std::string addr)
{
    std::cout << "send: " << "我(买方)说: " + addr << std::endl;
    m_medium->relay(m_name, addr);
}

void Buyer::receive(std::string from, std::string addr)
{
    std::cout << "receive: "<< from << "说: " + addr << std::endl;
}

int main()
{
    Medium* md = new EstateMedium();
    Customer* member1 = new Seller("张三(卖方)");
    Customer* member2 = new Buyer("李四(买方)");
    md->registers(member1); //客户注册
    md->registers(member2);
    member1->send("我有一套房子.");
    member2->send("在哪儿?");
    member1->send("珠海.");
    member2->send("多少钱?");
    member2->send("多大?");


    return 0;
}
