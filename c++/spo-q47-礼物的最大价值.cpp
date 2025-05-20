/**
 * @file spo-q47-礼物的最大价值.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：礼物的最大价值
 * - 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * - 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 * - 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 * 链接:
 * - https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
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
 * 有始有终的路径问题, 寻找最大值, 一般是可以递推的, 用动态规划方法
 * 假设到达终点 nums[m][n] 时, 最多可以拿到的最大礼物价值为 f(m, n)
 * f(m, n) 应该等于之前单元格的最大礼物价值加上最后单元格的礼物价值
 * 但是因为达到终点所需要经历的单元格会有两个, 也就是终点的上方或左方
 * 因此需要选择其中最大的一个, 用公式表达: f(m, n) = max(f(m-1, n), f(m, n-1))+ nums[n][n-1]
 *
 * 同时, 如果仔细观察示例矩阵, 会发现还有一些特殊的单元格, 比如第一行的, 第一列的和起始的单元格
 * 到达第一行的单元格的路径只能是左侧单元格, 到达第一列的单元格的路径只能是上侧单元格, 其实单元格只能出不能达
 * 因此公式在计算过程中, 需要考虑当前单元格的位置, 加几个条件
 *
 */

/**
 * 转移方程:
 * - m = 0 时, f(m, n) = f(m, n-1)+ nums[m][n]
 * - n = 0 时, f(m, n) = f(m-1)+ nums[m][n]
 * - 其他: f(m, n) = max(f(m-1, n), f(m, n-1))+ nums[m][n]
 * 初始状态: f[0][0] =nums[0][0]
 * 返回值: f[m, n]
 */

int maxValue(vector<vector<int>> &grid)
{
    if (grid.size() == 0)
        return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                f[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                f[i][j] = f[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                f[i][j] = f[i - 1][j] + grid[i][j];
            }
            else
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
    }
    return f[m - 1][n - 1];
}

int maxValue(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n));
    /* 初始化初始值 */
    f[0][0] = grid[0][0];
    //初始化dp的最上面一行，从左到右累加
    for (int i = 1; i < n; i++)
    {
        f[0][i] = f[0][i - 1] + grid[0][i];
    }
    //初始化dp的最左边一列，从上到下累加
    for (int i = 1; i < m; i++)
    {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }

    //下面是递推公式的计算
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }

    return f[m - 1][n - 1];
}
