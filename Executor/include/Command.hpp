#pragma once

#include "PoseHandler.hpp"

namespace adas
{
// 虚基类
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

// 方法封装到类里
class MoveCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFast()) {
            poseHandler.MoveForward();
        }
        poseHandler.MoveForward();
    }
};

class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFast()) {
            poseHandler.MoveForward();
        }
        poseHandler.TurnLeft();
    }
};

class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.IsFast()) {
            poseHandler.MoveForward();
        }
        poseHandler.TurnRight();
    }
};

class ToggleFastCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        poseHandler.ToggleFast();
    }
};
}  // namespace adas