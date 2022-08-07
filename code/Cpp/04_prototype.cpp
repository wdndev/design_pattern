/**
 * @file        - 04_prototype.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 原型模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>

/**
 * 抽象原型类：规定了具体抽象类对象必须实现的接口
*/
class AbstractPrototype
{
public:
    virtual ~AbstractPrototype() {} 
    virtual void use(const std::string& name) = 0;
    virtual AbstractPrototype* clone() = 0;
};

/**
 * 具体实现类：实现抽象原型类 clone() 的方法，是可以被复制的
*/
class ConcretePrototype : public AbstractPrototype
{
public:
    ConcretePrototype(const std::string& name) : m_name(name) {}

    AbstractPrototype* clone() override
    {
        return new ConcretePrototype(m_name);
    }

    void use(const std::string& name)
    {
        std::cout << "Message box " << m_name << " " << name << std::endl;
    }

private:
    std::string m_name;
};

/**
 * 访问类：使用具体原型类中的 clone() 方法来复制新的对象。
*/
class VisitPrototype
{
public:
    void registers(const std::string& name, AbstractPrototype* pro)
    {
        m_map.insert({name, pro});
    }

    AbstractPrototype* create(const std::string& name)
    {
        auto it = m_map.find(name);
        if (it != m_map.end())
        {
            return it->second->clone();
        }
        else
        {
            return nullptr;
        }
    }
private:
    std::unordered_map<std::string, AbstractPrototype*> m_map;
};

int main()
{
    VisitPrototype mgr;
    AbstractPrototype* p1 = new ConcretePrototype("hello");
    mgr.registers("MB", p1);
    p1->use("world");
    AbstractPrototype* p2 = mgr.create("MB");
    p2->use("World");

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    AbstractPrototype* pp = mgr.create("Not");
    if (pp == nullptr)
    {
        std::cout << "克隆失败，不存在该键" << std::endl;
    }

    delete p1;
    delete p2;

    return 0;
}
