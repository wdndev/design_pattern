/**
 * @file        - 08_adapter.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 适配器模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 新能源汽车的发动机有电能发动机（Electric Motor）和光能发动机（Optical Motor）等，
// 各种发动机的驱动方法不同，客户端希望用统一的发动机驱动方法 drive() 访问这两种发动机，
// 所以必须定义一个统一的目标接口 Motor，
// 然后再定义电能适配器（Electric Adapter）和光能适配器（Optical Adapter）去适配这两种发动机。

#include <iostream>
#include <string>
#include <memory>

/**
 * 目标：发动机
*/
class TargetMotor
{
public:
    virtual ~TargetMotor() {}
    virtual void drive() = 0;
};

/**
 * 适配者1：电能发动机
*/
class AdateeElectricMotor
{
public:
    void electric_drive()
    {
        std::cout << "Electric Motor" << std::endl;
    }
};

/**
 * 适配者2：光能发动机
*/
class AdateeOpticalMotor
{
public:
    void optical_drive()
    {
        std::cout << "Optical Motor" << std::endl;
    }
};

/**
 * 电能适配器
*/
class AdapterElectric : public TargetMotor
{
public:
    AdapterElectric() : TargetMotor(), 
        m_emotor(std::make_shared<AdateeElectricMotor>()) {}

    void drive() override
    {
        m_emotor->electric_drive();
    }

private:
    std::shared_ptr<AdateeElectricMotor> m_emotor;
};

/**
 * 光能适配器
*/
class AdapterOptical : public TargetMotor
{
public:
    AdapterOptical() : TargetMotor(), 
        m_omotor(std::make_shared<AdateeOpticalMotor>()) {}

    void drive() override
    {
        m_omotor->optical_drive();
    }

private:
    std::shared_ptr<AdateeOpticalMotor> m_omotor;
};

int main()
{
    // 电能测试
    TargetMotor* emotor = new AdapterElectric();
    emotor->drive();
    delete emotor;

    // 光能测试
    TargetMotor* omotor = new AdapterOptical();
    omotor->drive();
    delete omotor;

    return 0;
}
