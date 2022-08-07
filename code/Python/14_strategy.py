# -*- coding: utf-8 -*-
#  @file        - 14_strategy.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 策略模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class StrategyCrabCooking(metaclass=abc.ABCMeta):
    """ 抽象策略类：大闸蟹加工类
    """
    @abc.abstractmethod
    def cooking_method(self):
        pass

class ConcreteStrategySteamedCrabs(StrategyCrabCooking):
    """ 具体策略类:清蒸大螃蟹
    """
    def cooking_method(self):
        print("清蒸大螃蟹.")

class ConcreteStrategyBraisedCrabs(StrategyCrabCooking):
    """ 具体策略类:红烧大螃蟹
    """
    def cooking_method(self):
        print("红烧大螃蟹.")

class ContextKitchen(StrategyCrabCooking):
    """ 环境类
    """
    def __init__(self) -> None:
        self._strategy = None

    def set_strategy(self, strategy):
        self._strategy = strategy

    def get_strategy(self):
        return self._strategy
    
    def cooking_method(self):
        if self._strategy is not None:
            self._strategy.cooking_method()
        else :
            print("未选择，重新选择!")

def main():
    context_kitchen = ContextKitchen()
    context_kitchen.cooking_method()

    context_kitchen.set_strategy(ConcreteStrategySteamedCrabs())
    context_kitchen.cooking_method()

    context_kitchen.set_strategy(ConcreteStrategyBraisedCrabs())
    context_kitchen.cooking_method()



if __name__ == "__main__":
    main()