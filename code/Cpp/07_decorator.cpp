/**
 * @file        - 07_decorator.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 装饰器模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 在《恶魔战士》中，游戏角色“莫莉卡·安斯兰”的原身是一个可爱少女，
// 但当她变身时，会变成头顶及背部延伸出蝙蝠状飞翼的女妖，当然她还可以变为穿着漂亮外衣的少女。
// 这些都可用装饰模式来实现，在本实例中的“莫莉卡”原身有 set_image(String t) 方法决定其显示方式，
// 而其 变身“蝙蝠状女妖”和“着装少女”可以用 set_changer() 方法来改变其外观，
// 原身与变身后的效果用 display() 方法来显示。


#include <iostream>
#include <string>
#include <memory>

/**
 * 抽象构件角色：莫莉卡
*/
class AbstractComponentMorrign
{
public:
    using Ptr = std::shared_ptr<AbstractComponentMorrign>;

    virtual void display() = 0;

    void set_image(const std::string& img_name)
    {
        m_img_name = img_name;
    }

    std::string get_image()
    {
        return m_img_name;
    }
private:
    std::string m_img_name;
};

/**
 * 具体构件角色：原身
*/
class ConcreteComponentOriginal : public AbstractComponentMorrign
{
public:
    ConcreteComponentOriginal() : AbstractComponentMorrign()
    {
        this->set_image("original!!!");
    }

    void display()
    {
        std::cout << get_image() << std::endl;
    }
};

/**
 * 抽象装饰角色：变形
*/
class AbstractDecoratorChanger : public AbstractComponentMorrign
{
public:
    AbstractDecoratorChanger(AbstractComponentMorrign::Ptr m) 
        : AbstractComponentMorrign(), m_morrign(m)  {}

    void display()
    {
        std::cout << get_image() << std::endl;
    }
protected:
    AbstractComponentMorrign::Ptr m_morrign;
};

/**
 * 具体装饰角色：女妖
*/
class ConcreteDecoratorSuccubus : public AbstractDecoratorChanger
{
public:
    ConcreteDecoratorSuccubus(AbstractComponentMorrign::Ptr m) 
        : AbstractDecoratorChanger(m) {}
    
    void set_changer()
    {
        m_morrign->set_image("Succubus~~~");
    }

    void display()
    {
        this->set_changer();
        m_morrign->display();
    }
};

/**
 * 具体装饰角色：少女
*/
class ConcreteDecoratorGirl : public AbstractDecoratorChanger
{
public:
    ConcreteDecoratorGirl(AbstractComponentMorrign::Ptr m) 
        : AbstractDecoratorChanger(m) {}
    
    void set_changer()
    {
        m_morrign->set_image("Girl~~~");
    }

    void display()
    {
        this->set_changer();
        m_morrign->display();
    }
};

int main()
{
    AbstractComponentMorrign::Ptr m0 = std::make_shared<ConcreteComponentOriginal>();
    m0->display();
    AbstractComponentMorrign::Ptr m1 = std::make_shared<ConcreteDecoratorSuccubus>(m0);
    m1->display();
    AbstractComponentMorrign::Ptr m2 = std::make_shared<ConcreteDecoratorGirl>(m0);
    m2->display();

    m0->display();

    return 0;
}
