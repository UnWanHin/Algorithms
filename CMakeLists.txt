cmake_minimum_required(VERSION 3.22)
project(C_Programming)

# 设置项目语言和标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加工具箱
add_subdirectory(CommonUtils)

# 添加项目目录
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Project AND IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Project)
add_subdirectory(Project)
else()
    message(STATUS "Project directory not found, creating empty one")
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Project)
endif()
