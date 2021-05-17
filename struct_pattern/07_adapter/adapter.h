/**
 * @file        - adapter.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 适配器模式声明
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */


#pragma once

#include <iostream>
#include <string>
#include <memory>

// 目标：发动机
class TargetMotor
{
public:
    virtual ~TargetMotor() {}
    virtual void drive() = 0;
};

// 适配者1：电能发动机
class ElectricMotorAdatee
{
public:
    void electric_drive()
    {
        std::cout << "电能发动机驱动汽车！" << std::endl;
    }
};

// 适配者2：光能发动机
class OpticalMotorAdatee
{
public:
    void optical_drive()
    {
        std::cout << "光能发动机驱动汽车！" << std::endl;
    }
};

// 电能适配器
class ElectricAdapter : public TargetMotor
{
public:
    ElectricAdapter()
    {
        emotor = std::make_shared<ElectricMotorAdatee>();
    }

    void drive()
    {
        emotor->electric_drive();
    }
private:
    std::shared_ptr<ElectricMotorAdatee> emotor;
};

// 光能适配器
class OpticalAdapter : public TargetMotor
{
public:
    OpticalAdapter()
    {
        omotor = std::make_shared<OpticalMotorAdatee>();
    }

    void drive()
    {
        omotor->optical_drive();
    }
private:
    std::shared_ptr<OpticalMotorAdatee> omotor;
};
