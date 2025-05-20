/**
 * 题目：把数字翻译成字符串
 * - 给定一个数字，我们按照如下规则把它翻译为字符串：
 * - 0 翻译成 "a" , 1 翻译成 “b”, ……, 11 翻译成 “l”, ……,25 翻译成 “z”.
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法.
 * 链接:
 * - https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 * 考察:
 * - 动态规划
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

/** 动态规划
 * 假设给定的数字共有 n 个单数字字符, 其翻译方法共有 f(n) 种
 * 可知其最后一个被翻译出来的字符, 可能消耗掉一个或者两个单数字字符
 * 如果消耗掉两个字符, 说明已经有 n-2 个字符被翻译了, 则其翻译方法共有 f(n-2) 种
 * 如果消耗掉一个字符, 说明已经有 n-1 个字符被翻译了, 则其翻译方法共有 f(n-1) 种
 * 这里可以得到一个简单公式 f(n) = f(n-1) + f(n-2)
 *
 * 但是由题意可知, 对于双数字翻译来说,
 * - 如果双数字大小超过了 25, 则只能使用单字符翻译,
 * - 如果双数字的起始位为 0 , 也只能使用单字符翻译,
 * 也就是说, 最后必须只消耗掉一个字符, 因此此时 f(n) = f(n-1)
 *
 */

/**
 * 转移方程:
 * - 25 < dp[n],dp[n-1] 或 dp[n-1] = "0"  时, f(n) = f(n-1)
 * - 其他: f(n) = f(n-1) + f(n-2)
 *
 * 初始状态: f(0)= 1, f(1) = 1
 * 返回值: f[n]
 */

int translateNum(int num)
{
    if (!num)
        return 1;

    string dp = to_string(num);
    /* 定义初始值 */
    int res = 1;
    int res_pre = 1;
    /* 临时变量, 用来存储本次位置的翻译方法,  */
    int temp;

    /* 从第二个单字符开始遍历, 知道最后一个单字符 */
    for (int i = 1; i < dp.size(); i++)
    {
        /* 获取当前位置和前一位置组成的数字 */
        auto subStr = dp.substr(i - 1, 2);

        /* 判断条件 */
        if ("25" < subStr || subStr < "10")
        {
            temp = res;
        }
        else
            temp = res + res_pre;

        res_pre = res;
        res = temp;
    }
    return res;
}