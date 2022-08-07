# -*- coding: utf-8 -*-
#  @file        - 16_state.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 状态模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 红灯停，绿灯行，黄灯亮了等一等。

import abc
import time

class TrafficLightsContext:
    """
    """
    def __init__(self) -> None:
        print("TrafficLightsContext", self)
        self._state = RedLight(self)
    
    def set_state(self, state):
        self._state = state

    def request(self):
        self._state.handle()

class AbstractState(metaclass=abc.ABCMeta):
    """
    """
    @abc.abstractmethod
    def handle(self):
        pass

class RedLight(AbstractState):
    """
    """
    def __init__(self, context) -> None:
        self._context = context
    
    def handle(self):
        print("Red Light")
        self._context.set_state(GreeLight(self._context))

class GreeLight(AbstractState):
    """
    """
    def __init__(self, context) -> None:
        self._context = context
    
    def handle(self):
        print("Green Light")
        self._context.set_state(YellowLight(self._context))

class YellowLight(AbstractState):
    """
    """
    def __init__(self, context) -> None:
        self._context = context
    
    def handle(self):
        print("Yellow Light")
        self._context.set_state(RedLight(self._context))
    

def main():
    i = 0
    seconds = 0

    tlc = TrafficLightsContext()
    while True:
        # 表示一个完整的状态流（红灯->绿灯->黄灯）已经完成
        if i % 3 == 0:
            print("**********Session {} **********".format(int(((i+1)//3)+1)))

        # 根据当前状态来设置持续时间，红灯（6秒）、绿灯（4秒）、黄灯（2秒）
        if i % 3 == 0:
            seconds = 6
        elif i % 3 == 1:
            seconds = 4
        elif i % 3 == 2:
            seconds = 2
        
        # 休眠
        time.sleep(seconds)

        tlc.request()
        i = i + 1


if __name__ == "__main__":
    main()    
