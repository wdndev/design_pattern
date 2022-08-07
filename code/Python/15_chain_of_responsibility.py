# -*- coding: utf-8 -*-
#  @file        - 15_chain_of_responsibility.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 职责链模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

# 假如规定学生请假小于或等于 2 天，班主任可以批准；小于或等于 7 天，
# 系主任可以批准；小于或等于 10 天，院长可以批准；其他情况不予批准；

import imp

import abc

class Leader(metaclass=abc.ABCMeta):
    """ 抽象处理者：领导类
    """
    def __init__(self) -> None:
        self._next = None
    
    def set_next(self, next):
        self._next = next
    
    def get_next(self):
        return self._next

    @abc.abstractmethod
    def handle_request(self, leave_days):
        pass

class ClassAdviser(Leader):
    """
    """

    def handle_request(self, leave_days):
        if leave_days <=2 :
            print("班主任批准您请假 {} 天. ".format(leave_days))
        else :
            if self.get_next() is not None:
                self.get_next().handle_request(leave_days)
            else :
                print("请假天数太多，没有人批准该假条! ")

class DepartmentHead(Leader):
    """ 具体处理者2：系主任类
    """

    def handle_request(self, leave_days):
        if leave_days <=7 :
            print("系主任批准您请假 {} 天.".format(leave_days))
        else :
            if self.get_next() is not None:
                self.get_next().handle_request(leave_days)
            else :
                print("请假天数太多，没有人批准该假条! ")

class Dean(Leader):
    """ 具体处理者3：院长类
    """

    def handle_request(self, leave_days):
        if leave_days <=10 :
            print("院长批准您请假 {} 天.".format(leave_days))
        else :
            if self.get_next() is not None:
                self.get_next().handle_request(leave_days)
            else :
                print("请假天数太多，没有人批准该假条! ")

def main():
    teacher1 = ClassAdviser()
    teacher2 = DepartmentHead()
    teacher3 = Dean()

    # 组装职责链
    teacher1.set_next(teacher2)
    teacher2.set_next(teacher3)

    # 提交需求
    teacher1.handle_request(1)
    teacher1.handle_request(5)
    teacher1.handle_request(9)
    teacher1.handle_request(15)


if __name__ == "__main__":
    main()

