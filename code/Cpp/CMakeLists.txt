# @file     - CMakeLists.txt
# @author   - wdn (dongnian.wang@outlook.com)
# @brief    - 工程编译文件
# @version  - 0.1
# @date     - 2022-05-07
# 
# @copyright Copyright (c) 2022 

cmake_minimum_required (VERSION 3.0)

project ("designe_pattern_cpp")

# 设置C C++语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

if (NOT DEFINED CMAKE_BUILD_TYPE)
    message(STATUS "CMAKE_BUILD_TYPE not defined, 'Release' will be used")
    set(CMAKE_BUILD_TYPE "Release")
endif()

# 编译成可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

# 包含子项目。

## 单例模式
add_executable(01_singleton "01_singleton.cpp")

## 工厂模式
add_executable(02_factory_method "02_factory_method.cpp")

## 抽象工厂
add_executable(02.1_abstract_factory "02.1_abstract_factory.cpp")

## 建造者模式
add_executable(03_build "03_build.cpp")

## 原型模式
add_executable(04_prototype "04_prototype.cpp")

## 代理模式
add_executable(05_proxy "05_proxy.cpp")

## 桥接模式
add_executable(06_bridge "06_bridge.cpp")

## 装饰器模式
add_executable(07_decorator "07_decorator.cpp")

## 适配模式
add_executable(08_adapter "08_adapter.cpp")

## 外观模式
add_executable(09_facade "09_facade.cpp")

## 组合模式
add_executable(10_composite "10_composite.cpp")

## 享元模式
add_executable(11_fly_weight "11_fly_weight.cpp")

## 观察者模式
add_executable(12_observer "12_observer.cpp")

## 模板模式
add_executable(13_template "13_template.cpp")

## 策略模式
add_executable(14_strategy "14_strategy.cpp")

## 职责链模式
add_executable(15_chain_of_responsibility "15_chain_of_responsibility.cpp")

## 状态模式
add_executable(16_state "16_state.cpp")

## 迭代器模式
add_executable(17_iterator "17_iterator.cpp")

## 访问者模式
add_executable(18_visitor "18_visitor.cpp")

## 备忘录模式
add_executable(19_memento "19_memento.cpp")

## 命令模式模式
add_executable(20_command "20_command.cpp")

## 解释器模式
add_executable(21_interpreter "21_interpreter.cpp")

## 中介者模式
add_executable(22_mediator "22_mediator.cpp")
