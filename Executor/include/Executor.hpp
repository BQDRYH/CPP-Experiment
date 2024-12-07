#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace adas
{

class Executor
{
public:
    // 默认构造函数
    Executor() = default;

    // 虚析构函数
    virtual ~Executor() = default;
};

}  // namespace adas