/**
 * @file spo-q03-数组中重复的数字.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：数组中重复的数字
 * - 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * - 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
 * - 请找出数组中任意一个重复的数字。
 * 链接:
 * - https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
 * 考察:
 * - 查找算法
 * - 需要找到一种方法记录数字的出现清空
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
using namespace std;

/**遍历数组
 * 用无序的哈希表记录已经遇到的数字, 之后判断遇到的数字是否已经被哈希表记录即可
 */

int findRepeatNumber(vector<int> &nums)
{
    unordered_map<int, bool> map; /* 构建空哈希表 */
    for (int num : nums)
    {
        if (map[num])    /* 判断哈希表中是否有了当前的数字 num */
            return num;  /* 是已经遇到过的, 就返回此数字 */
        map[num] = true; /* 是新数字就记录当前遇到的数字 */
    }
    return -1;
}

/**萝卜坑解法
 * 由题意可知, 输入的数组中数值大小都在 [0, n-1 ] 范围之内,
 * 即数值范围和数组索引的范围相同.
 * 而且, 题目并未要求不能对此数组进行修改, 因此这里使用反向思维,
 * 通过数组索引与值的对应关系: 每个值刚好与数组的索引值一一对应, 即一个萝卜一个坑.
 * 遍历数组所有索引, 将每个数值都放在与其相等的数组索引处,
 * 如果判断产生了多次交换, 则说明此值重复.
 */

int findRepeatNumber(vector<int> &nums)
{
    int i = 0;              /* 从数组索引 0 开始处理数组存储的值 */
    while (i < nums.size()) /* 遍历所有索引存放的值 */
    {
        if (nums[i] == i) /* 如果当前处理的数组值刚好与其索引相等, 说明此值已在对应索引位置, 且是第一次遇到 */
        {
            i++; /* 无需交换, 跳过, 进入下一个索引即可 */
            continue;
        }
        /**
         * 否则, 判断与此值相等的索引处是否已经存放了此值, 是则说明出现了重复, 返回此值
         */
        if (nums[nums[i]] == nums[i])
            return nums[i];
        /* 以上都不满足, 则说明与此值也是第一次遇到, 只不过不在正确的位置, 交换值, 将其放到正确位置即可 */
        swap(nums[i], nums[nums[i]]);
    }
    return -1;
}

/**萝卜坑解法2
 * 由题意可知, 输入的数组中数值大小都在 [0, n-1 ] 范围之内,
 * 即数值范围和数组索引的范围相同.
 * 而且, 题目并未要求不能对此数组进行修改, 因此这里使用反向思维,
 * 通过数组索引与值的对应关系: 每个值刚好与数组的索引值一一对应, 即一个萝卜一个坑.
 * 遍历数组所有值, 然后将与遇到的值相等的索引处的值, 加上一个非常大的数值 x , 这个数值 x 至少要 ≥ n
 * 最后, 判断是否有值刚好大于二倍的 x 即可.只有重复出现的数值才会出现这种现象.
 */

int findRepeatNumber(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int index = nums[i] % nums.size();
        nums[index] += nums.size();

        if (nums[index] >= 2 * nums.size())
        {
            return index;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 2 * nums.size())
        {
            return i;
        }
    }
    return -1;
}

/**排序数组
 * 将数组排序, 自然而然的, 重复数字就必定会在一起了, 然后顺序遍历即可
 */

int findRepeatNumber(vector<int> &nums)
{
    unordered_map<int, bool> map; /* 构建空哈希表 */
    for (int num : nums)
    {
        if (map[num])    /* 判断哈希表中是否有了当前的数字 num */
            return num;  /* 是已经遇到过的, 就返回此数字 */
        map[num] = true; /* 是新数字就记录当前遇到的数字 */
    }
    return -1;
}