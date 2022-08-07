# -*- coding: utf-8 -*-
#  @file        - 10_composite.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 组合模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 假如李先生到“天街e角”生活用品店购物，
# 用 1 个红色小袋子装了 2 包特产（单价 7.9 元）、1 张地图（单价 9.9 元）；
# 用 1 个白色小袋子装了 2 包香菇（单价 68 元）和 3 包红茶（单价 180 元）；
# 用 1 个中袋子装了前面的红色小袋子和 1 个景德镇瓷器（单价 380 元）；
# 用 1 个大袋子装了前面的中袋子、白色小袋子和 1 双李宁牌运动鞋（单价 198 元）。
# 最后“大袋子”中的内容有：{
#      1 双李宁牌运动鞋（单价 198 元）、
#      白色小袋子{2 包香菇（单价 68 元）、
#      3 包红茶（单价 180 元）}、
#      中袋子{1 个景德镇瓷器（单价 380 元）、
#      红色小袋子{2 包特产（单价 7.9 元）、
#      1 张地图（单价 9.9 元）}}}，
# 现在要求编程显示李先生放在大袋子中的所有商品信息并计算要支付的总价。

import abc
from cgitb import small

class Articles(metaclass=abc.ABCMeta):
    """ 抽象构件（Component）角色：物品
    """

    @abc.abstractmethod
    def calculation(self):
        pass
    @abc.abstractmethod
    def show(self):
        pass

class Goods(Articles):
    """ 树叶构件（Leaf）角色：货物
    """
    def __init__(self, name, quantity, unit_price) -> None:
        self._name = name
        self._quantity = quantity
        self._unit_price = unit_price

    def calculation(self):
        return self._quantity * self._unit_price

    def show(self):
        print("{}  (数量 {}, 单价: {}, RMB.)".format(self._name, self._quantity, self._unit_price))

class Bags(Articles):
    """ 树枝构件（Composite）角色：袋子
    """
    def __init__(self, name) -> None:
        self._name = name
        self._bag = dict()

    def add(self, goods_name, good_ptr):
        self._bag[goods_name] = good_ptr
    
    def remove(self, goods_name):
        del self._bag[goods_name]

    def calculation(self):
        sum = 0.0
        for k, v in self._bag.items():
            sum += v.calculation()
        return sum

    def show(self):
        for k, v in self._bag.items():
            v.show()

def main():
    big_bag = Bags("大袋子: ")
    medium_bag = Bags("中袋子: ")
    small_red_bag = Bags("红色小袋子: ")
    small_white_bag = Bags("白色小袋子: ")

    sp = Goods(" 特产 ", 2, 7.9)
    small_red_bag.add(" 特产 ", sp)
    sp = Goods(" 地图 ", 1, 9.9)
    small_red_bag.add(" 地图 ", sp)

    sp = Goods(" 香菇 ", 2, 68)
    small_white_bag.add(" 香菇 ", sp)
    sp = Goods(" 红茶 ", 3, 180)
    small_white_bag.add(" 红茶 ",sp)

    sp = Goods(" 景德镇瓷器 ", 1, 380)
    medium_bag.add(" 景德镇瓷器 ", sp)
    medium_bag.add("红色小袋子 ", small_red_bag)

    sp = Goods(" 李宁牌运动鞋 ", 1, 198)
    big_bag.add(" 李宁牌运动鞋 ", sp)
    big_bag.add("白色小袋子 ", small_white_bag)
    big_bag.add("中袋子: ", medium_bag)

    print("您选购的商品有: ")
    big_bag.show()
    print("要支付的总价为 : {} RMB.".format(big_bag.calculation()))

    big_bag.remove(" 李宁牌运动鞋 ")
    print("您选购的商品有: ")
    big_bag.show()
    print("要支付的总价为 : {} RMB.".format(big_bag.calculation()))
    

if __name__ == "__main__":
    main()
