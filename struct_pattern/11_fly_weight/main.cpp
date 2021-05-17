/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 享元模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "fly_weight.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    FlyweightFactory* factory = new FlyweightFactory();
    FlyWeight::Ptr f01 = factory->get_flyweight("a");
    FlyWeight::Ptr f02 = factory->get_flyweight("a");
    FlyWeight::Ptr f03 = factory->get_flyweight("a");
    FlyWeight::Ptr f11 = factory->get_flyweight("b");
    FlyWeight::Ptr f12 = factory->get_flyweight("b");
    // f01->operation(new UnsharedConcreteFlyweight("First call a!"));
    // f02->operation(new UnsharedConcreteFlyweight("Second call a!"));
    // f03->operation(new UnsharedConcreteFlyweight("Third call a!"));
    // f11->operation(new UnsharedConcreteFlyweight("First call b!"));
    // f12->operation(new UnsharedConcreteFlyweight("Second call b!"));
    f01->operation(new UnsharedConcreteFlyweight("第 1 次调用a."));
    f02->operation(new UnsharedConcreteFlyweight("第 2 次调用a."));
    f03->operation(new UnsharedConcreteFlyweight("第 3 次调用a."));
    f11->operation(new UnsharedConcreteFlyweight("第 1 次调用b."));
    f12->operation(new UnsharedConcreteFlyweight("第 2 次调用b."));


    return 0;
}