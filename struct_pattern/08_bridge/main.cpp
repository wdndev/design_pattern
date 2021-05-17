/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 桥接模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "bridge.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    Color::Ptr color = std::make_shared<Yellow>();
    Bag::Ptr bag = std::make_shared<WallBag>();
    bag->set_color(color);
    std::cout << bag->get_name() << std::endl;

    return 0;
}