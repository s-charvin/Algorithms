/**
 * 题目：和为s的两个数字
 * - 输入一个递增排序的数组和一个数字 s,
 * - 在数组中查找两个数, 使得它们的和正好是s.
 * - 如果有多对数字的和等于s, 则输出任意一对即可.
 * 链接:
 * - https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * 考察:
 * - 双指针
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
 * 哈希表暴力存储法
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    if (!nums.size())
        return vector<int>{};
    unordered_map<int, int> d;
    for (auto num : nums)
    {
        if (d.find(num) != d.end())
            return vector<int>{num, target - num};
        d.insert(pair(target - num, num));
    }
    return vector<int>{};
}

/**
 * 对撞双指针
 * 因为 nums 是排序数组, 因此可以通过双指针分别指向最小和最大值,
 * 然后以其中的最小值或者最大值为基准, 去舍弃不需要的值, 缩减寻找范围
 * - 如果最大的加最小的比 target 大, 所以最大的数不可能找到互相求和为 target 的值, 因此舍弃掉.
 * - 如果最小的加最大的都比 target 小, 所以最小的数不可能找到互相求和为 target 的值, 因此舍弃掉.
 * - 如果最小的加最大的等于 target, 就是说找到了.
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int s = nums[i] + nums[j];
        if (s < target)
            i++;
        else if (s > target)
            j--;
        else
            return vector<int>{nums[i], nums[j]};
    }
    return vector<int>{};
}