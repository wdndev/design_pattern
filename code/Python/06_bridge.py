# -*- coding: utf-8 -*-
#  @file        - 06_bridge.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 桥接模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class ImplementorColor(metaclass=abc.ABCMeta):
    """ 实现化角色：颜色
    """

    @abc.abstractmethod
    def get_color(self):
        pass

class ConcreteImplYellow(ImplementorColor):
    """ 具体实现化角色：黄色
    """

    def get_color(self):
        return "Yellow "

class ConcreteImplRed(ImplementorColor):
    """ 具体实现化角色：红色
    """

    def get_color(self):
        return "Red "

class AbstractBag(metaclass=abc.ABCMeta):
    """ 抽象角色：包
    """
    def __init__(self) -> None:
        self._color = None
    
    def set_color(self, color):
        self._color = color
    
    @abc.abstractmethod
    def get_name(self):
        pass

class ConcreteHandBag(AbstractBag):
    """ 扩展抽象化角色：挎包
    """
    def get_name(self):
        return self._color.get_color() + "HandBag"

class ConcreteWallBag(AbstractBag):
    """ 扩展抽象化角色：钱包
    """
    def get_name(self):
        return self._color.get_color() + "WallBag"

def main():
    red_color = ConcreteImplRed()
    yellow_color = ConcreteImplYellow()
    bag = ConcreteWallBag()
    bag.set_color(red_color)
    print(bag.get_name())
    bag.set_color(yellow_color)
    print(bag.get_name())


if __name__ == "__main__":
    main()
