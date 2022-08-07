# -*- coding: utf-8 -*-
#  @file        - 05_proxy.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 代理模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc


class AbstractSubject(metaclass=abc.ABCMeta):
    """ 抽象主题
    """

    @abc.abstractmethod
    def display(self):
        pass

class RealSubject(AbstractSubject):
    """ 真实主题
    """
    def display(self):
        print("RealSubject::display()")

class Proxy(AbstractSubject):
    """ 代理类
    """
    def __init__(self, real_subject) -> None:
        self._real_subject = real_subject
    
    def _start_proxy(self):
        print("start proxy")

    def _end_proxy(self):
        print("end proxy")
    
    def display(self):
        self._start_proxy()
        # ...
        self._real_subject.display()
        # ...
        self._end_proxy()

def main():
    real_subject = RealSubject()
    proxy = Proxy(real_subject)
    proxy.display()


if __name__ == "__main__":
    main()