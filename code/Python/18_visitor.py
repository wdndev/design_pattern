# -*- coding: utf-8 -*-
#  @file        - 18_visitor.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 访问者模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 艺术公司利用“铜”可以设计出铜像，利用“纸”可以画出图画；
# 造币公司利用“铜”可以印出铜币，利用“纸”可以印出纸币。
# 对“铜”和“纸”这两种元素，两个公司的处理方法不同。

import abc

class ICompany(metaclass=abc.ABCMeta):
    """ 抽象访问者：公司
    """
    @abc.abstractmethod
    def paper_create(self, elem):
        pass

    @abc.abstractmethod
    def cuprum_create(self, elem):
        pass

class ArtCompany(ICompany):
    """ 具体访问者：艺术公司
    """

    def paper_create(self, elem):
        return "使用" + elem.get_material_name() + "制作了" + "讲学图"

    def cuprum_create(self, elem):
        return "使用" + elem.get_material_name() + "制作了" + "铜像"


class MintCompany(ICompany):
    """ 具体访问者：造币公司 
    """

    def paper_create(self, elem):
        return "使用" + elem.get_material_name() + "制作了" + "纸币"

    def cuprum_create(self, elem):
        return "使用" + elem.get_material_name() + "制作了" + "铜币"

class IMaterial(metaclass=abc.ABCMeta):
    """
    """
    def __init__(self, material_name) -> None:
        self._material_name = material_name
    
    def get_material_name(self):
        return self._material_name

    @abc.abstractmethod
    def accept(self, visitor):
        pass

class Paper(IMaterial):
    """ 具体元素：纸
    """
    def __init__(self) -> None:
        super().__init__("paper")

    def accept(self, visitor):
        return visitor.paper_create(self)

class Cuprum(IMaterial):
    """ 具体元素：铜
    """
    def __init__(self) -> None:
        super().__init__("cuprum")

    def accept(self, visitor):
        return visitor.cuprum_create(self)

class SetMaterial:
    """ 对象结构角色：材料集
    """
    def __init__(self) -> None:
        self._elems = set()

    def accept(self, visitor):
        tmp = ""
        for s in self._elems:
            tmp += s.accept(visitor) + " "
        return tmp

    def add(self, elem):
        self._elems.add(elem)

    def remove(self, elem):
        self._elems.remove(elem)

def main():
    set_material = SetMaterial()
    paper_material = Paper()
    cuprum_material = Cuprum()

    set_material.add(paper_material)
    set_material.add(cuprum_material)

    art_visitor = ArtCompany()
    print(set_material.accept(art_visitor))

    print("----------------------")

    mint_visitor = MintCompany()
    print(set_material.accept(mint_visitor))



if __name__ == "__main__":
    main()


