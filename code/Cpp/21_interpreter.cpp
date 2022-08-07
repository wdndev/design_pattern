/**
 * @file        - 21_interpreter.cpp
 * @author      - wdn (dongnian.wang@outlook.com)
 * @brief       - 解释器模式
 * @version     - 0.1
 * @date        - 2022-05-07
 * 
 * @copyright Copyright (c) 2022 
 * 
 */

// 用解释器模式实现四则运算。

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <stack>

/**
 * 抽象表达式类
*/
class Expression
{
public:
    virtual ~Expression() {}

    // 解析公式和数值，其中var中key是公式中的参数，value值是具体的数字
    virtual int interpreter(std::map<std::string, int>& var) = 0;
};

/**
 * 变量解析器（终结符表达式类）
*/
class VarExpression : public Expression
{
public:
    VarExpression(const std::string& key) : m_key(key) {}


    int interpreter(std::map<std::string, int>& var) override
    {
        return var[m_key];
    }
private:
    std::string m_key;
};

/**
 * 抽象运算符号解析器
*/
class SymbolExpression : public Expression
{
public:
    SymbolExpression(Expression* left, Expression* right) : m_left(left), m_right(right) {}

    Expression* get_left()
    {
        return m_left;
    }

    Expression* get_right()
    {
        return m_right;
    }
protected:
    Expression* m_left;
    Expression* m_right;
};

/**
 * 加法运算解释器
*/
class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* left, Expression* right)
        : SymbolExpression(left, right) {}
    
    int interpreter(std::map<std::string, int>& var) override
    {
        return m_left->interpreter(var) + m_right->interpreter(var);
    }
};

/**
 * 减法运算解释器
*/
class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* left, Expression* right)
        : SymbolExpression(left, right) {}
    
    int interpreter(std::map<std::string, int>& var) override
    {
        return m_left->interpreter(var) - m_right->interpreter(var);
    }
};

/**
 * 解析器封装
*/
class Calculator
{
public:
    Calculator(const std::string& exp_str)
    {
        m_expression = NULL;

        // 栈，用栈保存中间结果
        std::stack<Expression*> stk_exp;

        Expression* left = NULL;
        Expression* right = NULL;

        /*从左到向分析表达式（如:a+b-c)，最终的语法树如下：
         *           -
         *         /   \
         *       +     c
         *     /   \
         *    a     b
         */
        std::string var_exp;
        for(unsigned int i = 0; i < exp_str.length(); i++)
        {
            switch (exp_str[i])
            {
            case '+':
                // 1.先从栈中取出左操作数
                left = stk_exp.top();
                stk_exp.pop();

                // 2.从表达式中取出+号后面的有操作数，并生成终结符解析对象
                var_exp = exp_str.substr(++i, 1);
                std::cout << "var_exp: " << var_exp << std::endl;
                right = new VarExpression(var_exp);

                // 3.将左右操作数相加，并把结果放入栈中
                stk_exp.push(new AddExpression(left, right));
                break;

            case '-':
                // 1.先从栈中取出左操作数
                left = stk_exp.top();
                stk_exp.pop();

                // 2.从表达式中取出-号后面的有操作数，并生成终结符解析对象
                right = new VarExpression(exp_str.substr(++i, 1));

                // 3.将左右操作数相减，并把结果放入栈中
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

    ~Calculator()
    {
        del_tree(m_expression);
        m_expression = nullptr;
    }

    void del_tree(Expression* expr)
    {
        SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expr);
        // 叶子节点
        if(branch == NULL)
        {
            delete expr;
        }
        else // 分支节点
        {
            // 左子数
            del_tree(branch->get_left());

            // 右子树
            del_tree(branch->get_right());

            // 节点
            delete expr;
        }
    }

    int run(std::map<std::string, int>& var)
    {
        return (m_expression == NULL) ? 0 : m_expression->interpreter(var);
    }

private:
    Expression* m_expression;
};

int main()
{
    std::string exp_str = "a+b-c";      // 为简化处理，这里必须是合法的表达式

    std::map<std::string, int> var;     // 相当于Interpreter模式中的Context

    var["a"] = 90;
    var["b"] = 20;
    var["c"] = 40;

    Calculator cal(exp_str);

    std::cout << "result: " << exp_str << " = " << cal.run(var) << std::endl;

    return 0;
}











