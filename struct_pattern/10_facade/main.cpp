/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 外观模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "facade.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    Facade* f = new Facade();
    f->method();
    
    delete f;

    return 0;
}