#pragma once

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

    // 虚析构函数
    virtual ~Executor()
    {
    }

protected:
    // 枚举表示四个方向
    enum Direction {
        N = 0,  // North
        E = 1,  // East
        S = 2,  // South
        W = 3   // West
    };

    int x, y;           // 车的位置坐标
    Direction heading;  // 车的朝向
};

}  // namespace adas