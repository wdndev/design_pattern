# -*- coding: utf-8 -*-
#  @file        - 19_memento.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 备忘录模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 假如有西施、王昭君、貂蝉、杨玉环四大美女同你相亲，
# 你可以选择其中一位作为你的爱人；当然，如果你对前面的选择不满意，
# 还可以重新选择，但希望你不要太花心；
# 这个游戏提供后悔功能，用“备忘录模式”设计比较合适。

from matplotlib.pyplot import show
from numpy import true_divide


class Girl:
    """ 备忘录：美女
    """ 
    def __init__(self, name) -> None:
        self._name = name

    def set_name(self, name):
        self._name = name
    
    def get_name(self):
        return self._name

class You:
    """ 发起人：你
    """
    def __init__(self) -> None:
        self._wife_name = None

    def set_wife_name(self, name):
        self._wife_name = name

    def get_wife_name(self):
        return self._wife_name

    def create_memento(self):
        return Girl(self._wife_name)

    def restore_momento(self, girl):
        self.set_wife_name(girl.get_name())

class GirlStack:
    """ 管理者：美女栈
    """
    def __init__(self) -> None:
        self._top = -1
        self._girl = list()

    def push(self, girl):
        if self._top >= 4 :
            print("你太花心了，变来变去的! ")
            return False
        else :
            self._top += 1
            print("vvvv", self._top)
            self._girl.insert(self._top, girl)
            return True

    def pop(self):
        if self._top <= 0 :
            print("美女栈空了! ")
            return self._girl[0]
        else :
            self._top -= 1
            return self._girl[self._top]
    
# 测试
def show_girl(name):
    print("================")
    print("[sys] 你选择了 ", name)
    print("================")

def main():
    you = You()
    girl_stack = GirlStack()

    name_idx = 0
    is_true = 0
    name = None

    while True:

        while True:
            print("四大美女有“沉鱼落雁之容、闭月羞花之貌”，您选择谁?")
            print("[sys] [1] 西施")
            print("[sys] [2] 貂蝉")
            print("[sys] [3] 王昭君")
            print("[sys] [4] 杨玉环")
            print("请选择： ")
            name_idx = input()
            name_idx = int(name_idx)
            print("input: ", name_idx)
            if name_idx == 1 or name_idx == 2 or name_idx == 3 or name_idx == 4 :
                break

        while True:
            print("[sys] [0] 返回")
            print("[sys] [1] 确定")
            print("[sys] [2] 退出")
            print("请确定： ")
            is_true = input()
            is_true = int(is_true)
            if is_true == 0 or is_true == 1 or is_true == 2 :
                break

        if name_idx == 1 :
            name = "西施"
        elif name_idx == 2 :
            name = "貂蝉"
        elif name_idx == 3 :
            name = "王昭君"
        elif name_idx == 4 :
            name = "杨玉环"

        if is_true == 1:
            you.set_wife_name(name)
            if girl_stack.push(you.create_memento()):
                show_girl(name)
        elif is_true == 0 :
            you.restore_momento(girl_stack.pop())
            show_girl(you.get_wife_name())
        elif is_true == 2 :
            break


if __name__ == "__main__":
    main()
