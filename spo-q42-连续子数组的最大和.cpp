/**
 * 题目：连续子数组的最大和
 * - 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * - 要求时间复杂度为 O(n)。
 * 链接:
 * - https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
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
 * 此类求最大和的题目一般都有递推性质, 即  f(n) 和  f(n−1) …  f(1) 之间是有联系的。
 * 想要找递推关系, 可以从后往前推
 *
 * 假设完整数组 n 个数据中的子数组的最大和为 f(n)
 * 则其从后往前推的 n-1 个数据中子数组的最大和为 f(n-1)
 *
 * 如果, 在已经知道了前 n-1 个数据中子数组的最大和的情况下, 获得了第 n 个数据
 * 想要重新获得完整数组 n 个数据中的所有子数组中的最大和,
 * 需要判断与当前第 n 个值构成的所有的连续子数组的和是否有更大的, 有则替换, 没有则不变
 *
 * 因此就需要去获得当前第 n 个值构成连续的所有子数组的和, 然后找出最大的
 * 通过暴力求解的方法肯定不行, 时间复杂度太大了, 这里可以再次利用动态规划的方法进行优化
 *
 * 假设完整数组 n 个数据中, 包含第 n 个值的连续子数组的最大和为 g(n)
 * 则其从后往前推的 n-1 个数据中, 包含第 n-1 个值的连续子数组的最大和为 g(n-1)
 *
 * 如果, 在已经知道了 g(n-1) 的情况下, 获得了第 n 个数据
 * 想要重新获得 g(n), 需要考虑第 n 个数据是否需要被达到 g(n-1) 的连续子数组包含
 * 也就是说, 如果 g(n-1) 本身就小于零, 如果包含了第 n 个数据, 那他就一定不会是最大和
 * 要么因为加上负值变得更小, 要么因为加上正值, 使得还不如第 n 个数据单干强
 * 而如果 g(n-1) 本身就大于零, 如果包含了第 n 个数据, 要么因为加上正值, 变得更大了
 * 要么加上负值, 也要比第 n 个数据单干强
 * 用公式总结上面的其实就一个: g(n) = max( nums[n], g(n-1) + nums[n]), 选最大的就好了
 *
 * 因为以上两个动态规划的遍历顺序是一样的, 都是把输入的完整数组从前往后都遍历完
 * 因此可以按照先后顺序, 在一次动态规划的遍历中完成, 也就是说时间复杂度 O(n)
 * 总结公式如下:
 * g(n) = max( g(n-1), g(n-1) + nums[n])
 * f(n) = max(f[n−1], g(n))
 *
 */

/**
 * 转移方程: g(n) = max( nums[n], g(n-1) + nums[n]), f(n) = max(f[n−1], g(n))
 * 初始状态: f[0] = nums[0], g(0)= nums[0]
 * 返回值: dp[n-1]
 */

int maxSubArray(vector<int> &nums)
{
    if (!nums.size())
        return 0;

    int pre = nums[0], maxNum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        pre = max(pre + nums[i], nums[i]);

        maxNum = max(maxNum, pre);
    }
    return maxNum;
}