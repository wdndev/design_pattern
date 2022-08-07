/**
 * @file        - 19_memento.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 备忘录模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 假如有西施、王昭君、貂蝉、杨玉环四大美女同你相亲，
// 你可以选择其中一位作为你的爱人；当然，如果你对前面的选择不满意，
// 还可以重新选择，但希望你不要太花心；
// 这个游戏提供后悔功能，用“备忘录模式”设计比较合适。


#include <iostream>
#include <string>
#include <memory>
#include <list>

/**
 * 备忘录：美女
*/
class Girl
{
public:
    using Ptr = std::shared_ptr<Girl>;
    Girl(const std::string& name) : m_name(name) { }

    void set_name(const std::string& name)
    {
        m_name = name;
    }

    std::string get_name()
    {
        return m_name;
    }

private:
    std::string m_name;
};

/**
 * 发起人：你
*/
class You
{
public:
    void set_wife_name(const std::string& name)
    {
        m_wife_name = name;
    }

    std::string get_wife_name()
    {
        return m_wife_name;
    }

    Girl::Ptr create_memento()
    {
        return std::make_shared<Girl>(m_wife_name);
    }

    void restore_momento(Girl::Ptr girl)
    {
        set_wife_name(girl->get_name());
    }

private:
    std::string m_wife_name;
};

/**
 * 管理者：美女栈
*/
class GirlStack
{
public:
    GirlStack() : m_top(-1) {}

    bool push(Girl::Ptr girl)
    {
        if(m_top >= 4)
        {
            std::cout << "你太花心了，变来变去的! " << std::endl;
            return false;
        }
        else
        {
            m_girl[++m_top] = girl;
            return true;
        }
    }

    Girl::Ptr pop()
    {
        if(m_top <= 0)
        {
            std::cout << "美女栈空了! " << std::endl;
            return m_girl[0];
        }
        else
        {
            return m_girl[m_top--];
        }
    }
private:
    int m_top;
    Girl::Ptr m_girl[5];
};

// 测试
void show_girl(const std::string& name)
{
    std::cout << "[sys] 你选择了 " << name << " ." << std::endl;
    std::cout << "================" << std::endl;
}

int main()
{
    You* you = new You();
    GirlStack* girls = new GirlStack();
    you->set_wife_name("NULL");

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
        }while(name_idx == 1 || name_idx == 2 || name_idx == 3 || name_idx == 4);
        do
        {    
            std::cout << "[sys] [1] 确定 \n" 
                      << "[sys] [0] 返回 \n" 
                      << "[sys] [2] 退出 \n" ;
            std::cout << "请确定： ";
            std::cin >> is_true;
        }while(is_true == 1 || is_true == 0 || is_true == 2);

        switch (name_idx)
        {
        case 1:
            name = " 西施 ";
            break;
        case 2:
            name = " 貂蝉 ";
            break;
        case 3:
            name = " 王昭君 ";
            break;
        case 4:
            name = " 杨玉环 ";
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
            you->set_wife_name(name);
            if(girls->push(you->create_memento()))
            {
                show_girl(name);
            }
        }
        else if(is_true == 0)
        {
            you->restore_momento(girls->pop());
            show_girl(you->get_wife_name());
        }
        else if(is_true == 2)
            flag = false;
    }while(flag);

    return 0;
}


