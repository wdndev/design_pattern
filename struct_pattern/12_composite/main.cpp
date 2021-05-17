/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 组合模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "composite.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
int main()
{
    Bags::Ptr big_bag = std::make_shared<Bags>("大袋子: ");
    Bags::Ptr medium_bag = std::make_shared<Bags>("中袋子: ");
    Bags::Ptr small_red_bag = std::make_shared<Bags>("红色小袋子: ");
    Bags::Ptr small_white_bag = std::make_shared<Bags>("白色小袋子: ");
    
    Articles::Ptr sp = std::make_shared<Goods>(" 特产 ", 2, 7.9);
    small_red_bag->add(sp);
    sp = std::make_shared<Goods>(" 地图 ", 1, 9.9);
    small_red_bag->add(sp);

    sp = std::make_shared<Goods>(" 香菇 ", 2, 68);
    small_white_bag->add(sp);
    sp = std::make_shared<Goods>(" 红茶 ", 3, 180);
    small_white_bag->add(sp);
    
    sp = std::make_shared<Goods>(" 景德镇瓷器 ", 1, 380);
    medium_bag->add(sp);
    medium_bag->add(small_red_bag);

    sp = std::make_shared<Goods>(" 李宁牌运动鞋 ", 1, 198);
    big_bag->add(sp);
    big_bag->add(small_white_bag);
    big_bag->add(medium_bag);
    // std::cout << "您选购的商品有: " << std::endl;
    // big_bag->show();
    // big_bag->remove(sp);

    std::cout << "您选购的商品有: " << std::endl;
    big_bag->show();
    std::cout << " 要支付的总价为 : " << big_bag->calculation()  << " RMB." << std::endl;

    return 0;
}