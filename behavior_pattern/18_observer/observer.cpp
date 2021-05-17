/**
 * @file        - observer.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 观察者模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "observer.h"

// 抽象目标类：汇率
void Rate::add(Company* company)
{
    m_companys.push_back(company);
}

void Rate::remove(Company* company)
{
    m_companys.remove(company);
}

// 具体目标：人民币汇率
void RMBRate::change(int number)
{
    for (auto obs : m_companys)
    {
        obs->response(number);
    }
}

// 具体观察者1：进口公司
void ImportCompany::response(int number)
{
    if (number > 0)
    {
        std::cout << "人民币汇率升值 "+ std::to_string(number)+" 个基点，降低了进口产品成本，提升了进口公司利润率." << std::endl;
    }
    else
    {
        std::cout << "人民币汇率贬值 "+ std::to_string(number)+" 个基点，提升了进口产品成本，降低了进口公司利润率." << std::endl;
    }
}

// 具体观察者2：出口公司
void ExportCompany::response(int number)
{
    if (number > 0)
    {
        std::cout << "人民币汇率升值 "+ std::to_string(number)+" 个基点，降低了出口产品收入，降低了出口公司的销售利润率." << std::endl;
    }
    else
    {
        std::cout << "人民币汇率贬值 "+ std::to_string(number)+" 个基点，提升了出口产品收入，提升了出口公司的销售利润率." << std::endl;
    }
}
