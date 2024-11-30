#include <gtest/gtest.h>

#include "ExecutorImpl.hpp"

namespace adas
{

// 默认初始化测试
TEST(ExecutorImplTest, should_return_default_pose_when_without_init_and_command)
{
    ExecutorImpl ExecutorImpl;
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, N)");
}

// 移动指令（M）测试用例
TEST(ExecutorImplTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("M");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(1, 0, E)");
}

TEST(ExecutorImplTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    ExecutorImpl ExecutorImpl(0, 0, 'W');
    ExecutorImpl.ExecuteInstructions("M");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(-1, 0, W)");
}

TEST(ExecutorImplTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    ExecutorImpl ExecutorImpl(0, 0, 'N');
    ExecutorImpl.ExecuteInstructions("M");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 1, N)");
}

TEST(ExecutorImplTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    ExecutorImpl ExecutorImpl(0, 0, 'S');
    ExecutorImpl.ExecuteInstructions("M");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, -1, S)");
}

// 左转指令（L）测试用例
TEST(ExecutorImplTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("L");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, N)");
}

TEST(ExecutorImplTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    ExecutorImpl ExecutorImpl(0, 0, 'N');
    ExecutorImpl.ExecuteInstructions("L");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, W)");
}

TEST(ExecutorImplTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    ExecutorImpl ExecutorImpl(0, 0, 'W');
    ExecutorImpl.ExecuteInstructions("L");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, S)");
}

TEST(ExecutorImplTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    ExecutorImpl ExecutorImpl(0, 0, 'S');
    ExecutorImpl.ExecuteInstructions("L");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, E)");
}

// 右转指令（R）测试用例
TEST(ExecutorImplTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("R");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, S)");
}

TEST(ExecutorImplTest, should_return_facing_N_given_command_is_R_and_facing_is_S)
{
    ExecutorImpl ExecutorImpl(0, 0, 'S');
    ExecutorImpl.ExecuteInstructions("R");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, W)");
}

TEST(ExecutorImplTest, should_return_facing_E_given_command_is_R_and_facing_is_W)
{
    ExecutorImpl ExecutorImpl(0, 0, 'W');
    ExecutorImpl.ExecuteInstructions("R");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, N)");
}

TEST(ExecutorImplTest, should_return_facing_W_given_command_is_R_and_facing_is_N)
{
    ExecutorImpl ExecutorImpl(0, 0, 'N');
    ExecutorImpl.ExecuteInstructions("R");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 0, E)");
}

// 组合指令测试用例
TEST(ExecutorImplTest, should_handle_multiple_instructions_correctly)
{
    ExecutorImpl ExecutorImpl(1, 0, 'E');
    ExecutorImpl.ExecuteInstructions("MMR");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(3, 0, S)");
}

TEST(ExecutorImplTest, should_handle_multiple_instructions_correctly_2)
{
    ExecutorImpl ExecutorImpl(2, 3, 'W');
    ExecutorImpl.ExecuteInstructions("MMMLM");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(-1, 2, S)");
}

TEST(ExecutorImplTest, should_handle_multiple_instructions_correctly_3)
{
    ExecutorImpl ExecutorImpl(0, 0, 'S');
    ExecutorImpl.ExecuteInstructions("RMMMLML");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(-3, -1, E)");
}

// 加速指令（F）测试用例
TEST(ExecutorImplTest, should_toggle_acceleration_with_F)
{
    ExecutorImpl ExecutorImpl(0, 0, 'N');
    ExecutorImpl.ExecuteInstructions("F");
    ExecutorImpl.ExecuteInstructions("M");
    ExecutorImpl.ExecuteInstructions("F");
    ExecutorImpl.ExecuteInstructions("M");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 3, N)");  // 验证加速后前进2格，取消加速后前进1格
}

// 加速状态下的移动指令（M）测试用例
TEST(ExecutorImplTest, should_move_forward_2_steps_in_acceleration_mode)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("FM");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(2, 0, E)");  // 验证加速状态下前进2格
}

// 加速状态下的左转指令（L）测试用例
TEST(ExecutorImplTest, should_move_forward_and_turn_left_in_acceleration_mode)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("FL");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(1, 0, N)");  // 验证加速状态下先前进1格，然后左转90度
}

// 加速状态下的右转指令（R）测试用例
TEST(ExecutorImplTest, should_move_forward_and_turn_right_in_acceleration_mode)
{
    ExecutorImpl ExecutorImpl(0, 0, 'E');
    ExecutorImpl.ExecuteInstructions("FR");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(1, 0, S)");  // 验证加速状态下先前进1格，然后右转90度
}

// 加速状态下的组合指令测试用例
TEST(ExecutorImplTest, should_handle_acceleration_and_commands_correctly)
{
    ExecutorImpl ExecutorImpl(0, 0, 'N');
    ExecutorImpl.ExecuteInstructions("FMML");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(0, 5, W)");  // 验证加速状态下的组合指令
}

TEST(ExecutorImplTest, should_handle_acceleration_and_commands_correctly_2)
{
    ExecutorImpl ExecutorImpl(0, 0, 'W');
    ExecutorImpl.ExecuteInstructions("FRMFM");
    ASSERT_EQ(ExecutorImpl.GetCurrentStatus(), "(-1, 3, N)");  // 验证加速状态下的组合指令和取消加速
}

}  // namespace adas