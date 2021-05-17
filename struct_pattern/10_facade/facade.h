/**
 * @file        - facade.h
 * @author      - wdn (you@domain.com)
 * @brief       - 外观模式声明
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

// 子系统角色
class SubSysrem01
{
public:
    void method1()
    {
        std::cout << "Method1() of subsystem 01 is called!" << std::endl;
    }
};

// 子系统角色
class SubSysrem02
{
public:
    void method2()
    {
        std::cout << "Method2() of subsystem 02 is called!" << std::endl;
    }
};

// 子系统角色
class SubSysrem03
{
public:
    void method3()
    {
        std::cout << "Method3() of subsystem 03 is called!" << std::endl;
    }
};

//外观角色
class Facade
{
public:
    void method()
    {
        obj1->method1();
        obj2->method2();
        obj3->method3();
    }
private:
    std::shared_ptr<SubSysrem01> obj1 = std::make_shared<SubSysrem01>();
    std::shared_ptr<SubSysrem02> obj2 = std::make_shared<SubSysrem02>(); 
    std::shared_ptr<SubSysrem03> obj3 = std::make_shared<SubSysrem03>(); 
};