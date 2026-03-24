cmake_minimum_required(VERSION 3.22)
project(Algorithms)
# 设置项目语言和标准 - 从 ProjectContainer 继承，这里可以移除
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置输出目录 - 从根目录继承，这里可以移除
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# 查找源文件
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.cc")
file(GLOB_RECURSE HEADER_FILES "include/*.h" "include/*.hpp")
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "test/*.c")
# 🎯 修复：计算 SOURCE_FILES 数量
list(LENGTH SOURCE_FILES SOURCE_COUNT)  # ✅ 添加这行来定义 SOURCE_COUNT
# 🎯 智能选择库类型
if(SOURCE_COUNT EQUAL 0)
    message(STATUS "${PROJECT_NAME}: No source files - creating INTERFACE library")
    add_library(${PROJECT_NAME} INTERFACE)
    target_include_directories(${PROJECT_NAME} INTERFACE include)
else()
    message(STATUS "${PROJECT_NAME}: Found ${SOURCE_COUNT} source files - creating STATIC library")
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
    target_include_directories(${PROJECT_NAME} PUBLIC include)
endif()
# 🎯 ✨ 关键：链接 ProjectContainer 而不是直接链接 CommonUtilsAll
target_link_libraries(${PROJECT_NAME} PUBLIC ProjectContainer)
# 🎯 为主函数创建可执行文件
foreach(source_file ${SOURCE_FILES})
    get_filename_component(BASE_NAME ${source_file} NAME_WE)
    get_filename_component(FULL_PATH ${source_file} ABSOLUTE)
    file(READ ${FULL_PATH} FILE_CONTENT)
    if(FILE_CONTENT MATCHES "int main[\\s]*\\(|void main[\\s]*\\(" AND
            NOT TARGET "${PROJECT_NAME}_src_${BASE_NAME}")
        set(EXECUTABLE_NAME "${PROJECT_NAME}_src_${BASE_NAME}")
        message(STATUS "创建可执行文件: ${EXECUTABLE_NAME}")
        add_executable(${EXECUTABLE_NAME} ${source_file})
        target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
        target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${PROJECT_NAME})
    endif()
endforeach()

foreach(test_source ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${test_source} NAME_WE)
    set(EXECUTABLE_NAME "${PROJECT_NAME}_test_${TEST_NAME}")
    message(STATUS "创建测试: ${EXECUTABLE_NAME}")
    add_executable(${EXECUTABLE_NAME} ${test_source})
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${PROJECT_NAME})
endforeach()
# 🎯 验证配置
message(STATUS "=== ${PROJECT_NAME} 配置验证 ===")
if(TARGET ${PROJECT_NAME})
    get_target_property(algo_includes ${PROJECT_NAME} INCLUDE_DIRECTORIES)
    get_target_property(algo_interface_includes ${PROJECT_NAME} INTERFACE_INCLUDE_DIRECTORIES)
    message(STATUS "${PROJECT_NAME} 包含路径: ${algo_includes}")
    message(STATUS "${PROJECT_NAME} 接口包含路径: ${algo_interface_includes}")
endif()
