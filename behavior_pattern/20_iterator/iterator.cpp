/**
 * @file        - iterator.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 迭代器模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "iterator.h"

ConcreteIterator::ConcreteIterator(Aggregate* aggregate)
{
    m_index = 0;
    m_aggregate = aggregate;
}

std::string ConcreteIterator::first()
{
    return m_aggregate->pop(0);
}

std::string ConcreteIterator::next()
{
    std::string str;
    m_index++;
    if(m_index < m_aggregate->count())
    {
        str = m_aggregate->pop(m_index);
    }
    return str;
}

bool ConcreteIterator::is_done()
{
    return (m_index >= m_aggregate->count());
}

std::string ConcreteIterator::current_item()
{
    return m_aggregate->pop(m_index);
}

ConcreteAggregate::ConcreteAggregate()
{
    m_iterator = nullptr;
    m_items.clear();
}

ConcreteAggregate::~ConcreteAggregate()
{
    if(m_iterator)
    {
        delete m_iterator;
        m_iterator = nullptr;
    }
}

Iterator* ConcreteAggregate::create_iterator()
{
    if(m_iterator == NULL)
    {
        m_iterator = new ConcreteIterator(this);
    }
    return m_iterator;
}

int ConcreteAggregate::count()
{
    return m_items.size();
}

void ConcreteAggregate::push(std::string s)
{
    m_items.push_back(s);
}

std::string ConcreteAggregate::pop(int index)
{
    std::string str;
    if(index < count())
    {
        str = m_items[index];
    }
    return str;
}

