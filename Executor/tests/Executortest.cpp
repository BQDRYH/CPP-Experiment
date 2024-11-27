#include <gtest/gtest.h>

#include "Executor.h"

namespace adas
{

// 默认初始化测试
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    Executor executor;
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, N)");
}

// 移动指令（M）测试用例
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("M");
    ASSERT_EQ(executor.GetCurrentStatus(), "(1, 0, E)");
}

TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    Executor executor(0, 0, 'W');
    executor.ExecuteInstructions("M");
    ASSERT_EQ(executor.GetCurrentStatus(), "(-1, 0, W)");
}

TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    Executor executor(0, 0, 'N');
    executor.ExecuteInstructions("M");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 1, N)");
}

TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    Executor executor(0, 0, 'S');
    executor.ExecuteInstructions("M");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, -1, S)");
}

// 左转指令（L）测试用例
TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("L");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, N)");
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    Executor executor(0, 0, 'N');
    executor.ExecuteInstructions("L");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, W)");
}

TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    Executor executor(0, 0, 'W');
    executor.ExecuteInstructions("L");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, S)");
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    Executor executor(0, 0, 'S');
    executor.ExecuteInstructions("L");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, E)");
}

// 右转指令（R）测试用例
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("R");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, S)");
}

TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_S)
{
    Executor executor(0, 0, 'S');
    executor.ExecuteInstructions("R");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, W)");
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_W)
{
    Executor executor(0, 0, 'W');
    executor.ExecuteInstructions("R");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, N)");
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_N)
{
    Executor executor(0, 0, 'N');
    executor.ExecuteInstructions("R");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 0, E)");
}

// 组合指令测试用例
TEST(ExecutorTest, should_handle_multiple_instructions_correctly)
{
    Executor executor(1, 0, 'E');
    executor.ExecuteInstructions("MMR");
    ASSERT_EQ(executor.GetCurrentStatus(), "(3, 0, S)");
}

TEST(ExecutorTest, should_handle_multiple_instructions_correctly_2)
{
    Executor executor(2, 3, 'W');
    executor.ExecuteInstructions("MMMLM");
    ASSERT_EQ(executor.GetCurrentStatus(), "(-1, 2, S)");
}

TEST(ExecutorTest, should_handle_multiple_instructions_correctly_3)
{
    Executor executor(0, 0, 'S');
    executor.ExecuteInstructions("RMMMLML");
    ASSERT_EQ(executor.GetCurrentStatus(), "(-3, -1, E)");
}

}  // namespace adas