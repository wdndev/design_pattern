# -*- coding: utf-8 -*-
#  @file        - 12_observer.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 观察者模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 当“人民币汇率”升值时，进口公司的进口产品成本降低且利润率提升，出口公司的出口产品收入降低且利润率降低；
# 当“人民币汇率”贬值时，进口公司的进口产品成本提升且利润率降低，出口公司的出口产品收入提升且利润率提升。

import abc

class AbstractSubjectRate(metaclass=abc.ABCMeta):
    """ 抽象主题：汇率
    """
    def __init__(self) -> None:
        self._observers = set()

    def add(self, observer):
        self._observers.add(observer)
    
    def remove(self, observer):
        self._observers.discard(observer)

    @abc.abstractmethod
    def change(self, msg):
        pass

class ConcreteSubjectRMBRate(AbstractSubjectRate):
    """ 具体主题：人民币汇率
    """

    def change(self, msg):
        for observer in self._observers:
            observer.response(msg)

class AbstractObserverCompany(metaclass=abc.ABCMeta):
    """ 抽象观察者：公司
    """

    @abc.abstractmethod
    def response(self, msg):
        pass

class ConcreteObserverImportCompany(AbstractObserverCompany):
    """ 具体观察者：进口公司
    """

    def response(self, msg):
        if msg > 0 :
            print("人民币汇率升值 {} 个基点，降低了进口产品成本，提升了进口公司利润率.".format(msg))
        else :
            print("人民币汇率贬值 {} 个基点，提升了进口产品成本，降低了进口公司利润率.".format(msg))

class ConcreteObserverExportCompany(AbstractObserverCompany):
    """ 具体观察者：出口公司
    """

    def response(self, msg):
        if msg > 0 :
            print("人民币汇率升值 {} 个基点，降低了出口产品收入，降低了出口公司的销售利润率.".format(msg))
        else :
            print("人民币汇率贬值 {} 个基点，提升了出口产品收入，提升了出口公司的销售利润率.".format(msg))

def main():
    rate = ConcreteSubjectRMBRate()
    obs1 = ConcreteObserverImportCompany()
    obs2 = ConcreteObserverExportCompany()

    rate.add(obs1)
    rate.add(obs2)

    rate.change(10)
    rate.change(-9)


if __name__ == "__main__":
    main()