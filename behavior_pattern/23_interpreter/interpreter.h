/**
 * @file        - interpreter.h
 * @author      - wdn (you@domain.com)
 * @brief       - 解释器模式声明
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
#include <map>

// 抽象表达类
class IExpression
{
public:
    // 解析公式和数值，其中var中key是公式中的参数，value值是具体的数字
    virtual int interpreter(std::map<std::string, int>& var) = 0;

    virtual ~IExpression() {};
};

// 变量解析器（终结符表达式类）
class VarExpression : public IExpression
{
public:
    VarExpression(std::string key) : m_key(key) {}

    // 从map中取出变量的值
    int interpreter(std::map<std::string, int>& var) override
    {
        return var[m_key];
    }
private:
    std::string m_key;
};

// 抽象运算符号解析器
class SymbolExpression : public IExpression
{
public:
    SymbolExpression(IExpression* left, IExpression* right) : m_left(left), m_right(right){}

    IExpression* get_left()
    {
        return m_left;
    }

    IExpression* get_right()
    {
        return m_right;
    }

protected:
    IExpression* m_left;
    IExpression* m_right;
};

// 加法运算解释器
class AddExpression : public SymbolExpression
{
public:
    AddExpression(IExpression* left, IExpression* right) : SymbolExpression(left, right)
    {
    }

    int interpreter(std::map<std::string, int>& var) override
    {
        return m_left->interpreter(var) + m_right->interpreter(var);
    }
};

// 减法运算解释器
class SubExpression : public SymbolExpression
{
public:
    SubExpression(IExpression* left, IExpression* right) : SymbolExpression(left, right)
    {
    }

    int interpreter(std::map<std::string, int>& var) override
    {
        return m_left->interpreter(var) - m_right->interpreter(var);
    }
};

// 解析器封装
class Calculator
{
public:
    Calculator(std::string exp_str);
    ~Calculator();

    void del_tree(IExpression* expression);

    int run(std::map<std::string, int>& var);

private:
    IExpression* m_expression;
};



