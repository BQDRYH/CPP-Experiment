#pragma once

#include "Executor.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(int x = 0, int y = 0, char heading = 'N') noexcept;

    void MoveForward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void ToggleFast(void) noexcept;
    bool IsFast(void) const noexcept;
    std::string GetCurrentStatus() noexcept;

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

    bool isFast;  // 是否处于加速状态

    char DirectionToChar(Direction dir) noexcept;
};
}  // namespace adas
