/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "singleton.h"

int main()
{
    Apple::get_instance().show();
    std::cout << &Apple::get_instance() << std::endl;
    Apple::get_instance().show();
    std::cout << &Apple::get_instance() << std::endl;

    Orange::get_instance().show();
    Orange::get_instance().show();

    return 0;
}