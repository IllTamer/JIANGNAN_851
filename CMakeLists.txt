cmake_minimum_required(VERSION 3.26)
project(JIANGNAN_851 C)

set(CMAKE_C_STANDARD 11)
# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/outputs)

add_executable(
        JIANGNAN_851 main.c main.h
        algorithm
        structs
)
