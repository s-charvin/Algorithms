/**
 * @file spo-q21-调整数组顺序使奇数位于偶数前面.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：调整数组顺序使奇数位于偶数前面
 * - 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * - 使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
 * 链接:
 * - https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
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
 * 首尾双指针
 */
vector<int> exchange(vector<int> &nums)
{
    int ou = 0, ji = nums.size() - 1, temp = 0;
    while (ou <= ji)
    {
        if (nums[ou] % 2 == 0 && nums[ji] % 2 == 1)
        {
            temp = nums[ou];
            nums[ou] = nums[ji];
            nums[ji] = temp;
        }
        if (nums[ou] % 2 != 0)
        {
            ou++;
        }
        if (nums[ji] % 2 != 1)
        {
            ji--;
        }
    }
    return nums;
}

/**
 * 快慢双指针
 * fast 在前, low 在后.
 * fast 的作用是向前搜索奇数, low 的作用是指向下一个奇数应当存放的位置.
 */

vector<int> exchange(vector<int> &nums)
{
    int low = 0, fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] & 1)
        {
            swap(nums[low], nums[fast]);
            low++;
        }
        fast++;
    }
    return nums;
}
