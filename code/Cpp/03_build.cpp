/**
 * @file        - 03_build.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 建造者模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 客厅装修是一个复杂的过程，它包含墙体的装修、电视机的选择、沙发的购买与布局等。
// 客户把装修要求告诉项目经理，项目经理指挥装修工人一步步装修，最后完成整个客厅的装修与布局。
// 这里客厅是产品，包括墙、电视和沙发等组成部分。
// 具体装修工人是具体建造者，他们负责装修与墙、电视和沙发的布局。
// 项目经理是指挥者，他负责指挥装修工人进行装修。

#include <iostream>
#include <string>
#include <vector>
#include <memory>

/**
 * 产品：客厅
*/
class ProductParlour
{
public:

    using Ptr = std::shared_ptr<ProductParlour>;
    
    void set_wall(const std::string &wall)
    {
        m_wall = wall;
    }

    void set_TV(const std::string &TV)
    {
        m_TV = TV;
    }

    void set_sofa(const std::string &sofa)
    {
        m_sofa = sofa;
    }

    void show()
    {
        std::cout << "wall is " << m_wall << std::endl;
        std::cout << "TV is " << m_TV << std::endl;
        std::cout << "sofa is " << m_sofa << std::endl;
    }
private:
    std::string m_wall;     // 墙
    std::string m_TV;       // 电视
    std::string m_sofa;     // 沙发
};

/**
 * 抽象建造者：装修工人
*/
class AbstractBuilderDecorator
{
public:
    // 创建产品对象
    virtual void build_wall() = 0;
    virtual void build_TV() = 0;
    virtual void build_sofa() = 0;

    // 返回产品对象
    ProductParlour::Ptr get_result()
    {
        return product;
    }

    ProductParlour::Ptr product = std::make_shared<ProductParlour>();
};

/**
 * 具体建造者：具体装修工人1
*/
class ConcreteBuilderDecorator1 : public AbstractBuilderDecorator
{
public:
    void build_wall()
    {
        product->set_wall("w1");
    }

    void build_TV()
    {
        product->set_TV("TV1");
    }

    void build_sofa()
    {
        product->set_sofa("sf1");
    }
};

/**
 * 具体建造者：具体装修工人2
*/
class ConcreteBuilderDecorator2 : public AbstractBuilderDecorator
{
public:
    void build_wall()
    {
        product->set_wall("w2");
    }
 
    void build_TV()
    {
        product->set_TV("TV2");
    }

    void build_sofa()
    {
        product->set_sofa("sf2");
    }
};

/**
 * 指挥者：项目经理
*/
class DirectorProjectMgr
{
public:
    DirectorProjectMgr(AbstractBuilderDecorator* builder) : m_builder(builder) {}
    
    // 产品构建与组装方法
    ProductParlour::Ptr decorate()
    {
        m_builder->build_wall();
        m_builder->build_TV();
        m_builder->build_sofa();

        return m_builder->get_result();
    }
private:
    AbstractBuilderDecorator* m_builder;
};

int main()
{
    AbstractBuilderDecorator* bp = new ConcreteBuilderDecorator1();
    DirectorProjectMgr* m = new DirectorProjectMgr(bp);
    ProductParlour::Ptr pp = m->decorate();
    pp->show();
  
    delete m;
    delete bp;
    return 0;
}

