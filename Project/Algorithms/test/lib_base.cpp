#include "Utils/Logger.hpp"

int main() {
    using namespace Utils::Logger;
    // 初始化日志系统
    Logger logger;
    logger.AddPolicy(std::make_shared<ConsoleLogPolicy>());
    logger.AddPolicy(std::make_shared<FileLogPolicy>("app.log"));

    // 记录日志
    logger.Info("System started. Version: {}", 1.2);
    logger.Debug("User {} logged in from {}", "Alice", "192.168.1.10");
    logger.Error("Failed to connect database!");

    return 0;
}
//
// Created by unwan on 25-12-6.
//
