# -*- coding: utf-8 -*-
#  @file        - 09_facade.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 外观模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 


class Subsystem1:
    """ 子系统角色
    """

    def operation1(self):
        print("Method1() of subsystem 01 is called!")



class Subsystem2:
    """ 子系统角色
    """

    def operation2(self):
        print("Method2() of subsystem 02 is called!")


class Subsystem3:
    """ 子系统角色
    """

    def operation3(self):
        print("Method3() of subsystem 03 is called!")


class Facade:
    """ 外观角色
    """

    def __init__(self):
        self._obj1 = Subsystem1()
        self._obj2 = Subsystem2()
        self._obj3 = Subsystem3()

    def operation(self):
        self._obj1.operation1()
        self._obj2.operation2()
        self._obj3.operation3()


def main():
    facade = Facade()
    facade.operation()


if __name__ == "__main__":
    main()