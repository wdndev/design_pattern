/**
 * @file        - 05_proxy.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 代理模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// “特产公司”经营许多特产，它是真实主题，提供了显示特产的 display() 方法，
// 可以用窗体程序实现。而代理公司是特产公司特产的代理，
// 通过调用特产公司的 display() 方法显示代理产品，当然它可以增加一些额外的处理，
// 如包裝或加价等。客户可通过代理公司间接访问“特产公司”的产品。

#include <iostream>
#include <string>
#include <memory>

/**
 * 抽象主题
*/
class AbstractSubject
{
public:
    virtual ~AbstractSubject() {}
    virtual void display() = 0;
};

/**
 * 真实主题
*/
class RealSubject : public AbstractSubject
{
public:
    using Ptr = std::shared_ptr<RealSubject>;

    RealSubject() : AbstractSubject()
    {
        std::cout << "RealSubject()" << std::endl;
    }
    ~RealSubject()
    {
        std::cout << "~RealSubject()" << std::endl;
    }
    void display() override
    {
        std::cout << "RealSubject::display()" << std::endl;
    }
};

/**
 * 代理类
*/
class Proxy : public AbstractSubject
{
public:
    Proxy() : AbstractSubject(), m_speciality(std::make_shared<RealSubject>())
    {
        std::cout << "Proxy()" << std::endl;
    }
    ~Proxy()
    {
        std::cout << "~Proxy()" << std::endl;
    }
    void pre_request()
    {
        std::cout << "pre process!" <<  std::endl;
    }

    void post_request()
    {
        std::cout << "proxy end!" <<  std::endl;
    }

    void display() override
    {
        this->pre_request();
        m_speciality->display();
        this->post_request();
        
    }
private:
    RealSubject::Ptr m_speciality;
};

int main()
{
    AbstractSubject* pro = new Proxy();

    pro->display();

    delete pro;
    return 0;
}
