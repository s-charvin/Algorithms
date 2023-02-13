/**
 * @file spo-q53-在排序数组中查找数字 I.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：在排序数组中查找数字 I
 * * 统计一个数字在排序数组中出现的次数。
 * 链接: https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
 * *
 * 考察:
 * * 查找算法
 * * 查找元素出现的位置, 一般用二分法
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/**暴力查找法
 * Todo
 */

int search(vector<int> &nums, int target)
{
}

/**二分法查找
 *
 */

int search(vector<int> &nums, int target)
{

    std::upper_bound(nums.begin(), nums.end(), target) - std::lower_bound(nums.begin(), nums.end(), target);
}

/* 利用二分查找的思想, 寻找第一个*等于*目标值的元素 */
int GetLeftFirstPosition(std::vector<int> array, int low, int high, int key)
{

    if (low <= high && key <= array[high])
    {
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (array[mid] > key)
                high = mid - 1; /* 选择左侧小于等于 key 的区域 */
            else if (array[mid] < key)
                low = mid + 1; /* 选择右侧大于等于 key 的区域, 直至到最后一个元素 */

            else /* 如果中值刚好等于 key */
            {
                /** 如果中值等于 key, 且是第一个元素
                 * 或 mid 左侧的数不为目标数时返回其位置
                 */
                if ((mid == 0) || (array[mid - 1] != key))
                    return mid;
                /* 否则选择左侧小于等于 key 的区间 */
                high = mid - 1;
            }
        }
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

/* 利用二分查找的思想, 寻找最后一个等于目标值的元素 */

int GetRightLastPosition(std::vector<int> array, int low, int high, int key)
{

    if (low <= high && key <= array[high])
    {
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (array[mid] > key)
                high = mid - 1; /* 选择左侧小于等于 key 的区域 */
            else if (array[mid] < key)
                low = mid + 1; /* 选择右侧大于等于 key 的区域 */
            else
            {
                /* 如果中值等于 key, 且是最后一个元素
                    或 mid 右侧的数不为目标数时返回其位置
                  */
                if ((mid == array.size() - 1) || (array[mid + 1] != key))
                    return mid;
                /* 否则选择右侧大于等于 key 的区间 */
                low = mid + 1;
            }
        }
    }
    /* 当找不到值时, 即 high<0 或 low >= array.size() 或 high<low 时, 返回 -1 */
    return -1;
}

int search(vector<int> &nums, int target)
{
    int leftIdx = GetLeftFirstPosition(nums, 0, nums.size() - 1, target);
    int rightIdx = GetRightLastPosition(nums, leftIdx < 0 ? 0 : leftIdx, nums.size() - 1, target);
    if (leftIdx == -1 && rightIdx == -1)
        return 0;
    return (nums[leftIdx] == target && target == nums[rightIdx]) ? (rightIdx - leftIdx + 1) : 0;
}

int search(vector<int> &nums, int target)
{
    /* 搜索右边界 right */
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (nums[m] <= target)
            i = m + 1;
        else
            j = m - 1;
    }
    int right = i;
    /* 若数组中无 target ，则提前返回 */
    if (j >= 0 && nums[j] != target)
        return 0;
    /* 搜索左边界 right */
    i = 0;
    j = nums.size() - 1;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (nums[m] < target)
            i = m + 1;
        else
            j = m - 1;
    }
    int left = j;
    return right - left - 1;
}
