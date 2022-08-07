# -*- coding: utf-8 -*-
#  @file        - 08_adapter.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 适配器模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 新能源汽车的发动机有电能发动机（Electric Motor）和光能发动机（Optical Motor）等，
# 各种发动机的驱动方法不同，客户端希望用统一的发动机驱动方法 drive() 访问这两种发动机，
# 所以必须定义一个统一的目标接口 Motor，
# 然后再定义电能适配器（Electric Adapter）和光能适配器（Optical Adapter）去适配这两种发动机。

import abc

class TargetMotor(metaclass=abc.ABCMeta):
    """
    """
    def __init__(self) -> None:
        pass

    @abc.abstractmethod
    def drive(self):
        pass

class AdateeElectricMotor:
    """
    """
    
    def electric_drive(self):
        print("Electric Motor")

class AdateeOpticalMotor:
    """
    """
    
    def optical_drive(self):
        print("Optical Motor")


class AdapterElectric(TargetMotor):
    """
    """
    def __init__(self) -> None:
        self._emotor = AdateeElectricMotor()
    
    def drive(self):
        self._emotor.electric_drive()

class AdapterOptical(TargetMotor):
    """
    """
    def __init__(self) -> None:
        self._omotor = AdateeOpticalMotor()
    
    def drive(self):
        self._omotor.optical_drive()

def main():
    # 电能测试
    emotor = AdapterElectric()
    emotor.drive()

    # 光能测试
    omotor = AdapterOptical()
    omotor.drive()

if __name__ == "__main__":
    main()