/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 中介者模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "mediator.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

int main()
{
    Media* md = new EstateMedia();
    Customer* member1 = new Seller("张三(卖方)");
    Customer* member2 = new Buyer("李四(买方)");
    md->registers(member1); //客户注册
    md->registers(member2);
    member1->send("我有一套房子.");
    member2->send("在哪儿?");
    member1->send("珠海.");
    member2->send("多少钱?");
    member2->send("多大?");


    return 0;
}