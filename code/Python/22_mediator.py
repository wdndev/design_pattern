# -*- coding: utf-8 -*-
#  @file        - 22_mediator.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 中介模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 房地产交流平台是“房地产中介公司”提供给“卖方客户”与“买方客户”进行信息交流的平台

import abc
from unicodedata import name

class Medium(metaclass=abc.ABCMeta):
    """ 抽象中介者：中介公司
    """
    @abc.abstractmethod
    def registers(self, member):
        """ 客户注册
        """
        pass

    @abc.abstractmethod
    def relay(self, src, dst):
        """ 转发
        """
        pass

class EstateMedium(Medium):
    """ 具体中介者：房地产中介
    """
    def __init__(self) -> None:
        super().__init__()
        self._members = list()

    def registers(self, member):
        if len(self._members) == 0 or self._members.count(member) == 0 :
            self._members.append(member)
            member.set_medium(self)

    def relay(self, src, dst):
        for mem in self._members:
            if mem.get_name() != src:
                mem.receive(src, dst)

class Customer(metaclass=abc.ABCMeta):
    """ 抽象同事类：客户
    """
    def __init__(self, name) -> None:
        self._name = name
        self._medium = None

    def get_name(self):
        return self._name
    def set_medium(self, medium):
        self._medium = medium

    @abc.abstractmethod
    def send(self, addr):
        pass

    @abc.abstractmethod
    def receive(self, src, dst):
        pass

class Seller(Customer):
    """ 具体同事类：卖方
    """
    def __init__(self, name) -> None:
        super().__init__(name)

    def send(self, addr):
        print("send: 我(卖方)说: ", addr)
        self._medium.relay(self._name, addr)

    def receive(self, src, dst):
        print("receive: {} 说： {}".format(src, dst))

class Buyer(Customer):
    """ 具体同事类：买方
    """
    def __init__(self, name) -> None:
        super().__init__(name)

    def send(self, addr):
        print("send: 我(买方)说: ", addr)
        self._medium.relay(self._name, addr)

    def receive(self, src, dst):
        print("receive: {} 说： {}".format(src, dst))


def main():
    medium = EstateMedium()
    seller = Seller("张三(卖方)")
    buyer = Buyer("李四(买方)")

    medium.registers(seller)
    medium.registers(buyer)

    seller.send("我有一套房子.")
    buyer.send("在哪儿?")
    seller.send("珠海.")
    buyer.send("多少钱?")
    buyer.send("多大?")



if __name__ == "__main__":
    main()





