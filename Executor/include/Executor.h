#pragma once

#include <stdexcept>
#include <string>

namespace adas
{

class Executor
{
public:
    // 构造函数，初始化车的位置和朝向
    Executor(int x = 0, int y = 0, char heading = 'N')
    {
        this->x = x;
        this->y = y;
        // 将字符朝向转为枚举
        switch (heading) {
        case 'N':
            this->heading = N;
            break;
        case 'E':
            this->heading = E;
            break;
        case 'S':
            this->heading = S;
            break;
        case 'W':
            this->heading = W;
            break;
        default:
            throw std::invalid_argument("Invalid heading");
        }
    }

    // 执行批量指令
    void ExecuteInstructions(const std::string& instructions);

    // 获取当前的坐标和朝向
    std::string GetCurrentStatus();

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

    // 将方向枚举转为字符
    char DirectionToChar(Direction dir);

    // 前进1格
    void MoveForward();

    // 左转90度
    void TurnLeft();

    // 右转90度
    void TurnRight();
};

}  // namespace adas