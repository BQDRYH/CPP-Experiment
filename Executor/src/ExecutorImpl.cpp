#include "ExecutorImpl.hpp"

#include "Command.hpp"

namespace adas
{

void ExecutorImpl::ExecuteInstructions(const std::string& instructions) noexcept
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
            cmd = std::make_unique<ToggleFastCommand>();
            break;
        }
        if (cmd) {
            cmd->DoOperate(poseHandler);
        }
    }
}
std::string ExecutorImpl::GetCurrentStatus() noexcept
{
    return poseHandler.GetCurrentStatus();
}
}  // namespace adas