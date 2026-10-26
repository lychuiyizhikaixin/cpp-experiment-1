#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas {

// F01: FM 东向加速移动
TEST(ExecutorFastTest, should_move_two_steps_east_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// F02: FL 东向先行后左转
TEST(ExecutorFastTest, should_move_east_then_turn_north_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
