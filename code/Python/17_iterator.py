# -*- coding: utf-8 -*-
#  @file        - 17_iterator.py
#  @author      - wdn (dongnian.wang@outlook.com)
#  @brief       - 迭代器模式
#  @version     - 0.1
#  @date        - 2022-03-10
#  @copyright   - Copyright (c) 2021 

import abc

class Iterator(metaclass=abc.ABCMeta):
    """抽象迭代器（Iterator）角色：定义访问和遍历聚合元素的接口，
            通常包含 hasNext()、first()、next() 等方法。
    """
    @abc.abstractmethod 
    def first(self):
        pass
    
    @abc.abstractmethod 
    def next(self):
        pass

    @abc.abstractmethod 
    def has_next(self):
        pass

    @abc.abstractmethod 
    def current_item(self):
        pass

class ConcreteIterator(Iterator):
    """具体迭代器（Concretelterator）角色：实现抽象迭代器接口中所定义的方法，
            完成对聚合对象的遍历，记录遍历的当前位置。
    """
    def __init__(self, aggregate) -> None:
        super().__init__()
        self._index = 0
        self._aggregate = aggregate

    def first(self):
        return self._aggregate.remove(0)

    def next(self):
        elem = None
        
        if self._index < self._aggregate.count():
            elem = self._aggregate.remove(self._index)
        self._index = self._index + 1
        # print("elem: ", elem)
        return elem

    def has_next(self):
        return (self._index >= self._aggregate.count())
    
    def current_item(self):
        return self._aggregate.remove(self._index)

class Aggregate(metaclass=abc.ABCMeta):
    """ 抽象聚合（Aggregate）角色：定义存储、添加、删除聚合对象以及创建迭代器对象的接口
    """
    # @abc.abstractmethod
    # def create_iterator(self):
    #     pass

    @abc.abstractmethod
    def add(self, item):
        pass

    @abc.abstractmethod
    def remove(self, index):
        pass

    @abc.abstractmethod
    def count(self):
        pass

class ConcreteAggregate(Aggregate):
    """ 具体聚合（ConcreteAggregate）角色：实现抽象聚合类，返回一个具体迭代器的实例。
    """
    def __init__(self) -> None:
        super().__init__()
        self._iterator = None
        self._items = list()

    def add(self, item):
        self._items.append(item)

    def remove(self, index):
        item = None
        # print("111", self._items)
        if index < self.count() :
            item = self._items[index]
            # self._items.remove(item)
        # print("222", self._items)
        return item
    
    def count(self):
        return len(self._items)
            
def main():
    concrete_aggregate = ConcreteAggregate()
    concrete_aggregate.add("hello")
    concrete_aggregate.add("world")
    concrete_aggregate.add("!")
    concrete_aggregate.add("!")
    concrete_aggregate.add("!")
    concrete_aggregate.add("!")
    concrete_aggregate.add("!")

    it = ConcreteIterator(concrete_aggregate)
    # while it.has_next() is not None:
    #     print(it.current_item())
    #     it.next();
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()
    print(it.current_item())
    it.next()

if __name__ == "__main__":
    main()