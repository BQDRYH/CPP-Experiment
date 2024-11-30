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

// 加速指令（F）测试用例
TEST(ExecutorTest, should_toggle_acceleration_with_F)
{
    Executor executor(0, 0, 'N');
    executor.ExecuteInstructions("F");
    executor.ExecuteInstructions("M");
    executor.ExecuteInstructions("F");
    executor.ExecuteInstructions("M");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 3, N)");  // 验证加速后前进2格，取消加速后前进1格
}

// 加速状态下的移动指令（M）测试用例
TEST(ExecutorTest, should_move_forward_2_steps_in_acceleration_mode)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("FM");
    ASSERT_EQ(executor.GetCurrentStatus(), "(2, 0, E)");  // 验证加速状态下前进2格
}

// 加速状态下的左转指令（L）测试用例
TEST(ExecutorTest, should_move_forward_and_turn_left_in_acceleration_mode)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("FL");
    ASSERT_EQ(executor.GetCurrentStatus(), "(1, 0, N)");  // 验证加速状态下先前进1格，然后左转90度
}

// 加速状态下的右转指令（R）测试用例
TEST(ExecutorTest, should_move_forward_and_turn_right_in_acceleration_mode)
{
    Executor executor(0, 0, 'E');
    executor.ExecuteInstructions("FR");
    ASSERT_EQ(executor.GetCurrentStatus(), "(1, 0, S)");  // 验证加速状态下先前进1格，然后右转90度
}

// 加速状态下的组合指令测试用例
TEST(ExecutorTest, should_handle_acceleration_and_commands_correctly)
{
    Executor executor(0, 0, 'N');
    executor.ExecuteInstructions("FMML");
    ASSERT_EQ(executor.GetCurrentStatus(), "(0, 5, W)");  // 验证加速状态下的组合指令
}

TEST(ExecutorTest, should_handle_acceleration_and_commands_correctly_2)
{
    Executor executor(0, 0, 'W');
    executor.ExecuteInstructions("FRMFM");
    ASSERT_EQ(executor.GetCurrentStatus(), "(1, 3, N)");  // 验证加速状态下的组合指令和取消加速
}

}  // namespace adas