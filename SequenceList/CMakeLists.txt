# 设置工程名称
project(SqList) 
cmake_minimum_required(VERSION 3.0.0)

# 用于设置环境变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# 设置头文件包含路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 遍历文件
file(GLOB_RECURSE all_files
src/*.cpp
src/*.cc
src/*.c
test/*.cpp
test/*.cc
test/*.c)

# 生成目标可执行文件
add_executable(main ${all_files})
