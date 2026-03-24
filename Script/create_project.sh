#!/bin/bash

# 获取脚本所在目录
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# 项目根目录（脚本目录的上级目录）
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# 检查参数
if [ -z "$1" ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

PROJECT_NAME=$1
TARGET_DIR="$PROJECT_ROOT/Project/$PROJECT_NAME"

# 创建目录结构
mkdir -p "$TARGET_DIR/src"
mkdir -p "$TARGET_DIR/include"
mkdir -p "$TARGET_DIR/test"

# 创建 CMakeLists.txt
cat > "$TARGET_DIR/CMakeLists.txt" << EOF
cmake_minimum_required(VERSION 3.22)

project($PROJECT_NAME)

# 设置项目语言和标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin)

# 查找源文件
file(GLOB_RECURSE HEADER_FILES "include/*.h" "include/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.cc")

# 添加可执行文件
if(SOURCE_FILES)
    add_executable(\${PROJECT_NAME} \${HEADER_FILES} \${SOURCE_FILES})

    # 包含目录
    target_include_directories(\${PROJECT_NAME}
        PRIVATE
            \${CMAKE_CURRENT_SOURCE_DIR}/include
            \${CMAKE_SOURCE_DIR}/CommonUtils/include
    )

    # 链接CommonUtils中的库
    target_link_libraries(\${PROJECT_NAME}
        PRIVATE
            Utils::Logger
            Utils::ThreadPool
            # 添加其他需要的库...
    )
else()
    message(WARNING "No source files found for project \${PROJECT_NAME}")
endif()

# 添加测试（如果存在）
if(EXISTS \${CMAKE_CURRENT_SOURCE_DIR}/test)
    file(GLOB TEST_SOURCES "test/*.cpp")
    if(TEST_SOURCES)
        enable_testing()

        foreach(test_source \${TEST_SOURCES})
            get_filename_component(TEST_NAME \${test_source} NAME_WE)
            add_executable(\${TEST_NAME} \${test_source})
            target_link_libraries(\${TEST_NAME} PRIVATE \${PROJECT_NAME})
            add_test(NAME \${TEST_NAME} COMMAND \${TEST_NAME})
        endforeach()
    endif()
endif()
EOF

# 创建示例源文件
cat > "$TARGET_DIR/src/main.cpp" << EOF
#include <iostream>
#include "$PROJECT_NAME.hpp"

int main() {
    std::cout << "Hello from $PROJECT_NAME!" << std::endl;
    return 0;
}
EOF

# 创建示例头文件
cat > "$TARGET_DIR/include/$PROJECT_NAME.hpp" << EOF
#pragma once

// 示例头文件内容
class ${PROJECT_NAME}Class {
public:
    ${PROJECT_NAME}Class();
    void doSomething();
};
EOF

# 创建测试文件
cat > "$TARGET_DIR/test/test_$PROJECT_NAME.cpp" << EOF
#include <iostream>
#include "$PROJECT_NAME.hpp"

int main() {
    std::cout << "Running tests for $PROJECT_NAME" << std::endl;
    // 添加您的测试代码
    return 0;
}
EOF

echo "Project $PROJECT_NAME created successfully in $TARGET_DIR"