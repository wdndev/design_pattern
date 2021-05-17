/**
 * @file        - observer.h
 * @author      - wdn (you@domain.com)
 * @brief       - 观察者模式声明
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
#include <vector>
#include <list>

class Company;

// 抽象目标类：汇率
class Rate
{
public:
    void add(Company* company);
    void remove(Company* company);

    virtual void change(int number) = 0;

    std::list<Company* > m_companys;
};

// 具体目标：人民币汇率
class RMBRate : public Rate
{
public:
    void change(int number) override;
};

// 抽象观察者：公司
class Company
{
public:
    virtual void response(int number) = 0;
};

// 具体观察者1：进口公司
class ImportCompany : public Company
{
public:
    void response(int number) override;
};

// 具体观察者2：出口公司
class ExportCompany : public Company
{
public:
    void response(int number) override;
};