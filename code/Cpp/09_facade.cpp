/**
 * @file        - 09_facade.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 外观模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <string>
#include <memory>

/**
 * 子系统角色
*/
class SubSystem01
{
public:
    void method1()
    {
        std::cout << "Method1() of subsystem 01 is called!" << std::endl;
    }
};

/**
 * 子系统角色
*/
class SubSystem02
{
public:
    void method2()
    {
        std::cout << "Method2() of subsystem 02 is called!" << std::endl;
    }
};

/**
 * 子系统角色
*/
class SubSystem03
{
public:
    void method3()
    {
        std::cout << "Method3() of subsystem 03 is called!" << std::endl;
    }
};

/**
 * 外观角色
*/
class Facade
{
public:
    Facade()
    {
        m_obj1 = std::make_shared<SubSystem01>();
        m_obj2 = std::make_shared<SubSystem02>(); 
        m_obj3 = std::make_shared<SubSystem03>(); 
    }
    void method()
    {
        m_obj1->method1();
        m_obj2->method2();
        m_obj3->method3();
    }
private:
    std::shared_ptr<SubSystem01> m_obj1;
    std::shared_ptr<SubSystem02> m_obj2; 
    std::shared_ptr<SubSystem03> m_obj3; 
};

int main()
{
    Facade* f = new Facade();
    f->method();
    
    delete f;

    return 0;
}
