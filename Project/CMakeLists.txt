cmake_minimum_required(VERSION 3.22)
project(ProjectContainer)

# 🎯 創建統一的項目容器 INTERFACE 庫
add_library(ProjectContainer INTERFACE)

# 🎯 鏈接通用工具庫 - 這是核心功能
target_link_libraries(ProjectContainer INTERFACE
        Utils::Logger
        Utils::JSON
        Utils::DataBase
        Utils::Network
        Utils::TCP
        Utils::MessageQueue
        Utils::ThreadPool
)

#ALIAS 別名
add_library(Proj::Container ALIAS ProjectContainer)

# 關鍵開關：預設開啟自動掃描（你現在最爽）
option(PROJECT_ENABLE_AUTO_DISCOVERY
        "自動掃描所有子模塊（關掉後強制走白名單，適合 CI/團隊）"
        ON)

if(PROJECT_ENABLE_AUTO_DISCOVERY)
    message(STATUS "自動掃描模式啟用 - 所有有 CMakeLists.txt 的資料夾都會被加入")
    file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*")
    foreach(child ${children})
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child}
                AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt)
            message(STATUS "  → 自動加入模塊: ${child}")
            add_subdirectory(${child})
        endif()
    endforeach()
else()
    message(STATUS "白名單模式啟用 - 只編譯明確指定的模塊")
    set(PROJECT_SUBMODULES
            Algorithms
            Server
            Client
            Tools
            # 未來正式模塊都寫在這裡
    )
    foreach(sub ${PROJECT_SUBMODULES})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${sub}/CMakeLists.txt)
            add_subdirectory(${sub})
        else()
            message(WARNING "白名單模塊不存在: ${sub}")
        endif()
    endforeach()
endif()
