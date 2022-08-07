# -*- coding: utf-8 -*-
#  @file        - 02_factory_method.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 工厂模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 


import abc

class AbstractFactory(metaclass=abc.ABCMeta):
    """
    抽象工厂类：提供产品的接口，调用者通过它访问具体工厂创建产品
    """
    
    def __init__(self) -> None:
        self.product = self._factory_method()
    
    @abc.abstractmethod
    def _factory_method(self):
        pass

    def some_operation(self):
        self.product.interface()

class ConcreteFactory1(AbstractFactory):
    """
    具体工厂1，实现抽象工厂中的抽象方法，创建产品
    """
    def _factory_method(self):
        print("Concrete Factory 1, create Concrete Product 1")
        return ConcreteProduct1()

class ConcreteFactory2(AbstractFactory):
    """
    具体工厂2，实现抽象工厂中的抽象方法，创建产品
    """

    def _factory_method(self):
        print("Concrete Factory 2, create Concrete Product 2")
        return ConcreteProduct2()
    
class AbstractProduct(metaclass=abc.ABCMeta):
    """
    抽象产品：定义产品的规范，描述产品的主要特性
    """

    @abc.abstractmethod
    def interface(self):
        pass

class ConcreteProduct1(AbstractProduct):
    """
    具体产品1：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface(self):
        print("Concrete Product 1")

class ConcreteProduct2(AbstractProduct):
    """
    具体产品2：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface(self):
        print("Concrete Product 2")

def main():
    concrete_creator = ConcreteFactory1()
    concrete_creator.product.interface()
    concrete_creator.some_operation()

if __name__ == "__main__":
    main()   
