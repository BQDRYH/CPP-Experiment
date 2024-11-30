#include "ExecutorImpl.hpp"

namespace adas
{

Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) {
        switch (cmd) {
        case 'M':
            MoveForward();
            break;
        case 'L':
            TurnLeft();
            break;
        case 'R':
            TurnRight();
            break;
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}

void ExecutorImpl::TurnLeft()
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'W';
        break;
    case 'W':
        pose.heading = 'S';
        break;
    case 'S':
        pose.heading = 'E';
        break;
    case 'E':
        pose.heading = 'N';
        break;
    }
}

void ExecutorImpl::TurnRight()
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'E';
        break;
    case 'E':
        pose.heading = 'S';
        break;
    case 'S':
        pose.heading = 'W';
        break;
    case 'W':
        pose.heading = 'N';
        break;
    }
}

void ExecutorImpl::MoveForward()
{
    switch (pose.heading) {
    case 'N':
        ++pose.y;
        break;
    case 'S':
        --pose.y;
        break;
    case 'E':
        ++pose.x;
        break;
    case 'W':
        --pose.x;
        break;
    }
}

}  // namespace adas