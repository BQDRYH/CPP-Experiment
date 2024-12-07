#pragma once

#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{

class ExecutorImpl final : public Executor
{
public:
    ExecutorImpl(int x = 0, int y = 0, char heading = 'N') : poseHandler(x, y, heading)
    {
    }
    // 执行批量指令
    void ExecuteInstructions(const std::string& instructions) noexcept;

    std::string GetCurrentStatus() noexcept;

private:
    PoseHandler poseHandler;
};

}  // namespace adas