# -*- coding: utf-8 -*-
#  @file        - 20_command.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 命令模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 客户去餐馆可选择的早餐有肠粉、河粉和馄饨等，
# 客户可向服务员选择以上早餐中的若干种，
# 服务员将客户的请求交给相关的厨师去做。
# 这里的点早餐相当于“命令”，服务员相当于“调用者”，
# 厨师相当于“接收者”，所以用命令模式实现比较合适。

import abc

class ChangFenChef:
    """ 接受者：肠粉厨师
    """
    def cooking(self):
        print("做肠粉")

class HunTunChef:
    """ 接受者：混沌厨师
    """
    def cooking(self):
        print("做馄饨")

class HeFenChef:
    """ 接受者：河粉厨师
    """
    def cooking(self):
        print("做河粉")

class Breakfast(metaclass=abc.ABCMeta):
    """ 抽象命令类：早餐
    """
    @abc.abstractmethod
    def cooking(self):
        pass

class ChangFen(Breakfast):
    """ 具体命令：肠粉
    """
    def __init__(self) -> None:
        self._recv = ChangFenChef()

    def cooking(self):
        self._recv.cooking()

class HunTun(Breakfast):
    """ 具体命令：馄饨
    """
    def __init__(self) -> None:
        self._recv = HunTunChef()
        
    def cooking(self):
        self._recv.cooking()

class HeFen(Breakfast):
    """ 具体命令：河粉
    """
    def __init__(self) -> None:
        self._recv = HeFenChef()
        
    def cooking(self):
        self._recv.cooking()


class Waiter:
    """ 调用者：服务员
    """
    def __init__(self) -> None:
        self._changfen = None
        self._huntun = None
        self._hefen = None
    
    def set_changfen(self, changfen):
        self._changfen = changfen
    
    def set_huntun(self, huntun):
        self._huntun = huntun
    
    def set_hefen(self, hefen):
        self._hefen = hefen 

    def choose_changfen(self):
        self._changfen.cooking()
    
    def choose_huntun(self):
        self._huntun.cooking()

    def choose_hefen(self):
        self._hefen.cooking()

def main():
    food_changfen = ChangFen()
    food_huntun = HunTun()
    food_hefen = HeFen()
    waiter = Waiter()

    waiter.set_changfen(food_changfen)  # 设置肠粉菜单
    waiter.set_huntun(food_huntun)      # 设置混沌菜单
    waiter.set_hefen(food_hefen)        # 设置河粉菜单

    waiter.choose_changfen()            # 选择肠粉
    waiter.choose_huntun()              # 选择馄饨
    waiter.choose_hefen()               # 选择河粉


if __name__ == "__main__":
    main()

