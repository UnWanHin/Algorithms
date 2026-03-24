# Project/Algorithms/CMakeLists.txt  ← 終極無敵版，直接貼！
cmake_minimum_required(VERSION 3.22)
project(Data_Structure LANGUAGES CXX)

# 1. 自動處理 include 目錄（不存在也不崩）
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
if(EXISTS ${INCLUDE_DIR} AND IS_DIRECTORY ${INCLUDE_DIR})
    set(HAS_INCLUDE ON)
else()
    set(HAS_INCLUDE OFF)
    message(STATUS "${PROJECT_NAME}: include 目錄不存在，自動創建一個（之後可放頭文件）")
    file(MAKE_DIRECTORY ${INCLUDE_DIR})
endif()

# 2. 收集源文件（支援 src/ 和根目錄直接放 cpp）
file(GLOB_RECURSE SOURCES
        "src/*.cpp" "src/*.cc"
        "*.cpp" "*.cc"
)
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "test/*.cc")

# 3. 智能建庫
list(LENGTH SOURCES SOURCE_COUNT)

if(SOURCE_COUNT EQUAL 0)
    message(STATUS "${PROJECT_NAME}: 無源文件 → 創建 INTERFACE 庫")
    add_library(${PROJECT_NAME} INTERFACE)
else()
    message(STATUS "${PROJECT_NAME}: 發現 ${SOURCE_COUNT} 個源文件 → 創建靜態庫")
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
    target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
endif()

# 包含目錄（有才加）
if(HAS_INCLUDE)
    target_include_directories(${PROJECT_NAME}
            PUBLIC
            $<BUILD_INTERFACE:${INCLUDE_DIR}>
            $<INSTALL_INTERFACE:include>
    )
endif()

# 4. 關鍵！一鍵繼承所有通用工具（一定要用有命名空間的！）
target_link_libraries(${PROJECT_NAME} PUBLIC Proj::Container)

# 5. 自動生成帶 main 的 exe（已修好版）
foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME_WE)

    file(READ ${src} content LIMIT 512000)
    if(content MATCHES "int[ \t]+main[ \t]*\\(" OR content MATCHES "void[ \t]+main[ \t]*\\(")
        set(exe_name "${PROJECT_NAME}_${name}")
        if(NOT TARGET ${exe_name})
            message(STATUS "檢測到 main() → 創建可執行文件: ${exe_name}")
            add_executable(${exe_name} ${src})
            target_link_libraries(${exe_name} PRIVATE ${PROJECT_NAME})
            if(HAS_INCLUDE)
                target_include_directories(${exe_name} PRIVATE ${INCLUDE_DIR})
            endif()
            set_target_properties(${exe_name} PROPERTIES
                    FOLDER "${PROJECT_NAME}/Exes"
                    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}
            )
        endif()
    endif()
endforeach()

# 6. 測試（可選）
if(TEST_SOURCES)
    foreach(test_src ${TEST_SOURCES})
        get_filename_component(name ${test_src} NAME_WE)
        add_executable("${PROJECT_NAME}_test_${name}" ${test_src})
        target_link_libraries("${PROJECT_NAME}_test_${name}" PRIVATE ${PROJECT_NAME})
        set_target_properties("${PROJECT_NAME}_test_${name}" PROPERTIES FOLDER "${PROJECT_NAME}/Tests")
    endforeach()
endif()

message(STATUS "${PROJECT_NAME} 配置完成！")
