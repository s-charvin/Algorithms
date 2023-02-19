/**
 * @file spo-q32-从上到下打印二叉树I.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：从上到下打印二叉树
 * - 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 * 链接:
 * - https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 * 考察:
 * - 搜索与回溯算法
 * - 广度优先搜索（BFS）
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */

/**
 * 题解思路:
 *
 *
 *
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**队列先入先出
 * 从头节点开始遍历二叉树, 将所有节点从左到右的放入队列中
 * 因为队列先入先出的特性, 可以在遍历过程中每次向队列添加节点的同时,
 * 处理队列头部的节点, 将它的值按照顺序放入向量列表中
 */

vector<int> levelOrder(TreeNode *root)
{
    vector<int> result; /* 定义变量保存最终结果 */

    if (root == NULL) /* 空值判定 */
        return result;

    queue<TreeNode *> q; /* 定义队列用于存储节点的数据 */
    q.push(root);

    while (!q.empty()) /* 遍历结束的条件是, 队列中存储的所有节点数据都被放到向量列表中 */
    {
        TreeNode *node = q.front();  /* 获取队列中最先进去的节点 */
        q.pop();                     /* 将最先进去的节点从队列中弹出 */
        result.push_back(node->val); /* 保存获取的节点的值到向量列表中 */

        /* 当节点的子节点不为空时, 将子节点以先左后右的顺序放入队列中等待读取*/
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        /**
         * 如果左右子节点都为空, 则继续处理队列中剩余的节点
         */
    }
    return result;
}
