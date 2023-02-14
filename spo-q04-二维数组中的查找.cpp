/**
 * @file spo-q04-二维数组中的查找.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：二维数组中的查找
 * * 在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，
 * * 每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，
 * * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 链接:
 * * https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * 考察:
 * * 查找算法
 * 基本注意点
 * *
 * 高阶注意点
 * *
 */

/**
 * 题解思路:
 * 平常解决的问题都是一维数组, 对于二维数组呢, 要怎么办?
 * 二维比一维多了一个维度, 因此在解题时,
 * 若要考虑到二维数组的所有数据, 必然要在两个维度上都进行处理.
 *
 * 在不同维度进行什么处理?
 * 由题意可知此数组的行和列两个维度均满足顺序排序条件,
 * 顺序排序, 优先想到二分, 用二分去查找要的的值,, 肯定更快.
 * 否则就暴力查找.
 */

#include <iostream>
#include <vector>

using namespace std;

/**二分行(列)查找
 * 由于矩阵 matrix 中每一行(列)的元素都是升序排列的,
 * 因此我们可以对每一行(列)都使用一次二分查找,
 * 判断 target 是否在该行(列)中，从而判断 target 是否出现
 * 即对单一维度使用二分查找, 另一维度迭代
 */

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    for (const auto &row : matrix) /* 遍历所有指向行数组的指针 */
    {
        auto it = lower_bound(row.begin(), row.end(), target); /* 对行数据使用二分查找, 寻找第一个大于等于目标值的元素 */

        if (it != row.end() && *it == target) /* 判断 */
        {
            return true;
        }
    }
    return false;
}

/**二分对角线查找
 * 由于矩阵 matrix 中行列的元素都是升序排列的,
 * 因此我们可以对每一行和列都使用一次二分查找,
 * 判断 target 是否在该行或列中，从而判断 target 是否出现
 * 同时为了避免区域的重复查找, 可以通过沿对角线的方式迭代
 * 然后对相应的行和列分别使用二分查找验证目标值是否存在
 */

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    for (int i = 0; i != min(matrix.size(), matrix[0].size()); ++i)
    {
        if (binarySearchVerical(matrix[i], target) || binarySearchHorizon(matrix, i, target))
            return true;
    }
    return false;
}

bool binarySearchVerical(const vector<int> &vvec, int target)
{
    int low = 0, high = vvec.size() - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);

        if (vvec[mid] == target)
            return true;
        else if (vvec[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

bool binarySearchHorizon(const vector<vector<int>> &matrix, int col, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int low = 0, high = matrix.size() - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);

        if (matrix[mid][col] == target)
            return true;
        else if (matrix[mid][col] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

/**二叉搜索树
 * 对于每个元素，其左分支元素更小、右分支元素更大, 因此可以通过从 “根节点” 开始搜索，
 * 遇到比 target 大的元素就向左，反之向右，即可找到目标值 target 。
 */

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j < matrix[0].size())
    {
        if (matrix[i][j] > target)
            i--;
        else if (matrix[i][j] < target)
            j++;
        else
            return true;
    }
    return false;
}

/**多维度二分查找
 * Todo
 * 对于每个元素，其左分支元素更小、右分支元素更大, 除了使用二叉书顺序搜索外
 * 因为这里的数据使用数组存储的, 且此数组的行和列两个维度均满足顺序排序条件,
 * 也就是在每个维度上都可以用二分查找方法去寻找值
 *
 * 因此这里需要去判断此整数在行列两个维度与其他值的特点
 * 只要能够在不同维度上将数据分段, 就可以利用二分查找
 * 这里预先假设, 查找方向为从左向右和从上往下
 * 通过实例数据可以看出, 需要在行维度上需要去寻找最后一个小于等于此整数的值
 *    在列维度上去寻找第一个大于等于此整数的值
 */

/// @brief 利用二分查找的思想, 寻找二维数组中指定行最后一个*小于等于*目标值的元素
int GetHorizonFloorPosition2D(vector<vector<int>> &matrix, int row, int low, int high, int key)
{
    int size = high - low + 1;

    if (low <= high)
    {
        int mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] <= key) /* 中间值小于等于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
            else /* 中间值小于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
        }
        if (high >= 0 && matrix[row][mid] <= key)
            return high; /* 正确返回时, low 一定是指向第一个*小于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
}
/// @brief 利用二分查找的思想, 寻找二位数组中指定列第一个*大于等于*目标值的元素
int GetVericalCeilPosition2D(vector<vector<int>> &matrix, int col, int low, int high, int key)
{
    int size = high - low + 1;

    if (low <= high)
    {
        int mid;
        while (low <= high) /* 一步步缩紧区间 */
        {
            mid = low + (high - low) / 2;
            if (matrix[mid][col] >= key) /* 中间值大于等于 key */
            {
                high = mid - 1; /* 选取左侧区域*/
            }
            else /* 中间值小于 key */
            {
                low = mid + 1; /* 选取右侧区域*/
            }
        }
        if (low <= size && matrix[low][col] >= key)
            return low; /* 正确返回时, low 一定是指向第一个*大于等于*目标值的元素 */
    }
    /* 当找不到值时, 即  high<low 时, 返回 -1 */
    return -1;
}
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    int row = 0, col = 0, row_size = matrix.size(), col_size = matrix[0].size();
    while (row <= row_size, col <= col_size)
    {
        auto row = GetVericalCeilPosition2D(matrix, col, 0, col_size - 1, target);  /* 对当前列数据使用二分查找, 寻找第一个大于等于目标值的元素的行索引 */
        auto col = GetHorizonFloorPosition2D(matrix, row, 0, row_size - 1, target); /* 对当前行数据使用二分查找, 寻找最后一个小于等于目标值的元素的列索引 */
    }

    return false;
}

/**暴力遍历
 *
 */

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    for (const auto &row : matrix) /* 遍历所有行数组的指针 */
    {
        for (int element : row) /* 遍历当前行的所有数据 */
        {
            if (element == target) /* 判断值 */
            {
                return true;
            }
        }
    }
    return false;
}

/**Z 字形查找
 *
 */

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0)
    {
        if (matrix[x][y] == target)
        {
            return true;
        }
        if (matrix[x][y] > target)
        {
            --y;
        }
        else
        {
            ++x;
        }
    }
    return false;
}
