/**
 * 题目：机器人的运动范围
 * 地上有一个 m 行 n 列的方格, 从坐标 [0,0] 到坐标 [m-1,n-1].
 * 一个机器人从坐标 [0, 0] 的格子开始移动, 它每次可以向左、右、上、下移动一格（不能移动到方格外）,
 * 也不能进入行坐标和列坐标的数位之和大于 k 的格子.
 * 例如, 当 k 为 18 时, 机器人能够进入方格 [35, 37], 因为 3+5+3+7=18. 但它不能进入方格 [35, 38], 因为 3+5+3+8=19.
 * 请问该机器人能够到达多少个格子？
 * 链接:
 * - https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 * 考察:
 * -
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
 * 回溯(递归)
 * 机器人通过不断的移动, ** 最终到达终点 **(没说).
 * 这其中肯定会有很多路线, 每条路线所经历的格子都是能到达的.
 * 所有的路线可能会重复遇到一些格子.
 * 注意: 此题并不需要经历所有路线, 因为根据题意, 不能到达终点的无效方格(障碍物), 一定在右或下方
 * 因此, 只需要按照这俩方向移动, 即可找出所有障碍方格, 则有效方格也就都找到了
 *
 * 重复子任务: 机器人移动一格位置.
 * 子任务参数:
 * - 因为机器人要想移动到下一个, 必须要知道当前的位置(i, j);
 * - 同时, 机器人还要考虑坐标数位和是否大于值(k)
 * - 需要一个数组存储格子经历的状态
 * - 需要数组大小判断边界
 * 子任务终止条件: 坐标出界, 无法执行移动子任务; 行列坐标数位和太大; 到达终点;
 * 子任务的子任务: 机器人可以去上下左右四个方向移动一格
 * 子任务的子任务返回值: 子任务的执行状态
 * - 任务失败返回 true
 * - 任务成功返回 false
 *
 * 返回值利用:
 * - 如果子任务的子任务只要有一个执行成功, 说明后续的子任务都执行成功, 记录当前格子为有效格子, 有效格子数数量 + 1
 * - - 如果当前格子被重复经历过, 则有效格子数数量不变.
 * - 如果子任务的子任务执行失败, 则当前格子不是有效格子
 *
 */

// int movingCount(int m, int n, int k)
// {
//     vector<vector<bool>> visited(m, vector<bool>(n, 0));
//     int count = 0;
//     robotMove(0, 0, visited, count, m, n, k);
//     return count;
// }

// bool robotMove(int i, int j, vector<vector<bool>> &visited, int &count, int m, int n, int k)
// {
//     /* 子任务参数终止条件 */
//     if (i == m && j == n)
//         return true;
//     if (i >= m || j >= n)
//         return false;
//     if (sums(i) + sums(j) > k)
//         return false;

//     /* 执行后续子任务 */
//     bool flag = robotMove(i + 1, j, visited, count, m, n, k) || robotMove(i, j + 1, visited, count, m, n, k);
//     if (!flag)
//         return false;
//     if (!visited[i][j])
//     {
//         visited[i][j] = true;
//         count++;
//     }
//     return true;
// }

// int sums(int x)
// {
//     int s = 0;
//     while (x != 0)
//     {
//         s += x % 10;
//         x = x / 10;
//     }
//     return s;
// }

/**
 * 重复子任务: 机器人移动一格位置.
 * 子任务参数:
 * - 当前的位置(i, j)
 * - 坐标数位和值(k)
 * - 格子经历状态
 * - 数组大小
 *
 * 子任务终止条件:
 * - 行列索引越界
 * - 数位和超出目标值
 * - 当前元素已访问过
 *
 * 子任务的子任务: 机器人可以去上右两个方向移动一格
 * 子任务的子任务返回值: 任务路径中锁经历的后续的有效格子数量(无重复访问且不是障碍的格子)
 * 返回值利用:
 * - 将后续的有效格子数量与当前的有效格子进行再次统计
 */

int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k)
{
    if (i >= m || j >= n || k < si + sj || visited[i][j])
        return 0; /* 如果后面都是重复格子或者障碍格子, 就返回 0 */

    /* 如果遇到了有效格子, 就更新它的状态, 并与后续的所有有效格子一起返回个数目 */
    visited[i][j] = true;
    return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
           dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
}

int movingCount(int m, int n, int k)
{
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    return dfs(0, 0, 0, 0, visited, m, n, k);
}
