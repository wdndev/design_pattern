/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 工厂模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "factory.h"

int main()
{
    AbstractFactory* fac_card = new ConcreteFactoryCard;
    AbstractProduct* pro = fac_card->create("tao");
    AbstractProduct* pro2 = fac_card->create("tao2");
    pro->use();
    pro2->use();

    AbstractFactory* fac_phone = new ConcreteFactoryPhone;
    AbstractProduct* pro3 = fac_phone->create("tao3");
    AbstractProduct* pro4 = fac_phone->create("tao4");
    pro3->use();
    pro4->use();

    delete pro;
    delete fac_card;
    delete pro2;
    delete pro3;
    delete fac_phone;
    delete pro4;

    return 0;
}