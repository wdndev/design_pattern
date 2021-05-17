/**
 * @file        - singleton.h
 * @author      - wdn (you@domain.com)
 * @brief       - 单例模式头文件
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#pragma once

#include <utility>
#include <iostream>
#include <string>

template <class T>
class SingleTon
{
public:
    static T& get_instance()
    {
        static T ins;
        return ins;
    }

    SingleTon(const SingleTon &) = delete;
    virtual ~SingleTon() {}

protected:
    SingleTon() {}
};

class Apple : public SingleTon<Apple>
{
public:
    void show()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    ~Apple()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

protected:
    Apple() {}
private:
    friend SingleTon<Apple>;
};

class Orange : public SingleTon<Orange>
{
public:
    void show()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    ~Orange()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

protected:
    Orange() {}
private:
    friend SingleTon<Orange>;
};