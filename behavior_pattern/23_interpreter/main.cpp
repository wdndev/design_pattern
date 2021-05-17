/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 解释器模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "interpreter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::string exp_str = "a+b-c";      // 为简化处理，这里必须是合法的表达式

    std::map<std::string, int> var;     // 相当于Interpreter模式中的Context

    var["a"] = 90;
    var["b"] = 20;
    var["c"] = 40;

    Calculator cal(exp_str);

    std::cout << "result: " << exp_str << " = " << cal.run(var) << std::endl;

    return 0;
}