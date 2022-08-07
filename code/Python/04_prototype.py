# -*- coding: utf-8 -*-
#  @file        - 04_prototype.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 原型模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import copy

class Prototype:
    """
    """
    def use(self, addr):
        print("hello world! addr: {}".format(addr))

def main():
    prototype = Prototype()
    prototype_copy = copy.copy(prototype)
    prototype_deepcopy = copy.deepcopy(prototype)

    prototype.use(id(prototype))
    prototype_copy.use(id(prototype_copy))
    prototype_deepcopy.use(id(prototype_deepcopy))

if __name__ == "__main__":
    main()
