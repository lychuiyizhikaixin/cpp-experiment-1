#include <gtest/gtest.h>
#include <memory>
#include <ostream>
#include <tuple>
#include "Executor.hpp"

namespace adas {
bool operator==(const Pose& lhs, const Pose& rhs)
{
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
void PrintTo(const Pose& pose, std::ostream* output)
{
    *output << "(" << pose.x << ", " << pose.y << ", " << pose.heading << ")";
}
}  // namespace adas

namespace adas {

// TC01: 初始化指定状态
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when: query before any command is executed.
    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// TC02: 默认初始化
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    ASSERT_NE(nullptr, executor);
    // when: query before any command is executed.
    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
