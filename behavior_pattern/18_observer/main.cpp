/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 观察者模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "observer.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <windows.h>

int main()
{
    Rate* rate = new RMBRate();
    Company* watcher1 = new ImportCompany();
    Company* watcher2 = new ExportCompany();

    rate->add(watcher1);
    rate->add(watcher2);

    rate->change(10);
    rate->change(-9);

    delete rate;
    delete watcher1;
    delete watcher2;

    return 0;
}