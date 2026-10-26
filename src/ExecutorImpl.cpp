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
            MoveCommand{}.DoOperate(*this);
        }
        else if (command == 'L') {
            TurnLeft();
        }
        else if (command == 'R') {
            TurnRight();
        }
    }
}
void ExecutorImpl::Move() noexcept
{
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
void ExecutorImpl::TurnLeft() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'N';
    }
    else if (pose.heading == 'N') {
        pose.heading = 'W';
    }
    else if (pose.heading == 'W') {
        pose.heading = 'S';
    }
    else if (pose.heading == 'S') {
        pose.heading = 'E';
    }
}
void ExecutorImpl::TurnRight() noexcept
{
    if (pose.heading == 'E') {
        pose.heading = 'S';
    }
    else if (pose.heading == 'S') {
        pose.heading = 'W';
    }
    else if (pose.heading == 'W') {
        pose.heading = 'N';
    }
    else if (pose.heading == 'N') {
        pose.heading = 'E';
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas
