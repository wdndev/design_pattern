/**
 * @file        - 17_iterator.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 迭代器模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

/**
 * 抽象迭代器（Iterator）角色：定义访问和遍历聚合元素的接口，
 *      通常包含 hasNext()、first()、next() 等方法。
*/
class Iterator
{
public:
    virtual ~Iterator() {}

    virtual std::string first() = 0;
    virtual std::string next() = 0;
    virtual bool has_next() = 0;
    virtual std::string current_item() = 0; 
};

/**
 * 抽象聚合（Aggregate）角色：定义存储、添加、删除聚合对象以及创建迭代器对象的接口
*/
class Aggregate
{
public:
    virtual Iterator* create_iterator() = 0;
    virtual void add(std::string s) = 0;
    virtual std::string remove(int index) = 0;
    virtual int count() = 0; 
};

/**
 * 具体迭代器（Concretelterator）角色：实现抽象迭代器接口中所定义的方法，
 *      完成对聚合对象的遍历，记录遍历的当前位置。
*/
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* aggregate) : m_index(0), m_aggregate(aggregate) { }
    
    std::string first() override
    {
        return m_aggregate->remove(0);
    }
    std::string next() override
    {
        std::string str;
        m_index++;
        if(m_index < m_aggregate->count())
            str = m_aggregate->remove(m_index);
        return str;
    }
    bool has_next() override
    {
        return (m_index >= m_aggregate->count());
    }
    std::string current_item() override
    {
        return m_aggregate->remove(m_index);
    }

private:
    Aggregate* m_aggregate;
    int m_index;
};

/**
 * 具体聚合（ConcreteAggregate）角色：实现抽象聚合类，返回一个具体迭代器的实例。
*/
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate() : m_iterator(nullptr)
    {
        m_items.clear();
    }

    ~ConcreteAggregate()
    {
        if(m_iterator)
            delete m_iterator;
    }

    Iterator* create_iterator() override
    {
        if(m_iterator == NULL)
        {
            m_iterator = new ConcreteIterator(this);
        }
        return m_iterator;
    }

    void add(std::string s) override
    {
        m_items.push_back(s);
    }
    std::string remove(int index) override
    {
        std::string str;
        if(index < count())
        {
            str = m_items[index];
        }
        return str;
    }
    int count() override
    {
        return m_items.size();
    }
private:
    std::vector<std::string> m_items;
    Iterator* m_iterator;
};


int main()
{
    Aggregate* ca = new ConcreteAggregate();
    ca->add("hello");
    ca->add("world");

    Iterator* it = new ConcreteIterator(ca);
    while (!it->has_next())
    {
        std::cout << it->current_item() << std::endl;
        it->next();
    }

    delete it;
    delete ca;
    return 0;
}

