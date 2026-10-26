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

// F08: FL 北向先行后左转
TEST(ExecutorFastTest, should_move_north_then_turn_west_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FL");
    // then
    const Pose target{2, -2, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// F09: FL 西向先行后左转
TEST(ExecutorFastTest, should_move_west_then_turn_south_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FL");
    // then
    const Pose target{1, -3, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// F10: FL 南向先行后左转
TEST(ExecutorFastTest, should_move_south_then_turn_east_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FL");
    // then
    const Pose target{2, -4, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// F11: FR 南向先行后右转
TEST(ExecutorFastTest, should_move_south_then_turn_west_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FR");
    // then
    const Pose target{2, -4, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// F12: FR 西向先行后右转
TEST(ExecutorFastTest, should_move_west_then_turn_north_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FR");
    // then
    const Pose target{1, -3, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// F13: FR 北向先行后右转
TEST(ExecutorFastTest, should_move_north_then_turn_east_when_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FR");
    // then
    const Pose target{2, -2, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// F14: F 本身不移动与不转向
TEST(ExecutorFastTest, should_toggle_fast_without_changing_pose)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("F");
    // then
    const Pose target{2, -3, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// F15: FFF 奇数次切换后加速
TEST(ExecutorFastTest, should_stay_fast_after_three_toggles)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FFFM");
    // then
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
