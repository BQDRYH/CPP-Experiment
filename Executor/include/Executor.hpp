#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace adas
{

class Executor
{
public:
    // 执行批量指令
    virtual void ExecuteInstructions(const std::string& instructions) = 0;

    // 获取当前的坐标和朝向
    virtual std::string GetCurrentStatus() = 0;

    // 默认构造函数
    Executor() = default;

    // 虚析构函数
    virtual ~Executor() = default;
};

}  // namespace adas