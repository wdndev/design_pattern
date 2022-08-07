# -*- coding: utf-8 -*-
#  @file        - 03_build.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 建造者模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class Product:
    """
    产品：客厅
    """
    def __init__(self) -> None:
        self.wall = None
        self.TV = None
        self.sofa = None
    def _set_wall(self, wall):
        self.wall = wall
    def _set_TV(self, TV):
        self.TV = TV
    def _set_safa(self, sofa):
        self.sofa = sofa

    def show(self):
        print("wall is", self.wall)
        print("TV is", self.TV)
        print("sofa is", self.sofa)
    

class AbstractBuilder(metaclass=abc.ABCMeta):
    """
    抽象建造者：装修工人
    """
    def __init__(self) -> None:
        self.product = Product()
    
    @abc.abstractmethod
    def _build_wall(self):
        pass

    @abc.abstractmethod
    def _build_TV(self):
        pass

    @abc.abstractmethod
    def _build_sofa(self):
        pass

    def get_result(self):
        return self.product
    
class ConcreteBuilderDecorator1(AbstractBuilder):
    """
    具体建造者：具体装修工人1
    """
    def _build_wall(self):
        return self.product._set_wall("w1")
    def _build_TV(self):
        return self.product._set_TV("w1")
    def _build_sofa(self):
        return self.product._set_safa("sofa1")

class ConcreteBuilderDecorator2(AbstractBuilder):
    """
    具体建造者：具体装修工人2
    """
    def _build_wall(self):
        return self.product._set_wall("w2")
    def _build_TV(self):
        return self.product._set_TV("w2")
    def _build_sofa(self):
        return self.product._set_safa("sofa2")

class DirectorProjectMgr:
    """
    指挥者：项目经理
    """
    def __init__(self) -> None:
        self.builder = None

    def construct(self, builder):
        self.builder = builder
        self.builder._build_wall()
        self.builder._build_TV()
        self.builder._build_sofa()
        
def main():
    concrete_builder = ConcreteBuilderDecorator2()
    director = DirectorProjectMgr()
    director.construct(concrete_builder)
    product = concrete_builder.product
    product.show()


if __name__ == "__main__":
    main()