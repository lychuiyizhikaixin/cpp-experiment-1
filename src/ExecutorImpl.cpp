#include "ExecutorImpl.hpp"
#include <new>

namespace adas {
Executor* Executor::NewExecutor(const Pose& initialPose) noexcept
{
    return new (std::nothrow) ExecutorImpl(initialPose);
}
ExecutorImpl::ExecutorImpl(const Pose& initialPose) noexcept : pose(initialPose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const char command : commands) {
        if (command == 'M') {
            if (pose.heading == 'E') {
                ++pose.x;
            }
            else if (pose.heading == 'W') {
                --pose.x;
            }
            else if (pose.heading == 'N') {
                ++pose.y;
            }
            else if (pose.heading == 'S') {
                --pose.y;
            }
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
