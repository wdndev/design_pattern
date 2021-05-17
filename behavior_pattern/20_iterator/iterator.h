/**
 * @file        - iterator.h
 * @author      - wdn (you@domain.com)
 * @brief       - 迭代器模式声明
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

// 迭代器抽象类
class Iterator
{
public:
    virtual ~Iterator() {}

    virtual std::string first() = 0;
    virtual std::string next() = 0;
    virtual bool is_done() = 0;
    virtual std::string current_item() = 0; 
};

// 聚合抽象类
class Aggregate
{
public:
    virtual Iterator* create_iterator() = 0;
    virtual void push(std::string s) = 0;
    virtual std::string pop(int index) = 0;
    virtual int count() = 0; 
};

// 具体迭代器
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* aggregate);
    
    std::string first() override;
    std::string next() override;
    bool is_done() override;
    std::string current_item() override; 

private:
    Aggregate* m_aggregate;
    int m_index;
};

// 具体聚合类
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate();
    ~ConcreteAggregate();

    Iterator* create_iterator() override;
    void push(std::string s) override;
    std::string pop(int index) override;
    int count() override; 
private:
    std::vector<std::string> m_items;
    Iterator* m_iterator;
};

