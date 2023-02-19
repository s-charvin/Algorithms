/**
 * @file spo-q53-0_n-1中缺失的数字II.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：0～n-1中缺失的数字II
 * - 一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，
 * - 并且每个数字都在范围 0～n-1 之内。
 * - 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，
 * - 请找出这个数字。
 * 链接:
 * - https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/?envType=study-plan&id=lcof
 * 考察:
 * - 查找算法
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */

#include <iostream>
#include <vector>

using namespace std;

/**二分法
 * 一个连续的递增数列, 其中间元素一定为头部和尾部元素的一半
 * 缺失的数字将数组分割为了两种数组, 左侧数组元素与索引对应, 右侧数组元素不与索引对应
 * 缺失的元素刚好为右侧数组元素第一个元素的索引值
 */
int missingNumber(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; /* 计算中间值位置 */
        if (nums[mid] == mid)             /* 当中值与其索引值相等时, 说明不等的区域在更右侧 */
            low = mid + 1;                /* low 会不断地去寻找不等区域 */
        else                              /* 当中值与其索引值不相等时, 说明相等的区域在左侧, 同样的不等区域的首位元素也在右侧 */
            high = mid - 1;               /* high 会不断地去寻找相等区域 */

        /* 直到遇到不等区域和相等区域的交界处 */
    }
    /**
     * 跳出时，变量 low 指向 “右子数组的首位元素”
     * 跳出时，变量 high 指向 “左子数组的末位元素”
     */
    return low;
}

/**暴力遍历
 * 遍历去寻找数组值刚好不与索引值相等的位置, 然后输出索引值
 *
 */
int missingNumber(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    for (int i = 0; i <= nums.size() - 1; i++)
    {
        if (nums[i] != i)
            return i;
    }
    return nums.size();
}

/** 哈希
 * 遍历去寻找数组值刚好不与索引值相等的位置, 然后输出索引值
 *
 */
int missingNumber(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    for (int i = 0; i <= nums.size() - 1; i++)
    {
        if (nums[i] != i)
            return i;
    }
    return nums.size();
}