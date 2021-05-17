/**
 * @file        - main.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 备忘录模式demo
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "memento.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

void show_girl(std::string name)
{
    std::cout << "[sys] 你选择了 " << name << " ." << std::endl;
    std::cout << "================" << std::endl;
}

int main()
{
    You* you = new You();
    GirlStack* girls = new GirlStack();
    you->set_wife("NULL");

    int name_idx;
    int is_true;
    bool flag = true;
    std::string name;
    do
    {
        do
        {    
            std::cout << "四大美女有“沉鱼落雁之容、闭月羞花之貌”，您选择谁? \n"
                      << "[sys] [1] 西施 \n" 
                      << "[sys] [2] 貂蝉 \n" 
                      << "[sys] [3] 王昭君 \n" 
                      << "[sys] [4] 杨玉环 \n" ;
                    
            std::cout << "请选择： ";
            std::cin >> name_idx ;
        }while(name_idx != 1 && name_idx != 2 && name_idx != 3 && name_idx != 4);
        do
        {    
            std::cout << "[sys] [1] 确定 \n" 
                      << "[sys] [0] 返回 \n" 
                      << "[sys] [2] 退出 \n" ;
            std::cout << "请确定： ";
            std::cin >> is_true;
        }while(is_true != 5 && is_true != 6 && is_true != 7);

        switch (name_idx)
        {
        case 1:
            name = "西施";
            break;
        case 2:
            name = "貂蝉";
            break;
        case 3:
            name = "王昭君";
            break;
        case 4:
            name = "杨玉环";
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;    
        }

        if(is_true == 1)
        {
            you->set_wife(name);
            if(girls->push(you->create_memento()))
            {
                show_girl(name);
            }
        }
        else if(is_true == 0)
        {
            you->restore_momento(girls->pop());
            show_girl(you->get_wife());
        }
        else if(is_true == 2)
            flag = false;
    }while(flag);

    return 0;
}