/**
 * @file spo-q11-旋转数组的最小数字.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：旋转数组的最小数字
 * - 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * - 给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，
 * - 并按上述情形进行了一次旋转。请返回旋转数组的最小元素。
 * - 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。  
 * - 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为
 * - 数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
 * 链接:
 * - https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 * 考察:
 * - 查找算法
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */

/**二分法
 * 在最小值右侧的元素，它们的值一定都小于等于 x；
 * 而在最小值左侧的元素，它们的值一定都大于等于 x。
 * 因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。
 *
 * 选择使用二分法, 需要找到能使任意中间值, 将计算区域分段的条件
 * 在这里, 对于可能是任意值的中间值, 仅当在与右区域最大值比较时才满足
 * 当中点值大于右侧值时, 中点一定在左侧排序区域
 * 当中点值雄小于右侧值时, 中点一定在右侧排序区域
 * 当中点值雄等于右侧值时, 只需要另作考虑
 */

#include <iostream>
#include <vector>

using namespace std;

int minArray(vector<int> &numbers)
{
    int low = 0, high = numbers.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (numbers[mid] > numbers[high]) /* 当中点值大于右侧值时, 中点一定在左侧排序区域 */
            low = mid + 1;
        else if (numbers[mid] < numbers[high]) /* 当中点值雄小于右侧值时, 中点一定在右侧排序区域 */
            high = mid;
        else /* 当中点值雄等于右侧值时, 缩小判断范围 */
            high--;
    }
    return numbers[low];
}

int minArray(vector<int> &numbers)
{
    int low = 0, high = numbers.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (numbers[mid] > numbers[high])
            low = mid + 1;
        else if (numbers[mid] < numbers[high])
            high = mid;
        else
        {
            int x = low;
            for (int k = low + 1; k < high; k++)
            {
                if (numbers[k] < numbers[x])
                    x = k;
            }
            return numbers[x];
        }
    }
    /* 当 low 与 high 重合的时候，找到最小值 */
    return numbers[low];
}

/** 迭代法
 *
 *
 */

int minArray(vector<int> &numbers)
{
    if (numbers.size() == 1)
        return numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < numbers[i - 1])
        {
            return numbers[i];
        }
    }
    // 没有找到这个转折点, 则数组为升序
    return numbers[0];
}
