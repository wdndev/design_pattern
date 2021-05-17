/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 原型模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */
#include "prototype.h"
#include <cassert>
#include <iostream>

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