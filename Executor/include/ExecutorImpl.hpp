#pragma once

#include "Executor.hpp"
#include "ICommand.hpp"

namespace adas
{

class ExecutorImpl final : public Executor
{
public:
    // 构造函数，初始化车的位置和朝向
    ExecutorImpl(int x = 0, int y = 0, char heading = 'N');

    // 执行批量指令
    void ExecuteInstructions(const std::string& instructions) override;

    // 获取当前的坐标和朝向
    std::string GetCurrentStatus() override;

private:
    // 枚举表示四个方向
    enum Direction {
        N = 0,  // North
        E = 1,  // East
        S = 2,  // South
        W = 3   // West
    };

    int x, y;  // 车的位置坐标

    Direction heading;  // 车的朝向

    bool isAccelerating;  // 是否处于加速状态

    // 将方向枚举转为字符
    char DirectionToChar(Direction dir);

    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override;
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override;
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override;
    };

    // 前进1格或2格（根据加速状态）
    void MoveForward();

    // 左转90度
    void TurnLeft();

    // 右转90度
    void TurnRight();

    // 切换加速状态
    void ToggleAcceleration();
};

}  // namespace adas