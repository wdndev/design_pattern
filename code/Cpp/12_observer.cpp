/**
 * @file        - 12_observer.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 观察者模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 当“人民币汇率”升值时，进口公司的进口产品成本降低且利润率提升，出口公司的出口产品收入降低且利润率降低；
// 当“人民币汇率”贬值时，进口公司的进口产品成本提升且利润率降低，出口公司的出口产品收入提升且利润率提升。

#include <iostream>
#include <string>
#include <memory>
#include <list>

// 前置声明
class AbstractObserverCompany;


/**
 * 抽象主题：汇率
*/
class AbstractSubjectRate
{
public:
    void add(AbstractObserverCompany* company)
    {
        m_companys.push_back(company);
    }

    void remove(AbstractObserverCompany* company)
    {
        m_companys.remove(company);
    }

    virtual void change(int number) = 0;

protected:
    std::list<AbstractObserverCompany*> m_companys;
};

/**
 * 抽象观察者：公司
*/
class AbstractObserverCompany
{
public:
    virtual void response(int number) = 0;
};

/**
 * 具体主题：人民币汇率
*/
class ConcreteSubjectRMBRate : public AbstractSubjectRate
{
public:
    void change(int number) override
    {
        for(auto obs : m_companys)
        {
            obs->response(number);
        }
    }
};



/**
 * 具体观察者：进口公司
*/
class ConcreteObserverImportCompany : public AbstractObserverCompany
{
public:
    void response(int number) override
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
};

/**
 * 具体观察者：出口公司
*/
class ConcreteObserverExportCompany : public AbstractObserverCompany
{
public:
    void response(int number) override
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
};

int main()
{
    AbstractSubjectRate* rate = new ConcreteSubjectRMBRate();
    AbstractObserverCompany* obs1 = new ConcreteObserverImportCompany();
    AbstractObserverCompany* obs2 = new ConcreteObserverExportCompany();

    rate->add(obs1);
    rate->add(obs2);

    rate->change(10);
    rate->change(-9);

    delete rate;
    delete obs1;
    delete obs2;

    return 0;
}