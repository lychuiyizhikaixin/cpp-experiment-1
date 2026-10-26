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

// F03: FR 东向先行后右转
TEST(ExecutorFastTest, should_move_east_then_turn_south_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FR");
    // then
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// F04: FFM 取消加速
TEST(ExecutorFastTest, should_move_one_step_north_after_two_fast_toggles)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FFM");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// F05: FM 西向加速移动
TEST(ExecutorFastTest, should_move_two_steps_west_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FM");
    // then
    const Pose target{0, -3, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// F06: FM 北向加速移动
TEST(ExecutorFastTest, should_move_two_steps_north_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// F07: FM 南向加速移动
TEST(ExecutorFastTest, should_move_two_steps_south_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, -5, 'S'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
