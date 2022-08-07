# -*- coding: utf-8 -*-
#  @file        - 21_interpreter.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 解释器模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 用解释器模式实现四则运算。

import abc

class Expression(metaclass=abc.ABCMeta):
    """ 抽象表达式类
    """
    @abc.abstractmethod
    def interpreter(self, var):
        """ 解析公式和数值，其中var中key是公式中的参数，value值是具体的数字
            var : @dict
        """
        pass

class VarExpression(Expression):
    """ 变量解析器（终结符表达式类）
    """
    def __init__(self, key) -> None:
        self._key = key
    
    def interpreter(self, var):
        return var[self._key]

class SymbolExpression(Expression):
    """ 抽象运算符号解析器
    """
    def __init__(self, left, right) -> None:
        self._left = left
        self._right = right

    def get_left(self):
        return self._left
    
    def get_right(self):
        return self._right

class AddExpression(SymbolExpression):
    """ 加法运算解释器
    """
    def __init__(self, left, right) -> None:
        super().__init__(left, right)

    def interpreter(self, var):
        return self._left.interpreter(var) + self._right.interpreter(var)

class SubExpression(SymbolExpression):
    """ 减法运算解释器
    """
    def __init__(self, left, right) -> None:
        super().__init__(left, right)

    def interpreter(self, var):
        return self._left.interpreter(var) - self._right.interpreter(var)

class Calculator:
    """ 解析器封装
    """
    def __init__(self, expr_str, var) -> None:
        self._expr = None

        # 栈，用栈保存中间结果, 使用列表来模拟栈
        stk_exp = list()
        left = None
        right = None

        # /*从左到向分析表达式（如:a+b-c)，最终的语法树如下：
        #  *           -
        #  *         /   \
        #  *       +     c
        #  *     /   \
        #  *    a     b
        #  */
        i = 0
        while i < len(expr_str) :
            if expr_str[i] == '+':
                left = stk_exp.pop()
                i = i + 1
                right = VarExpression(expr_str[i])
                stk_exp.append(AddExpression(left, right))
                
            elif expr_str[i] == '-':
                left = stk_exp.pop()
                i = i + 1
                right = VarExpression(expr_str[i])
                stk_exp.append(SubExpression(left, right))
            else :
                stk_exp.append(VarExpression(expr_str[i]))
            i += 1
                
        if stk_exp is not None:
            self._expr = stk_exp.pop()

    def run(self, var):
        if self._expr is None :
            return 0
        else :
            return self._expr.interpreter(var)

def main():
    expr_str =  "a+b-c"
    var = dict()

    var["a"] = 90
    var["b"] = 20
    var["c"] = 40

    cal = Calculator(expr_str, var)
    print(cal.run(var))

if __name__ == "__main__":
    main()
