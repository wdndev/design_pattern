# @file CMakeLists.txt
# @author wdn
# @brief  工程编译文件
# @version 0.1
# @date 2021-03-11
# 
# @copyright Copyright (c) 2021 

cmake_minimum_required (VERSION 3.0)

project ("struct_pattern")

# 包含子项目。
## 代理模式
add_subdirectory ("06_proxy")
## 适配器模式
add_subdirectory ("07_adapter")
## 桥接模式
add_subdirectory ("08_bridge")
## 装饰模式
add_subdirectory ("09_decorator")
## 外观模式
add_subdirectory ("10_facade")
## 享元模式
add_subdirectory ("11_fly_weight")
## 组合模式
add_subdirectory ("12_composite")
