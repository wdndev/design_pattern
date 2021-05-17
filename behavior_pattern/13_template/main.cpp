/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 模板模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "template.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    StudyAbroad* tm = new StudyInAmerica();
    tm->template_method();

    delete tm;
    return 0;
}