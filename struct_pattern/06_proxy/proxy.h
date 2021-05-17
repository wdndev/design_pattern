/**
 * @file        - proxy.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 代理模式声明
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

// 抽象主题
class SubjectSpecialty
{
public:
    virtual ~SubjectSpecialty() {}
    virtual void display() = 0;
};

// 真实主题
class RealSubjectSpecialty : public SubjectSpecialty
{
public:
    using Ptr = std::shared_ptr<RealSubjectSpecialty>;

    RealSubjectSpecialty()
    {
        std::cout << "特产 构造！ " << std::endl;
    }
    ~RealSubjectSpecialty()
    {
        std::cout << "特产 析构！ " << std::endl;
    }
    void display()
    {
        std::cout << "特产" << std::endl;
    }
};

class Proxy : public SubjectSpecialty
{
public:
    Proxy()
    {
        std::cout << "代理 构造！" << std::endl;
    }
    ~Proxy()
    {
        std::cout << "代理 析构" << std::endl;
    }
    void pre_request()
    {
        std::cout << "pre process!" <<  std::endl;
    }

    void post_request()
    {
        std::cout << "proxy end!" <<  std::endl;
    }

    void display()
    {
        this->pre_request();
        real_subject_specialty->display();
        this->post_request();
        
    }

private:
    //RealSubjectSpecialty* real_subject_specialty = new RealSubjectSpecialty();
    //std::shared_ptr<RealSubjectSpecialty> real_subject_specialty = std::make_shared<RealSubjectSpecialty>();  //new RealSubjectSpecialty());
    RealSubjectSpecialty::Ptr real_subject_specialty = std::make_shared<RealSubjectSpecialty>();
};
