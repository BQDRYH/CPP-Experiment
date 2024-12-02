#include "ExecutorImpl.hpp"

namespace adas
{

ExecutorImpl::ExecutorImpl(int x, int y, char heading)
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
    default:
        throw std::invalid_argument("Invalid heading");
    }
    this->isFast = false;
}

std::string ExecutorImpl::GetCurrentStatus()
{
    char headingChar = DirectionToChar(heading);
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + headingChar + ")";
}

void ExecutorImpl::ExecuteInstructions(const std::string& instructions)
{
    for (char command : instructions) {
        std::unique_ptr<ICommand> cmd;
        switch (command) {
        case 'M':
            cmd = std::make_unique<MoveCommand>();
            break;
        case 'L':
            cmd = std::make_unique<TurnLeftCommand>();
            break;
        case 'R':
            cmd = std::make_unique<TurnRightCommand>();
            break;
        case 'F':
            cmd = std::make_unique<FastCommand>();
            break;
        default:
            throw std::invalid_argument("Invalid command");
        }
        if (cmd) {
            cmd->DoOperate(*this);
        }
    }
}

char ExecutorImpl::DirectionToChar(Direction dir)
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

void ExecutorImpl::MoveForward()
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
    default:
        throw std::logic_error("Invalid direction for move");
    }
}

void ExecutorImpl::TurnLeft()
{
    heading = static_cast<Direction>((heading + 3) % 4);
}

void ExecutorImpl::TurnRight()
{
    heading = static_cast<Direction>((heading + 1) % 4);
}

void ExecutorImpl::ToggleFast()
{
    isFast = !isFast;
}

bool ExecutorImpl::IsFast()
{
    return isFast;
}

void ExecutorImpl::MoveCommand::DoOperate(ExecutorImpl& executor) const noexcept
{
    if (executor.IsFast()) {
        executor.MoveForward();
    }
    executor.MoveForward();
}

void ExecutorImpl::TurnLeftCommand::DoOperate(ExecutorImpl& executor) const noexcept
{
    if (executor.IsFast()) {
        executor.MoveForward();
    }
    executor.TurnLeft();
}

void ExecutorImpl::TurnRightCommand::DoOperate(ExecutorImpl& executor) const noexcept
{
    if (executor.IsFast()) {
        executor.MoveForward();
    }
    executor.TurnRight();
}

void ExecutorImpl::FastCommand::DoOperate(ExecutorImpl& executor) const noexcept
{
    executor.ToggleFast();
}

}  // namespace adas