#include "PoseHandler.hpp"

namespace adas
{

PoseHandler::PoseHandler(int x, int y, char heading) noexcept
{
    this->x = x;
    this->y = y;
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
    }
    this->isFast = false;
}

char PoseHandler::DirectionToChar(Direction dir) noexcept
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
        return '?';
    }
}

void PoseHandler::MoveForward() noexcept
{
    switch (heading) {
    case N:
        y++;
        break;
    case S:
        y--;
        break;
    case E:
        x++;
        break;
    case W:
        x--;
        break;
    }
}

void PoseHandler::TurnLeft() noexcept
{
    heading = static_cast<Direction>((heading + 3) % 4);
}

void PoseHandler::TurnRight() noexcept
{
    heading = static_cast<Direction>((heading + 1) % 4);
}

void PoseHandler::ToggleFast() noexcept
{
    isFast = !isFast;
}

bool PoseHandler::IsFast() const noexcept
{
    return isFast;
}

std::string PoseHandler::GetCurrentStatus() noexcept
{
    char headingChar = DirectionToChar(heading);
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + headingChar + ")";
}

}  // namespace adas