# @file CMakeLists.txt
# @author wdn
# @brief  工程编译文件
# @version 0.1
# @date 2021-03-11
# 
# @copyright Copyright (c) 2021 

cmake_minimum_required (VERSION 3.0)

project ("23_interpreter")

# 生成可执行文件。
add_executable(23_interpreter "interpreter.h" "interpreter.cpp" "main.cpp")