/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 装饰模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "decorator.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    Morrigan::Ptr m0 = std::make_shared<Original>();
    m0->display();
    Morrigan::Ptr m1 = std::make_shared<Succubus>(m0);
    m1->display();
    Morrigan::Ptr m2 = std::make_shared<Girl>(m0);
    m2->display();

    return 0;
}