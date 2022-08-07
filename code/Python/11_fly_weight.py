# -*- coding: utf-8 -*-
#  @file        - 11_fly_weight.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 享元模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class UnSharedConcreteFlyWeight:
    """ 非享元角色：是不可以共享的外部状态，它以参数的形式注入具体享元的相关方法中。
    """
    def __init__(self, info) -> None:
        self._info = info
    
    def get_info(self):
        return self._info
    
    def set_info(self, info):
        self._info = info

class AbstractFlyWeight(metaclass=abc.ABCMeta):
    """ 抽象享元角色：是所有的具体享元类的基类，为具体享元规范需要实现的公共接口，
                     非享元的外部状态以参数的形式通过方法传入。
    """
    
    @abc.abstractmethod
    def operation(state):
        pass

class ConcreteFlyWeight(AbstractFlyWeight):
    """ 具体享元角色：实现抽象享元角色中所规定的接口。
    """
    def __init__(self, key) -> None:
        super().__init__()
        self._key = key
        print("具体享元 {} 被创建 ! ".format(self._key))

    def operation(self, state):
        print("具体享元 {} 被调用 ! ".format(self._key))
        print("非享元信息是: {}".format(state.get_info()))

class FlyWeightFactory:
    """享元工厂：负责创建和管理享元角色。当客户对象请求一个享元对象时，
                享元工厂检査系统中是否存在符合要求的享元对象，
                如果存在则提供给客户；如果不存在的话，则创建一个新的享元对象
    """
    def __init__(self) -> None:
        self._fly_weight = dict()
    
    def get_fly_weight(self, key):
        fly_weight = self._fly_weight.get(key, -1)

        if fly_weight == -1:
            fly_weight = ConcreteFlyWeight(key)
            self._fly_weight[key] = fly_weight
        else :
            print("具体享元 {} 已经存在，被成功获取!".format(key))

        return fly_weight

def main():
    fly_weight_factory = FlyWeightFactory()
    f01 = fly_weight_factory.get_fly_weight("a")
    f02 = fly_weight_factory.get_fly_weight("a")
    f03 = fly_weight_factory.get_fly_weight("a")
    f11 = fly_weight_factory.get_fly_weight("b")
    f12 = fly_weight_factory.get_fly_weight("b")

    f01.operation(UnSharedConcreteFlyWeight("第 1 次调用a "))
    f02.operation(UnSharedConcreteFlyWeight("第 2 次调用a "))
    f03.operation(UnSharedConcreteFlyWeight("第 3 次调用a "))
    f11.operation(UnSharedConcreteFlyWeight("第 1 次调用b "))
    f12.operation(UnSharedConcreteFlyWeight("第 2 次调用b "))


if __name__ == "__main__":
    main()