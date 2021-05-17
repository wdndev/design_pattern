/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 策略模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "strategy.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    Kitchen* kitken = new Kitchen();
    kitken->cooking_method();

    std::cout << "-----------------------------" << std::endl;
    
    kitken->set_strategy(std::make_shared<SteamedCrabs>());
    kitken->cooking_method();

    std::cout << "-----------------------------" << std::endl;

    kitken->set_strategy(std::make_shared<BraisedCrabs>());
    kitken->cooking_method();

    delete kitken;
    return 0;
}