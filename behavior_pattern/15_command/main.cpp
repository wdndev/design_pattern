/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 命令模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "command.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
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