# -*- coding: utf-8 -*-
#  @file        - 01_singleton.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 单例模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 


# 方法一
class Instance:
    _instance = None

    @classmethod
    def get_instance(cls):
        if cls._instance:
            return cls._instance
        else :
            cls._instance = Instance
            return cls._instance


# 方法二
class Singleton(type):
    def __init__(cls, name, bases, attrs, **kwargs) -> None:
        super().__init__(name, bases, attrs)
        cls._instance = None
        
    def __call__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__call__(*args, **kwargs)
        return cls._instance
    

class MyClass(metaclass=Singleton):
    """
        示例
    """
    pass

def main():
    m1 = MyClass()
    m2 = MyClass()
    # assert m1 is m2
    if m1 is m2:
        print("1111")
    else:
        print("2222")

if __name__ == "__main__":
    main()