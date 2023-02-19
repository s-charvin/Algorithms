/**
 * @file spo-q63-股票的最大利润.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：股票的最大利润
 * - 假设把某股票的价格按照时间先后顺序存储在数组中, 请问买卖该股票一次可能获得的最大利润是多少？
 * 链接:
 * - https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/
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
 * 此类求最大利润的题目一般都有递推性质, 即  f(n) 和  f(n−1) …  f(1) 之间是有联系的。
 * 想要找递推关系, 可以从后往前推
 *
 * 假设最后一日为 n , 则最后一日以来可能可以获得的最大利润为 f(n)
 * 那么如果向前推移一日, 在刚知道最后一日价格的时候, 想要计算最后一日的最大利润
 * 需要将倒数第二日之前可能可以获得的最大利润 f(n−1) 与最后一日价格能获得的最大利润作比较
 *
 * 最后一日价格能获得的最大利润, 可以由最后一日价格和前面所有日中的最低价格计算得出
 * 因此可以得到最后一日以来可能可以获得的最大利润公式: dp[n] = max( dp[n−1], dp[n] − min(dp[0:n-1]))
 * 因此如果从前往后的遍历所有价格, 就能计算出每一日之前所能获得的最大利润和最小价格
 * 并且只需要通过存储前一日所能获得的最大利润和最小价格, 即可获得当日的所能获得的最大利润
 */

/**
 * 转移方程: dp[n]=max(dp[n−1],dp[n]−min(dp[0:n-1]))
 * 初始状态: dp[0] = 0, dp[1] = max(dp[0],dp[1]−min(dp[0:0]))
 * 返回值: dp[n-1]
 */

int maxProfit(vector<int> &prices)
{
    if (!prices.size()) /* 处理空值 */
    {
        return 0;
    }
    /**
     * minValue, 用来存储从前往后遍历的时间段中遇到的最低价格
     * profit, 用来存储当前遍历到的时间的前一日之前能获得的最大利润
     *[..., minValue,... ,price1 , price2]
                                      ↑
     */
    int minValue = prices[0], profit = 0;
    for (int price : prices) /* 从头往后, 遍历所有日的价格 */
    {
        minValue = minValue > price ? price : minValue;
        profit = profit > (price - minValue) ? profit : (price - minValue);
    }
    return profit;
}

/**
 * 暴力遍历
 *
 */
int maxProfit(vector<int> &prices)
{
    int n = (int)prices.size(), ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            ans = max(ans, prices[j] - prices[i]);
        }
    }
    return ans;
}