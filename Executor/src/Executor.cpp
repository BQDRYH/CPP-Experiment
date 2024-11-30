#include "Executor.h"

namespace adas
{

std::string Executor::GetCurrentStatus()
{
    char headingChar = DirectionToChar(heading);
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + headingChar + ")";
}

void Executor::ExecuteInstructions(const std::string& instructions)
{
    for (char command : instructions) {
        switch (command) {
        case 'M':
            if (isAccelerating) {
                MoveForward();
            }
            MoveForward();
            break;
        case 'L':
            if (isAccelerating) {
                MoveForward();
                TurnLeft();
            } else {
                TurnLeft();
            }
            break;
        case 'R':
            if (isAccelerating) {
                MoveForward();
                TurnRight();
            } else {
                TurnRight();
            }
            break;
        case 'F':
            ToggleAcceleration();
            break;
        default:
            throw std::invalid_argument("Invalid command");
        }
    }
}

char Executor::DirectionToChar(Direction dir)
{
    switch (dir) {
    case N:
        return 'N';
    case E:
        return 'E';
    case S:
        return 'S';
    case W:
        return 'W';
    default:
        throw std::invalid_argument("Invalid direction");
    }
}

void Executor::MoveForward()
{
    switch (heading) {
    case N:
        y++;
        break;  // 向北走，y增加
    case S:
        y--;
        break;  // 向南走，y减少
    case E:
        x++;
        break;  // 向东走，x增加
    case W:
        x--;
        break;  // 向西走，x减少
    default:
        throw std::logic_error("Invalid direction for move");
    }
}

void Executor::TurnLeft()
{
    heading = static_cast<Direction>((heading + 3) % 4);  // 左转即逆时针90度
}

void Executor::TurnRight()
{
    heading = static_cast<Direction>((heading + 1) % 4);  // 右转即顺时针90度
}

void Executor::ToggleAcceleration()
{
    isAccelerating = !isAccelerating;
}

}  // namespace adas