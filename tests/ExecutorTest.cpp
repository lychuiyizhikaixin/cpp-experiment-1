#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

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

// TC03: 朝东前进一步
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("M");
    // then
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// TC04: 朝西前进一步
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("M");
    // then
    const Pose target{-1, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// TC05: 朝北前进一步
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("M");
    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// TC06: 朝南前进一步
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("M");
    // then
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// TC07: 朝东左转至北
TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("L");
    // then
    const Pose target{2, -3, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// TC08: 朝北左转至西
TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("L");
    // then
    const Pose target{2, -3, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// TC09: 朝西左转至南
TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("L");
    // then
    const Pose target{2, -3, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// TC10: 朝南左转至东
TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("L");
    // then
    const Pose target{2, -3, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// TC11: 朝东右转至南
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'E'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("R");
    // then
    const Pose target{2, -3, 'S'};
    ASSERT_EQ(target, executor->Query());
}

// TC12: 朝南右转至西
TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'S'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("R");
    // then
    const Pose target{2, -3, 'W'};
    ASSERT_EQ(target, executor->Query());
}

// TC13: 朝西右转至北
TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'W'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("R");
    // then
    const Pose target{2, -3, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// TC14: 朝北右转至东
TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({2, -3, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when
    executor->Execute("R");
    // then
    const Pose target{2, -3, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// TC15: 混合指令与连续调用
TEST(ExecutorTest, should_preserve_state_across_empty_and_mixed_command_batches)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    ASSERT_NE(nullptr, executor);
    // when: empty input leaves the state unchanged; later calls continue from it.
    executor->Execute("");
    ASSERT_EQ((Pose{0, 0, 'N'}), executor->Query());
    executor->Execute("MLM");
    ASSERT_EQ((Pose{-1, 1, 'W'}), executor->Query());
    executor->Execute("MRM");
    // then
    const Pose target{-2, 2, 'N'};
    ASSERT_EQ(target, executor->Query());
    ASSERT_EQ(target, executor->Query());  // Query has no side effects.
}
}  // namespace adas
