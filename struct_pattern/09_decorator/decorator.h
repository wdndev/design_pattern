/**
 * @file        - decorator.h
 * @author      - wdn (you@domain.com)
 * @brief       - 装饰模式声明
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

// 抽象构建角色：莫莉卡
class Morrigan
{
public:
    using Ptr = std::shared_ptr<Morrigan>;

    virtual void display() = 0;
    void set_image(std::string t)
    {
        this->t = t;
    }

    std::string get_image()
    {
        return this->t;
    }

private:
    std::string t;
};

// 具体构建角色：原身
class Original : public Morrigan
{
public:
    using Ptr = std::shared_ptr<Original>;
    Original()
    {
        this->set_image( "原身!!!");
    }

    void display()
    {
        std::cout << get_image() << std::endl;
    }
};

// 抽象装饰角色：变形
class Changer : public Morrigan
{
public:
    Morrigan::Ptr m;
    Changer(Morrigan::Ptr m)
    {
        this->m = m;
    }
    void display()
    {
        m->display();
    }
};

// 具体装饰角色：女妖
class Succubus : public Changer
{
public:
    Succubus(Morrigan::Ptr m) : Changer(m)
    {
    }

    void set_changer()
    {
        m->set_image("女妖!!!");
    }

    void display()
    {
        set_changer();
        m->display();
    }
};

// 具体装饰角色：少女
class Girl : public Changer
{
public:
    Girl(Morrigan::Ptr m) : Changer(m)
    {
    }

    void set_changer()
    {
        m->set_image("少女!!!");
    }

    void display()
    {
        set_changer();
        m->display();
    }
};
