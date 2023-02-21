/**
 * @file spo-q12-矩阵中的路径.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：矩阵中的路径
 * - 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 * - 如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * - 单词必须按照字母顺序，通过相邻的单元格内的字母构成，
 * - 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 * - 同一个单元格内的字母不允许被重复使用。
 * 链接:
 * - https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * 考察:
 * - 搜索
 * - 回溯
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
 * 因为给定的二维字符网格是完全无规律的,
 * 因此想要查找字符串单词, 需要遍历网格内所有的位置, 这里只有暴力遍历的方法
 *
 * 在遍历字符网格时, 需要去判断当前位置字符及其后续的邻格字符
 * 是否可以一起构成给定的字符串单词, 即:
 * - 如果当前字符与单词的首字符不同, 就继续遍历下一个位置
 * - 如果当前字符与单词的首字符相同, 就继续判断当前字符的上下左右邻格字符是否与单词的第二个字符相同
 * - - 如果不存在邻格字符与单词的第二个字符相同, 就继续遍历下一个位置
 * - - 如果存在邻格字符与单词的第二个字符相同, 就继续判断邻格字符的邻格字符
 * - - 以上类推, 直到单词的所有字符都被判别完, 并且都判别成功, 就说明此单词存在于网格中
 * - - 判别过程中, 已经判别成功的字符不能再使用, 因此需要找到一种办法去记录判别历史
 *
 * 根据上述的检测过程, 可以明显的看出通过回溯(递归)的方式检查更简单, 因此构建递归过程
 * 假设要检测的网格位置为 (i, j), 要检测的单词为 word
 * 想要使用递归(回溯)法, 则需要将检测问题分割成独立的重复子任务
 *
 * 重复子任务: 可以看出上述中, 判别当前位置字符与单词字符是否相同的子任务是重复的, 并且每次任务结束, 都会进入当前字符的邻格继续执行此子任务
 * 子任务参数: 执行此子任务, 需要知道当前字符的位置(i, j), 正在判别的字符是哪个(word[k])
 * 子任务嵌套的终止条件: 单词判别完毕, 矩阵索引越界, 当前字符与目标字符不同, 当前字符被访问过
 * 子任务返回值: 子任务成功状态
 * 下一子任务返回值的利用: 只要有一个成功就行
 *
 * 想要了解当前字符是否被访问过, 有多种方式
 * - 新建矩阵存储访问状态
 * - 每次访问后都将在原位置做标记(修改字符为特殊字符)
 * - - 这里需要考虑是否允许修改, 如果不能可以使用后, 再还原字符
 */
bool exist(vector<vector<char>> &board, string word)
{

    for (int i = 0; i < board.size(); i++) /* 从左到右, 从上到下遍历字符矩阵的所有位置 */
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            /* 检查当前位置的字符及其后续所有邻格字符是否可以组成为单词 */
            if (check(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}

bool check(vector<vector<char>> &board, int i, int j, string &word, int k)
{
    /* 子任务结束(参数判断) */
    if (k > word.size() - 1)
        return true;
    if (i > board.size() - 1 || i < 0 || j > board[0].size() - 1 || j < 0)
        return false;
    /* 子任务流程 */
    bool flag = board[i][j] == word[k];

    /* 子任务结束(结果判断) */
    if (!flag)
        return false;
    /* 下面判断被包含在了上述判断中 */
    // if (board[i][j] == '\0')
    //     return false;

    /* 子任务的子任务 */
    board[i][j] = '\0';
    bool res = check(board, i + 1, j, word, k + 1) || check(board, i, j + 1, word, k + 1) || check(board, i - 1, j, word, k + 1) || check(board, i, j - 1, word, k + 1);

    /* 子任务的子任务的结果处理 */
    board[i][j] = word[k];
    return res;
}
