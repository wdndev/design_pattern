/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 代理模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "proxy.h"


#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    SubjectSpecialty* pro = new Proxy();

    pro->display();

    delete pro;

    return 0;
}