/**
 * @file        - interpreter.cpp
 * @author      - wdn (you@domain.com)
 * @brief       - 解释器模式实现
 * @version     - 0.1
 * @date        - 2021-02-04
 * 
 * @copyright Copyright (c) 2021 
 * 
 */

#include "interpreter.h"

#include <stack>

Calculator::Calculator(std::string exp_str)
{
    m_expression = NULL;

    // 栈，用栈来暂存中间结果
    std::stack<IExpression*> stk_exp;

    IExpression* left = NULL;
    IExpression* right = NULL;

    /*从左到向分析表达式（如:a+b-c)，最终的语法树如下：
    *           -
    *         /   \
    *       +     c
    *     /   \
    *    a     b
    */
    for(unsigned int i = 0; i < exp_str.length(); i++)
    {
        switch (exp_str[i])
        {
        case '+':   // 加法
            //1.先从栈中取出左操作数
            left = stk_exp.top();
            stk_exp.pop();

            //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
            right = new VarExpression(exp_str.substr(++i,1));

            //3.将左右操作数相加，并把结果放入栈中
            stk_exp.push(new AddExpression(left, right));
            break;
        
        case '-':   // 减法
            //1.先从栈中取出左操作数
            left = stk_exp.top();
            stk_exp.pop();

            //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
            right = new VarExpression(exp_str.substr(++i,1));

            //3.将左右操作数相减，并把结果放入栈中
            stk_exp.push(new SubExpression(left, right));
            break;
        
        default:
            // 如果是变量（终结符）：如a+b+c中的a\b\c，
            //则直接生成对应的变量解析器对象
            stk_exp.push(new VarExpression(exp_str.substr(i, 1)));
        }
    }

    // 栈中保存的就是最终语法树的根节点
    if(!stk_exp.empty())
    {
        m_expression = stk_exp.top();
        stk_exp.pop();
    }
}

Calculator::~Calculator()
{
    del_tree(m_expression);
    m_expression = nullptr;
}

void Calculator::del_tree(IExpression* expression)
{
    SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
    // 叶子节点
    if(branch == NULL)
    {
        delete expression;
    }
    else // 分支节点
    {
        // 左子数
        del_tree(branch->get_left());

        // 右子树
        del_tree(branch->get_right());

        // 节点
        delete expression;
    }
    
}

int Calculator::run(std::map<std::string, int>& var)
{
    return (m_expression == NULL) ? 0 : m_expression->interpreter(var);
}
