# -*- coding: utf-8 -*-
#  @file        - 07_decorator.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 装饰器模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 在《恶魔战士》中，游戏角色“莫莉卡·安斯兰”的原身是一个可爱少女，
# 但当她变身时，会变成头顶及背部延伸出蝙蝠状飞翼的女妖，当然她还可以变为穿着漂亮外衣的少女。
# 这些都可用装饰模式来实现，在本实例中的“莫莉卡”原身有 set_image(String t) 方法决定其显示方式，
# 而其 变身“蝙蝠状女妖”和“着装少女”可以用 set_changer() 方法来改变其外观，
# 原身与变身后的效果用 display() 方法来显示。

import abc

class AbstractComponentMorrign(metaclass=abc.ABCMeta):
    """ 抽象构件角色：莫莉卡
    """
    def __init__(self) -> None:
        self.img_name = None

    @abc.abstractmethod
    def display(self):
        pass

    def set_image(self, img_name):
        self.img_name = img_name
    
    def get_image(self):
        return self.img_name

class ConcreteComponentOriginal(AbstractComponentMorrign):
    """ 具体构件角色：原身
    """
    def __init__(self) -> None:
        super().__init__()
        self.set_image("original!!!")

    def display(self):
        print(self.get_image())

class AbstractDecoratorChanger(AbstractComponentMorrign):
    """ 抽象装饰角色：变形
    """
    def __init__(self, m) -> None:
        super().__init__()
        self.morrign = m
    
    def display(self):
        print(self.get_image())

class ConcreteDecoratorSuccubus(AbstractDecoratorChanger):
    """ 具体装饰角色：女妖
    """
    def __init__(self, m) -> None:
        super().__init__(m)

    def set_changer(self):
        self.morrign.set_image("Succubus~~~")

    def display(self):
        self.set_changer()
        self.morrign.display()

class ConcreteDecoratorGirl(AbstractDecoratorChanger):
    """ 具体装饰角色：少女
    """
    def __init__(self, m) -> None:
        super().__init__(m)

    def set_changer(self):
        self.morrign.set_image("Girl~~~")

    def display(self):
        self.set_changer()
        self.morrign.display()

def main():
    m0 = ConcreteComponentOriginal()
    m0.display()
    m1 = ConcreteDecoratorSuccubus(m0)
    m1.display()
    m2 = ConcreteDecoratorGirl(m0)
    m2.display()


if __name__ == "__main__":
    main()