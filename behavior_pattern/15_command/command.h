/**
 * @file        - command.h
 * @author      - wdn (you@domain.com)
 * @brief       - 命令模式声明
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

// 接收者：肠粉厨师
class ChangFenChef
{
public:
    using Ptr = std::shared_ptr<ChangFenChef>;

    void cooking()
    {
        std::cout << " 做肠粉.  " << std::endl;
    }
};

// 接收者：混沌厨师
class HunTunChef
{
public:
    using Ptr = std::shared_ptr<HunTunChef>;

    void cooking()
    {
        std::cout << " 做混沌.  " << std::endl;
    }
};

// 接收者：河粉厨师
class HeFenChef
{
public:
    using Ptr = std::shared_ptr<HeFenChef>;

    void cooking()
    {
        std::cout << " 做河粉.  " << std::endl;
    }
};

// 抽象命令：早餐
class Breakfast
{
public:
    virtual void cooking() = 0;

    virtual ~Breakfast() {}
};

// 具体命令： 肠粉
class ChangFen : public Breakfast
{
public:
    ChangFen()
    {
        receiver = std::make_shared<ChangFenChef>();
    }

    ~ChangFen()
    {
        std::cout << " ChangFen xigou ! " << std::endl;
    }

    void cooking()
    {
        receiver->cooking();
    }
private:
    ChangFenChef::Ptr receiver;
};

// 具体命令： 混沌
class HunTun : public Breakfast
{
public:
    HunTun()
    {
        receiver = std::make_shared<HunTunChef>();
    }

    ~HunTun()
    {
        std::cout << " HunTun xigou !" << std::endl;
    }

    void cooking()
    {
        receiver->cooking();
    }
private:
    HunTunChef::Ptr receiver;
};

// 具体命令： 河粉
class HeFen : public Breakfast
{
public:
    HeFen()
    {
        receiver = std::make_shared<HeFenChef>();
    }

    ~HeFen()
    {
        std::cout << " HeFen xigou !" << std::endl;
    }

    void cooking()
    {
        receiver->cooking();
    }
private:
    HeFenChef::Ptr receiver;
};

// 调用者：服务员
class Waiter
{
public:
    ~Waiter()
    {
        std::cout << " Waiter xigou ! " << std::endl;
    }
    void set_changfen(Breakfast* f)
    {
        changfen = f;
    }

    void set_huntun(Breakfast* f)
    {
        huntun = f;
    }

    void set_hefen(Breakfast* f)
    {
        hefen = f;
    }

    void choose_changfen()
    {
        changfen->cooking();
    }

    void choose_huntun()
    {
        huntun->cooking();
    }

    void choose_hefen()
    {
        hefen->cooking();
    }

private:
    Breakfast* changfen;
    Breakfast* huntun;
    Breakfast* hefen;
};
