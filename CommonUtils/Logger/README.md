# CommonUtils.Logger

基于C++20的高性能异步日志库，支持控制台彩色输出和文件日志。

## 特性亮点
- 🚀 多线程异步架构（零阻塞主线程）
- 📂 双输出策略：控制台（ANSI彩色） + 文件日志
- ⏱️ 毫秒级时间戳（`2024-08-25 14:35:12.345`）
- 📊 五级日志等级：TRACE / DEBUG / INFO / WARNING / ERROR
- 🔄 环形缓冲池文件写入，百万级文件写入速度
- 🔒 线程安全设计（支持高并发写入）
- 💻 跨平台支持：适用于 Linux / Windows，不依赖任何第三方库

## 快速开始

### 编译项目

项目使用`CMake`开发，可以按照以下的步骤快速测试：
```bash
git clone https://github.com/Motues/Logger.git
cd Logger
mkdir build; cd build
cmake ..
make -j8
./bin/Log_Test
```

### 添加到项目中

该日志库可以作为一个模块集成到几乎任何c++项目中，你可以将本项目拷贝到一个C++项目中，并在CMakeLists.txt中添加如下配置。

```cmake
add_subdirectory(${PROJECT_SOURCE_DIR}/Logger) # 项目的存放位置
target_link_libraries(executable_name Utils::Logger) # 链接库
```

在项目中只需要引用一个头文件即可，命名空间为`Utils::Logger`。
```c++
#include "Utils/Logger.hpp"

using namespace Utils::Logger;
```

## 使用示例

编写测试程序如下

```c++
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
```

### 输出示例

```
[2023-08-25 14:35:12.345] [INFO] System started. Version: 1.2 
[2023-08-25 14:35:12.347] [DEBUG] User Alice logged in from 192.168.1.10 
[2023-08-25 14:35:12.350] [ERROR] Failed to connect database!
```

## 高级配置

### 文件日志策略

```c++
// 参数：文件路径
auto file_policy = std::make_shared<FileLogPolicy>("app.log"); // 文件路径
logger.AddPolicy(file_policy);
```

### 手动刷新

```c++
logger.Flush(); // 强制立即写入所有缓冲日志
```

### 日志等级

```c++
logger.Trace("Detailed trace info"); 
logger.Debug("Debugging information"); 
logger.Info("System status update"); 
logger.Warning("Potential issue detected"); 
logger.Error("Critical operation failed");
```

## 性能指标

测试环境：
```
OS: Ubuntu 24.04.2 LTS x86_64
CPU: 13th Gen Intel i5-1340P (16) @ 4.600GHz
Memory: 32GB DDR4
```
| 场景 | 吞吐量          |
|------|--------------|
| 纯控制台输出 | 200,000条/秒   |
| 纯文件输出 | 1,200,000条/秒 |

## 注意事项
1. 确保所有日志策略对象在销毁前保持有效
2. 文件路径需要写入权限
3. 终端需支持ANSI颜色转义码
4. 推荐使用C++20或更高版本编译器

## TODO
- [ ] 按时间/大小自动分割日志文件
- [ ] 实现日志等级动态过滤
- [ ] 性能优化：考虑使用无锁队列替代mutex锁


欢迎通过Issue提交建议！
> Made by Motues with ❤️