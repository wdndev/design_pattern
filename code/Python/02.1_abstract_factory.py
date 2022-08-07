# -*- coding: utf-8 -*-
#  @file        - 02.1_abstract_factory.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 抽象工厂
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class AbstractFactory(metaclass=abc.ABCMeta):
    """
    抽象工厂类：提供产品的接口，调用者通过它访问具体工厂创建产品
    """
    
    @abc.abstractmethod
    def create_product_a(self):
        """ 创建A产品
        """
        pass

    @abc.abstractmethod
    def create_product_b(self):
        """ 创建B产品
        """

class ConcreteFactory1(AbstractFactory):
    """
    具体工厂1，实现抽象工厂中的抽象方法，创建产品
    """
    def create_product_a(self):
        print("Concrete Factory 1, create Concrete Product A1")
        return ConcreteProductA1()

    def create_product_b(self):
        print("Concrete Factory 1, create Concrete Product B1")
        return ConcreteProductB1()

class ConcreteFactory2(AbstractFactory):
    """
    具体工厂2，实现抽象工厂中的抽象方法，创建产品
    """

    def create_product_a(self):
        print("Concrete Factory 2, create Concrete Product A2")
        return ConcreteProductA2()

    def create_product_b(self):
        print("Concrete Factory 2, create Concrete Product B2")
        return ConcreteProductB2()
    
class AbstractProductA(metaclass=abc.ABCMeta):
    """
    抽象产品：定义产品的规范，描述产品的主要特性
    """

    @abc.abstractmethod
    def interface_a(self):
        pass

class ConcreteProductA1(AbstractProductA):
    """
    具体产品1：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface_a(self):
        print("Concrete Product A1")

class ConcreteProductA2(AbstractProductA):
    """
    具体产品2：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface_a(self):
        print("Concrete Product A2")

class AbstractProductB(metaclass=abc.ABCMeta):
    """
    抽象产品：定义产品的规范，描述产品的主要特性
    """

    @abc.abstractmethod
    def interface_b(self):
        pass

class ConcreteProductB1(AbstractProductB):
    """
    具体产品1：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface_b(self):
        print("Concrete Product B1")

class ConcreteProductB2(AbstractProductB):
    """
    具体产品2：实现抽象产品所定义的接口，由具体工厂来创建
    """

    def interface_b(self):
        print("Concrete Product B2")

def main():
    for factory in (ConcreteFactory1(), ConcreteFactory2()):
        product_a = factory.create_product_a()
        product_b = factory.create_product_b()
        product_a.interface_a()
        product_b.interface_b()

if __name__ == "__main__":
    main()   
