/**
 * 题目：斐波那契数列
 * - 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
 * - 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
 * - 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 * 链接:
 * - https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/
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
 * 递归求解, 有重复计算, 导致时间不够, 因此需要通过存储计算结果, 减少计算
 */

static int mod = (int)1e9 + 7;
static int N = 110;
static int *cache = new int[N];

int fib(int n)
{
    if (n <= 1)
        return n;
    if (cache[n] != 0)
        return cache[n];
    cache[n] = fib(n - 1) + fib(n - 2);
    cache[n] %= mod;
    return cache[n];
}

/**
 * 动态规划(数学递推求解)
 * 转移方程: dp[n]=dp[n-1]+dp[n−2]
 * 初始状态: dp[0]=0, dp[1]=1
 *   返回值: dp[n]
 */

int fib(int n)
{
    /* 设置计算初值和求和的初值 */
    int a = 0, b = 1, sum = 0;
    // 当 n>1 时才会进入循环，所以 for 循环算的是 n 从 2 项到 n+1 项的值
    for (int i = 2; i <= n + 1; i++)
    {
        /* 循环求余法原理: (x+y) % p=(x % p + y % p) % p */
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    // 由于多算一次，所以返回的是a，不是b
    return a;
}

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }
    int *dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 1000000007;
    }
    return dp[n];
}

/**
 * 矩阵快速幂(矩阵方程)
 * 转移方程: dp[i+1]=dp[i]+dp[i−1]
 * 初始状态: dp[0]=0, dp[1]=1
 *   返回值: dp[n]
 */

const int MOD = 1000000007;

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }
    vector<vector<long>> q{{1, 1}, {1, 0}};
    vector<vector<long>> res = pow(q, n - 1);
    return res[0][0];
}

vector<vector<long>> pow(vector<vector<long>> &a, int n)
{
    vector<vector<long>> ret{{1, 0}, {0, 1}};
    while (n > 0)
    {
        if (n & 1)
        {
            ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}

vector<vector<long>> multiply(vector<vector<long>> &a, vector<vector<long>> &b)
{
    vector<vector<long>> c{{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
        }
    }
    return c;
}
