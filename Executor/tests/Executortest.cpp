#include <gtest/gtest.h>

#include "Executor.h"

namespace adas
{

TEST(ExecutorTest, test1)
{
    // 测试1: 默认初始化
    Executor executor1;
    ASSERT_EQ(executor1.GetCurrentStatus(), "(0, 0, N)");
}

TEST(ExecutorTest, test2)
{
    // 测试2: 指令 "M"
    Executor executor2(0, 0, 'N');
    executor2.ExecuteInstructions("M");
    ASSERT_EQ(executor2.GetCurrentStatus(), "(0, 1, N)");
}

TEST(ExecutorTest, test3)
{
    // 测试3: 指令 "L"
    Executor executor3(0, 0, 'N');
    executor3.ExecuteInstructions("L");
    ASSERT_EQ(executor3.GetCurrentStatus(), "(0, 0, W)");
}

TEST(ExecutorTest, test4)
{
    // 测试4: 指令 "R"
    Executor executor4(0, 0, 'N');
    executor4.ExecuteInstructions("R");
    ASSERT_EQ(executor4.GetCurrentStatus(), "(0, 0, E)");
}

TEST(ExecutorTest, test5)
{
    // 测试5: 指令 "MMR"
    Executor executor5(1, 0, 'E');  // 自定义初始位置
    executor5.ExecuteInstructions("MMR");
    ASSERT_EQ(executor5.GetCurrentStatus(), "(3, 0, S)");
}

TEST(ExecutorTest, test6)
{
    // 测试6: 指令 "MMMLM"
    Executor executor6(2, 3, 'W');  // 自定义初始位置
    executor6.ExecuteInstructions("MMMLM");
    ASSERT_EQ(executor6.GetCurrentStatus(), "(-1, 2, S)");
}

TEST(ExecutorTest, test7)
{
    // 测试7: 指令 "RMMMLML"
    Executor executor7(0, 0, 'S');  // 自定义初始位置
    executor7.ExecuteInstructions("RMMMLML");
    ASSERT_EQ(executor7.GetCurrentStatus(), "(-3, -1, E)");
}

}  // namespace adas