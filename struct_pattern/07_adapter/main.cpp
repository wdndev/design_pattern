/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 适配器模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "adapter.h"


#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    // 客户端测试
    std::cout << "client test!!!" << std::endl;

    // 电能
    std::cout << "---------electric----------" << std::endl;
    TargetMotor* motor = new ElectricAdapter();
    motor->drive();
    delete motor;

    // 光能
    std::cout << "---------optical----------" << std::endl;
    TargetMotor* motor1 = new OpticalAdapter();
    motor1->drive();
    delete motor1;

    return 0;
}