#include <memory>

namespace adas
{

class ExecutorImpl;

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
};

}  // namespace adas