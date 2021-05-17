/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 迭代器模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "iterator.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

int main()
{
    ConcreteAggregate* ca = new ConcreteAggregate();
    ca->push("hello");
    ca->push("world");

    Iterator* it = new ConcreteIterator(ca);
    while (!it->is_done())
    {
        std::cout << it->current_item() << std::endl;
        it->next();
    }

    delete it;
    delete ca;
    return 0;
}