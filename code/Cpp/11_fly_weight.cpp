/**
 * @file        - 11_fly_weight.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 享元模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>
#include <memory>
#include <map>

/**
 * 非享元角色：是不可以共享的外部状态，它以参数的形式注入具体享元的相关方法中。
*/
class UnSharedConcreteFlyWeight
{
public:
    UnSharedConcreteFlyWeight(const std::string& info) : m_info(info) {}

    std::string get_info()
    {
        return m_info;
    }

    void set_info(const std::string& info)
    {
        m_info = info;
    }
private:
    std::string m_info;
};

/**
 * 抽象享元角色：是所有的具体享元类的基类，为具体享元规范需要实现的公共接口，
 *              非享元的外部状态以参数的形式通过方法传入。
*/
class AbstractFlyWeight
{
public:
    using Ptr = std::shared_ptr<AbstractFlyWeight>;
    virtual void operation(UnSharedConcreteFlyWeight* state) = 0;
};

/**
 * 具体享元角色：实现抽象享元角色中所规定的接口。
*/
class ConcreteFlyWeight : public AbstractFlyWeight
{
public:
    ConcreteFlyWeight(const std::string& key) : AbstractFlyWeight(), m_key(key)
    {
        std::cout << "具体享元 " + m_key + " 被创建 ! " << std::endl;
    }

    void operation(UnSharedConcreteFlyWeight* out_state)
    {
        std::cout << "具体享元 " + m_key + " 被调用 ! " ;
        std::cout << "非享元信息是  " + out_state->get_info() << std::endl;
    }

private:
    std::string m_key;
};

/**
 * 享元工厂：负责创建和管理享元角色。当客户对象请求一个享元对象时，享元工厂检査系统中是否存在符合要求的享元对象，
 *          如果存在则提供给客户；如果不存在的话，则创建一个新的享元对象
*/
class FlyWeightFactory
{
public:
    AbstractFlyWeight::Ptr get_flyweight(std::string key)
    {
        AbstractFlyWeight::Ptr flyweight = m_fly_weights[key];
        if (flyweight != nullptr)
        {
            std::cout << "具体享元 " + key + " 已经存在，被成功获取!" << std::endl;
        }
        else
        {
            flyweight = std::make_shared<ConcreteFlyWeight>(key);
            m_fly_weights[key] = flyweight;
        }
        return flyweight;
    }

private:
    std::map<std::string, AbstractFlyWeight::Ptr> m_fly_weights;
};

int main()
{
    FlyWeightFactory* factory = new FlyWeightFactory();
    AbstractFlyWeight::Ptr f01 = factory->get_flyweight("a");
    AbstractFlyWeight::Ptr f02 = factory->get_flyweight("a");
    AbstractFlyWeight::Ptr f03 = factory->get_flyweight("a");
    AbstractFlyWeight::Ptr f11 = factory->get_flyweight("b");
    AbstractFlyWeight::Ptr f12 = factory->get_flyweight("b");
    // f01->operation(new UnSharedConcreteFlyWeight("First call a!"));
    // f02->operation(new UnSharedConcreteFlyWeight("Second call a!"));
    // f03->operation(new UnSharedConcreteFlyWeight("Third call a!"));
    // f11->operation(new UnSharedConcreteFlyWeight("First call b!"));
    // f12->operation(new UnSharedConcreteFlyWeight("Second call b!"));
    f01->operation(new UnSharedConcreteFlyWeight("第 1 次调用a."));
    f02->operation(new UnSharedConcreteFlyWeight("第 2 次调用a."));
    f03->operation(new UnSharedConcreteFlyWeight("第 3 次调用a."));
    f11->operation(new UnSharedConcreteFlyWeight("第 1 次调用b."));
    f12->operation(new UnSharedConcreteFlyWeight("第 2 次调用b."));


    return 0;
}

