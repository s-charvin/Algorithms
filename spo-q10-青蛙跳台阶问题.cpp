/**
 * 题目：青蛙跳台阶问题
 * - 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * - 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 * 链接:
 * - https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
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

/**
 * 此类求 多少种可能性 的题目一般都有递推性质, 即  f(n) 和  f(n−1) …  f(1) 之间是有联系的。
 * 想要找递推关系, 可以从后往前推
 * 假设跳完 n 级台阶有 f(n) 种跳法,
 * 那么如果还需要最后一跳, 才能到达第 n 阶, 此时青蛙仅有两种可能的跳法, 即需要跳 1 阶 或 2 阶
 * 如果是需要跳 1 阶, 说明青蛙已经跳完了 n-1 阶台阶, 因此此时青蛙已经经历的跳法有 f(n−1) 中可能
 * 如果是需要跳 2 阶, 说明青蛙已经跳完了 n-2 阶台阶, 因此此时青蛙已经经历的跳法有 f(n−2) 中可能
 * 而对于最后一跳来说, 青蛙跳 1 阶 或 2 阶的可能都有, 因此可知 f(n) = f(n−1) + f(n−2)
 */

/**动态规划
 * 转移方程: dp[n]=dp[n-1]+dp[n−2]
 * 初始状态: dp[0]=1, dp[1]=1
 * 返回值: dp[n]
 */
int numWays(int n)
{
    /* 设置计算初值和求和的初值 */
    int a = 1, b = 1, sum = 0;
    // 当 n>1 时才会进入循环，所以 for 循环算的是 n 从 2 项到 n+1 项的值
    for (int i = 2; i <= n + 1; i++)
    {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    // 由于多算一次，所以返回的是a，不是b
    return a;
}