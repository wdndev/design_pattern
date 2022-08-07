/**
 * @file        - 20_command.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 命令模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 客户去餐馆可选择的早餐有肠粉、河粉和馄饨等，
// 客户可向服务员选择以上早餐中的若干种，
// 服务员将客户的请求交给相关的厨师去做。
// 这里的点早餐相当于“命令”，服务员相当于“调用者”，
// 厨师相当于“接收者”，所以用命令模式实现比较合适。

#include <iostream>
#include <string>
#include <memory>

/**
 * 接受者：肠粉厨师
*/
class ChangFenChef
{
public:
    using Ptr = std::shared_ptr<ChangFenChef>;

    void cooking()
    {
        std::cout << " 做肠粉 " << std::endl;
    }
};

/**
 * 接受者：混沌厨师
*/
class HunTunChef
{
public:
    using Ptr = std::shared_ptr<HunTunChef>;

    void cooking()
    {
        std::cout << " 做馄饨 " << std::endl;
    }
};

/**
 * 接受者：河粉厨师
*/
class HeFenChef
{
public:
    using Ptr = std::shared_ptr<HeFenChef>;

    void cooking()
    {
        std::cout << " 做河粉 " << std::endl;
    }
};

/**
 * 抽象命令类：早餐
*/
class Breakfast
{
public:
    virtual void cooking() = 0;
    virtual ~Breakfast() {}
};

/**
 * 具体命令：肠粉
*/
class ChangFen : public Breakfast
{
public:
    ChangFen() : m_recv(std::make_shared<ChangFenChef>()) {}
    ~ChangFen() 
    {
        std::cout << " ChangFen xigou ! " << std::endl;
    }
    void cooking() override
    {
        m_recv->cooking();
    }
private:
    ChangFenChef::Ptr m_recv;
};

/**
 * 具体命令：馄饨
*/
class HunTun : public Breakfast
{
public:
    HunTun() : m_recv(std::make_shared<HunTunChef>()) {}
    ~HunTun() 
    {
        std::cout << " HunTun xigou ! " << std::endl;
    }
    void cooking() override
    {
        m_recv->cooking();
    }
private:
    HunTunChef::Ptr m_recv;
};

/**
 * 具体命令：河粉
*/
class HeFen : public Breakfast
{
public:
    HeFen() : m_recv(std::make_shared<HeFenChef>()) {}
    ~HeFen() 
    {
        std::cout << " HeFen xigou ! " << std::endl;
    }
    void cooking() override
    {
        m_recv->cooking();
    }
private:
    HeFenChef::Ptr m_recv;
};

/**
 * 调用者：服务员
*/
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

int main()
{
    Breakfast* food_changfen = new ChangFen();
    Breakfast* food_huntun = new HunTun();
    Breakfast* food_hefen = new HeFen();
    Waiter* waiter = new Waiter();

    waiter->set_changfen(food_changfen);    // 设置肠粉菜单
    waiter->set_huntun(food_huntun);        // 设置混沌菜单
    waiter->set_hefen(food_hefen);          // 设置河粉菜单

    waiter->choose_changfen();              // 选择肠粉
    waiter->choose_huntun();                // 选择馄饨
    waiter->choose_hefen();                 // 选择河粉

    delete food_changfen;
    delete food_huntun;
    delete food_hefen;
    delete waiter;

    return 0;
}

