# @file CMakeLists.txt
# @author wdn
# @brief  工程编译文件
# @version 0.1
# @date 2021-03-11
# 
# @copyright Copyright (c) 2021 

cmake_minimum_required (VERSION 3.0)

project ("behavior_pattern")

# 包含子项目
## 模板方法模式
add_subdirectory ("13_template")
## 策略模式
add_subdirectory ("14_strategy")
## 命令模式
add_subdirectory ("15_command")
## 责任链模式
add_subdirectory ("16_chain_of_responsibility")
## 状态模式
add_subdirectory ("17_state")
## 观察者模式
add_subdirectory ("18_observer")
## 中介者模式
add_subdirectory ("19_mediator")
## 迭代器模式
add_subdirectory ("20_iterator")
## 访问者模式
add_subdirectory ("21_visitor")
## 备忘录模式
add_subdirectory ("22_memento")
## 解释器模式
add_subdirectory ("23_interpreter")


