# @file CMakeLists.txt
# @author wdn
# @brief  工程编译文件
# @version 0.1
# @date 2021-03-11
# 
# @copyright Copyright (c) 2021 

cmake_minimum_required (VERSION 3.0)

project ("create_pattern")

# 包含子项目。
## 单例模式
add_subdirectory ("01_singleton")
## 原型模式
add_subdirectory ("02_prototype")
## 工厂模式
add_subdirectory ("03_factory")
## 抽象工厂模式
add_subdirectory ("04_abstract_factory")
## 建造者模式
add_subdirectory ("05_builder")
