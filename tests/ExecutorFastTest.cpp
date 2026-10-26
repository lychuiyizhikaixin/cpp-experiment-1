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

// F16: FMFM 取消后恢复一步
TEST(ExecutorFastTest, should_restore_normal_move_after_fast_move)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FMFM");
    // then
    const Pose target{0, 3, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// F17: 跨调用保持加速与空输入
TEST(ExecutorFastTest, should_preserve_fast_state_across_calls_and_empty_input)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("F");
    executor->Execute("M");
    ASSERT_EQ((Pose{0, 2, 'N'}), executor->Query());
    executor->Execute("");
    ASSERT_EQ((Pose{0, 2, 'N'}), executor->Query());
    executor->Execute("RM");
    ASSERT_EQ((Pose{2, 3, 'E'}), executor->Query());
    executor->Execute("F");
    executor->Execute("M");
    // then
    const Pose target{3, 3, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// F18: 课件完整加速轨迹
TEST(ExecutorFastTest, should_follow_the_course_fast_command_route)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FMLMLM");
    // Verify the course route again in batches with explicit intermediate poses.
    std::unique_ptr<Executor> staged(Executor::NewExecutor());
    ASSERT_NE(nullptr, staged);
    staged->Execute("F");
    ASSERT_EQ((Pose{0, 0, 'N'}), staged->Query());
    staged->Execute("M");
    ASSERT_EQ((Pose{0, 2, 'N'}), staged->Query());
    staged->Execute("L");
    ASSERT_EQ((Pose{0, 3, 'W'}), staged->Query());
    staged->Execute("M");
    ASSERT_EQ((Pose{-2, 3, 'W'}), staged->Query());
    staged->Execute("L");
    ASSERT_EQ((Pose{-3, 3, 'S'}), staged->Query());
    staged->Execute("M");
    ASSERT_EQ((Pose{-3, 1, 'S'}), staged->Query());
    // then
    const Pose target{-3, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// F19: 不同执行器加速状态隔离
TEST(ExecutorFastTest, should_keep_fast_state_independent_between_executors)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    std::unique_ptr<Executor> normal(Executor::NewExecutor());
    ASSERT_NE(nullptr, normal);
    executor->Execute("FM");
    normal->Execute("M");
    ASSERT_EQ((Pose{0, 1, 'N'}), normal->Query());
    // then
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// F20: FF 取消后转向保持原地
TEST(ExecutorFastTest, should_turn_in_place_after_cancelling_fast)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("FF");
    executor->Execute("L");
    ASSERT_EQ((Pose{2, -3, 'W'}), executor->Query());
    executor->Execute("R");
    // then
    const Pose target{2, -3, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
